#include "queenssolver.h"
#include <QThread>
#include <QtMath>

QueensSolver::QueensSolver(QObject *parent) : QObject(parent) {}

void QueensSolver::setColors(const QVector<QVector<QChar>> &colors) {
    m_colors = colors;
}

void QueensSolver::setColorMap(const QMap<QChar, QColor> &colorMap) {
    m_colorMap = colorMap;
}

void QueensSolver::setUpdateInterval(int n) {
    m_updateEveryN.store(qMax(1, n));
}

void QueensSolver::setDelayMs(int ms) {
    m_delayMs.store(qMax(0, ms));
}

int QueensSolver::iteration() const {
    return m_iteration;
}

void QueensSolver::setUseBacktracking(bool bt) {
    m_useBacktracking = bt;
}

void QueensSolver::solve() {
    int size = m_colors.size();
    QVector<int> queenCol(size, -1);
    m_iteration = 0;

    bool result;
    if (m_useBacktracking) {
        QSet<QChar> usedColors;
        result = backtrack(queenCol, 0, size, usedColors);
    } else {
        result = bruteForce(queenCol, 0, size);
    }

    emitCurrentState(queenCol, size);
    emit finished(result, m_iteration);
}

void QueensSolver::tickIteration(const QVector<int> &queenCol, int size) {
    m_iteration++;
    int interval = m_updateEveryN.load();
    if (interval > 0 && m_iteration % interval == 0) {
        emitCurrentState(queenCol, size);
        emit iterationUpdated(m_iteration);
        int delay = m_delayMs.load();
        if (delay > 0)
            QThread::msleep(delay);
    }
}

// BACKTRACKING 

bool QueensSolver::isSafe(const QVector<int> &queenCol, int row, int col, int size, const QSet<QChar> &usedColors) {
    // column check
    for (int r = 0; r < row; r++) {
        if (queenCol[r] == col) return false;
    }

    // 3x3 adjacency check
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int nr = row + dr, nc = col + dc;
            if (nr >= 0 && nr < size && nc >= 0 && nc < size) {
                for (int r = 0; r < row; r++) {
                    if (r == nr && queenCol[r] == nc) return false;
                }
            }
        }
    }

    // color check
    if (usedColors.contains(m_colors[row][col])) return false;

    return true;
}

bool QueensSolver::backtrack(QVector<int> &queenCol, int row, int size, QSet<QChar> &usedColors) {
    tickIteration(queenCol, size);

    if (row == size)
        return true;

    for (int col = 0; col < size; col++) {
        if (isSafe(queenCol, row, col, size, usedColors)) {
            queenCol[row] = col;
            usedColors.insert(m_colors[row][col]);

            if (backtrack(queenCol, row + 1, size, usedColors))
                return true;

            queenCol[row] = -1;
            usedColors.remove(m_colors[row][col]);
        }
    }
    return false;
}

// PURE BRUTE FORCE

bool QueensSolver::isValidBoard(const QVector<int> &queenCol, int size) {
    QSet<QChar> usedColors;

    for (int r = 0; r < size; r++) {
        int c = queenCol[r];
        if (c < 0) return false;

        // column check
        for (int r2 = 0; r2 < size; r2++) {
            if (r2 != r && queenCol[r2] == c) return false;
        }

        // 3x3 adjacency check
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) continue;
                int nr = r + di, nc = c + dj;
                if (nr >= 0 && nr < size && nc >= 0 && nc < size) {
                    if (queenCol[nr] == nc) return false;
                }
            }
        }

        // color uniqueness
        QChar color = m_colors[r][c];
        if (usedColors.contains(color)) return false;
        usedColors.insert(color);
    }
    return true;
}

bool QueensSolver::bruteForce(QVector<int> &queenCol, int row, int size) {
    tickIteration(queenCol, size);

    if (row == size) {
        return isValidBoard(queenCol, size);
    }

    for (int col = 0; col < size; col++) {
        queenCol[row] = col;
        if (bruteForce(queenCol, row + 1, size))
            return true;
        queenCol[row] = -1;
    }
    return false;
}

void QueensSolver::emitCurrentState(const QVector<int> &queenCol, int size) {
    QVector<Cell> cells;
    cells.reserve(size * size);

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            Cell cell;
            cell.color = m_colors[r][c];
            cell.hasQueen = (queenCol[r] == c);
            cell.cellColor = m_colorMap.value(cell.color, QColor(0x88, 0x88, 0x88));
            cells.append(cell);
        }
    }

    emit boardUpdated(cells, size);
}
