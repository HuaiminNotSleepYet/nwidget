#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QTableWidget>

#include "tableview.h"

namespace nw {

template<typename S, typename T>
class TableWidgetBuilder : public TableViewBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(TableViewBuilder, S, T)

public:
    TableWidgetBuilder()                      : TableViewBuilder<S, T>(new T) {}
    explicit TableWidgetBuilder(T* target)    : TableViewBuilder<S, T>(target) {}
    TableWidgetBuilder(int rows, int columns) : TableViewBuilder<S, T>(new T(rows, columns)) {}
};

N_BUILDER_IMPL(TableWidgetBuilder, QTableWidget, TableWidget);

}

#endif // TABLEWIDGET_H
