#include "queensmodel.h"

QueensModel::QueensModel(QObject *parent) : QAbstractListModel(parent) {}

int QueensModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_cells.size();
}

QVariant QueensModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_cells.size())
        return {};
    const auto &cell = m_cells[index.row()];
    switch (role) {
    case ColorRole:     return cell.color;
    case HasQueenRole:  return cell.hasQueen;
    case CellColorRole: return cell.cellColor;
    }
    return {};
}

QHash<int, QByteArray> QueensModel::roleNames() const {
    return {
        {ColorRole,     "color"},
        {HasQueenRole,  "hasQueen"},
        {CellColorRole, "cellColor"}
    };
}

int QueensModel::boardSize() const {
    return m_size;
}

void QueensModel::updateBoard(const QVector<Cell> &cells, int size) {
    beginResetModel();
    m_cells = cells;
    m_size = size;
    endResetModel();
    emit boardSizeChanged();
}
