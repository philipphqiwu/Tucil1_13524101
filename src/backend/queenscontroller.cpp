#include "queenscontroller.h"
#include <QUrl>
#include <QMetaObject>
#include <QFile>
#include <QTextStream>

QueensController::QueensController(QObject *parent) : QObject(parent) {}

QueensController::~QueensController() {
    cleanupSolver();
}

QueensModel* QueensController::queensModel() { return &m_queensModel; }
int QueensController::iteration() const { return m_iteration; }
bool QueensController::solving() const { return m_solving; }
bool QueensController::boardLoaded() const { return m_boardLoaded; }
bool QueensController::solved() const { return m_solved; }
QString QueensController::errorMessage() const { return m_errorMessage; }
int QueensController::updateInterval() const { return m_updateEveryN; }
int QueensController::delayMs() const { return m_delayMs; }
double QueensController::elapsedMs() const { return m_elapsedMs; }
bool QueensController::useBacktracking() const { return m_useBacktracking; }

void QueensController::setUpdateInterval(int n) {
    if (m_updateEveryN != n) {
        m_updateEveryN = n;
        if (m_solver) m_solver->setUpdateInterval(n);
        emit updateIntervalChanged();
    }
}

void QueensController::setDelayMs(int ms) {
    if (m_delayMs != ms) {
        m_delayMs = ms;
        if (m_solver) m_solver->setDelayMs(ms);
        emit delayMsChanged();
    }
}

void QueensController::setUseBacktracking(bool bt) {
    if (m_useBacktracking != bt) {
        m_useBacktracking = bt;
        emit useBacktrackingChanged();
    }
}

void QueensController::loadFromTxtFile(const QString &filePath) {
    QString localPath = QUrl(filePath).toLocalFile();
    auto result = QueensParser::fromTxtFile(localPath);
    applyParseResult(result);
}

void QueensController::applyParseResult(const ParseResult &result) {
    if (!result.success) {
        m_errorMessage = result.error;
        m_boardLoaded = false;
        emit errorMessageChanged();
        emit boardLoadedChanged();
        return;
    }

    m_colors = result.colors;
    m_colorMap = result.colorMap;

    int size = result.size;
    QVector<Cell> cells;
    cells.reserve(size * size);
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            Cell cell;
            cell.color = m_colors[r][c];
            cell.hasQueen = false;
            cell.cellColor = m_colorMap.value(cell.color, QColor(0x88, 0x88, 0x88));
            cells.append(cell);
        }
    }
    m_queensModel.updateBoard(cells, size);

    m_boardLoaded = true;
    m_solved = false;
    m_errorMessage.clear();
    emit boardLoadedChanged();
    emit errorMessageChanged();
}

void QueensController::startSolving() {
    if (m_solving || !m_boardLoaded) return;

    cleanupSolver();

    m_solving = true;
    m_solved = false;
    m_iteration = 0;
    m_elapsedMs = 0;
    emit solvingChanged();
    emit iterationChanged();

    m_solver = new QueensSolver();
    m_solver->setColors(m_colors);
    m_solver->setColorMap(m_colorMap);
    m_solver->setUpdateInterval(m_updateEveryN);
    m_solver->setDelayMs(m_delayMs);
    m_solver->setUseBacktracking(m_useBacktracking);

    m_solverThread = new QThread();
    m_solver->moveToThread(m_solverThread);

    connect(m_solver, &QueensSolver::boardUpdated,
            this, &QueensController::onBoardUpdated);
    connect(m_solver, &QueensSolver::iterationUpdated,
            this, &QueensController::onIterationUpdated);
    connect(m_solver, &QueensSolver::finished,
            this, &QueensController::onSolverFinished);

    connect(m_solverThread, &QThread::started, m_solver, &QueensSolver::solve);
    connect(m_solverThread, &QThread::finished, m_solverThread, &QThread::deleteLater);

    m_timer.start();
    m_solverThread->start();
}

void QueensController::stopSolving() {
    cleanupSolver();
    m_solving = false;
    emit solvingChanged();
}

bool QueensController::saveBoardAsTxt(const QString &filePath) {
    QString localPath = QUrl(filePath).toLocalFile();
    if (localPath.isEmpty()) localPath = filePath;

    QFile file(localPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    int size = m_queensModel.boardSize();

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            int idx = r * size + c;
            QVariant v = m_queensModel.data(m_queensModel.index(idx), QueensModel::HasQueenRole);
            if (v.toBool()) {
                out << "#";
            } else {
                out << m_colors[r][c] ;
            }
        }
        out << "\n";
    }

    file.close();
    return true;
}

void QueensController::cleanupSolver() {
    if (m_solverThread) {
        m_solverThread->quit();
        m_solverThread->wait();
        m_solverThread = nullptr;
    }
    if (m_solver) {
        delete m_solver;
        m_solver = nullptr;
    }
}


void QueensController::onBoardUpdated(const QVector<Cell> &cells, int size) {
    m_queensModel.updateBoard(cells, size);
}

void QueensController::onIterationUpdated(int iteration) {
    m_iteration = iteration;
    emit iterationChanged();
}

void QueensController::onSolverFinished(bool solved, int totalIterations) {
    m_elapsedMs = m_timer.elapsed();
    m_iteration = totalIterations;
    m_solving = false;
    m_solved = solved;

    emit iterationChanged();
    emit solvingChanged();
    emit elapsedMsChanged();
    emit solveFinished(solved);

    QMetaObject::invokeMethod(this, [this]() {
        cleanupSolver();
    }, Qt::QueuedConnection);
}
