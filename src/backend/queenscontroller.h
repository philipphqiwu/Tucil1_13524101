#ifndef QUEENSCONTROLLER_H
#define QUEENSCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QMap>
#include <QColor>
#include <QElapsedTimer>
#include "queensmodel.h"
#include "queensparser.h"
#include "queenssolver.h"

class QueensController : public QObject {
    Q_OBJECT

    Q_PROPERTY(QueensModel* queensModel READ queensModel CONSTANT)
    Q_PROPERTY(int iteration READ iteration NOTIFY iterationChanged)
    Q_PROPERTY(bool solving READ solving NOTIFY solvingChanged)
    Q_PROPERTY(bool boardLoaded READ boardLoaded NOTIFY boardLoadedChanged)
    Q_PROPERTY(bool solved READ solved NOTIFY solveFinished)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged)
    Q_PROPERTY(int updateInterval READ updateInterval WRITE setUpdateInterval NOTIFY updateIntervalChanged)
    Q_PROPERTY(int delayMs READ delayMs WRITE setDelayMs NOTIFY delayMsChanged)
    Q_PROPERTY(bool useBacktracking READ useBacktracking WRITE setUseBacktracking NOTIFY useBacktrackingChanged)
    Q_PROPERTY(double elapsedMs READ elapsedMs NOTIFY elapsedMsChanged)

public:
    explicit QueensController(QObject *parent = nullptr);
    ~QueensController();

    QueensModel* queensModel();
    int iteration() const;
    bool solving() const;
    bool boardLoaded() const;
    bool solved() const;
    QString errorMessage() const;
    int updateInterval() const;
    int delayMs() const;
    double elapsedMs() const;
    bool useBacktracking() const;

    void setUpdateInterval(int n);
    void setDelayMs(int ms);
    void setUseBacktracking(bool bt);

    Q_INVOKABLE void loadFromTxtFile(const QString &filePath);
    Q_INVOKABLE void startSolving();
    Q_INVOKABLE void stopSolving();
    Q_INVOKABLE bool saveBoardAsTxt(const QString &filePath);

signals:
    void iterationChanged();
    void solvingChanged();
    void boardLoadedChanged();
    void errorMessageChanged();
    void updateIntervalChanged();
    void delayMsChanged();
    void useBacktrackingChanged();
    void elapsedMsChanged();
    void solveFinished(bool success);

private slots:
    void onBoardUpdated(const QVector<Cell> &cells, int size);
    void onIterationUpdated(int iteration);
    void onSolverFinished(bool solved, int totalIterations);

private:
    void applyParseResult(const ParseResult &result);
    void cleanupSolver();

    QueensModel m_queensModel;
    QVector<QVector<QChar>> m_colors;
    QMap<QChar, QColor> m_colorMap;

    QueensSolver *m_solver = nullptr;
    QThread *m_solverThread = nullptr;

    int m_iteration = 0;
    bool m_solving = false;
    bool m_boardLoaded = false;
    bool m_solved = false;
    QString m_errorMessage;
    int m_updateEveryN = 1;
    int m_delayMs = 200;
    double m_elapsedMs = 0;
    bool m_useBacktracking = true;
    QElapsedTimer m_timer;
};
#endif // QUEENSCONTROLLER_H
