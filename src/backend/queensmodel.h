#ifndef QUEENSMODEL_H
#define QUEENSMODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <QVector>

struct Cell {
    QChar color;
    bool hasQueen;
    QColor cellColor;
};

class QueensModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int boardSize READ boardSize NOTIFY boardSizeChanged)

public:
    enum Roles {
        ColorRole = Qt::UserRole + 1,
        HasQueenRole,
        CellColorRole
    };

    explicit QueensModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    int boardSize() const;
    void updateBoard(const QVector<Cell> &cells, int size);

signals:
    void boardSizeChanged();

private:
    QVector<Cell> m_cells;
    int m_size = 0;
};

#endif // QUEENSMODEL_H
