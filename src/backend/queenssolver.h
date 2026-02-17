#ifndef QUEENSSOLVER_H
#define QUEENSSOLVER_H

#include <QObject>
#include <QVector>
#include <QSet>
#include <QMap>
#include <QColor>
#include <atomic>
#include "queensmodel.h"

class QueensSolver : public QObject {
    Q_OBJECT

public:
    explicit QueensSolver(QObject *parent = nullptr);

    void setColors(const QVector<QVector<QChar>> &colors);
    void setColorMap(const QMap<QChar, QColor> &colorMap);
    void setUpdateInterval(int n);
    void setDelayMs(int ms);
    void setUseBacktracking(bool bt);

    int iteration() const;

public slots:
    void solve();

signals:
    void boardUpdated(QVector<Cell> cells, int size);
    void iterationUpdated(int iteration);
    void finished(bool solved, int totalIterations);

private:
    bool backtrack(QVector<int> &queenCol, int row, int size, QSet<QChar> &usedColors);
    bool isSafe(const QVector<int> &queenCol, int row, int col, int size, const QSet<QChar> &usedColors);

    bool bruteForce(QVector<int> &queenCol, int row, int size);
    bool isValidBoard(const QVector<int> &queenCol, int size);

    void emitCurrentState(const QVector<int> &queenCol, int size);
    void tickIteration(const QVector<int> &queenCol, int size);

    QVector<QVector<QChar>> m_colors;
    QMap<QChar, QColor> m_colorMap;

    int m_iteration = 0;
    std::atomic<int> m_updateEveryN{1};
    std::atomic<int> m_delayMs{200};
    bool m_useBacktracking = true;
};

#endif // QUEENSSOLVER_H
