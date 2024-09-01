#ifndef NWIDGET_TABLEWIDGET_H
#define NWIDGET_TABLEWIDGET_H

#include <QTableWidget>

#include "tableview.h"

namespace nwidget {

template<typename S, typename T>
class TableWidgetBuilder : public TableViewBuilder<S, T>
{
    N_BUILDER

public:
    TableWidgetBuilder()                      : TableViewBuilder<S, T>(new T) {}
    TableWidgetBuilder(int rows, int columns) : TableViewBuilder<S, T>(new T(rows, columns)) {}
    explicit
    TableWidgetBuilder(T* target)             : TableViewBuilder<S, T>(target) {}
};

N_DECL_BUILDER(TableWidgetBuilder, QTableWidget, TableWidget);

}

#endif // NWIDGET_TABLEWIDGET_H
