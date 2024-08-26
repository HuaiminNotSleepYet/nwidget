#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QTableWidget>

#include "tableview.h"

namespace nw {

template<typename S, typename T>
class TableWidgetBuilder : public TableViewBuilder<S, T>
{
    N_BUILDER

public:
    TableWidgetBuilder()                      : TableViewBuilder<S, T>(new T) {}
    TableWidgetBuilder(int rows, int columns) : TableViewBuilder<S, T>(new T(rows, columns)) {}
    explicit TableWidgetBuilder(T* target)              : TableViewBuilder<S, T>(target) {}
    TableWidgetBuilder(T* target, int row, int columns) : TableViewBuilder<S, T>(target) { t->setRowCount(row); t->setColumnCount(columns); }
};

N_BUILDER_IMPL(TableWidgetBuilder, QTableWidget, TableWidget);

}

#endif // TABLEWIDGET_H
