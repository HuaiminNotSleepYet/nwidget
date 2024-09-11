#ifndef NWIDGET_TABLEWIDGET_H
#define NWIDGET_TABLEWIDGET_H

#include <QTableWidget>

#include "tableview.h"

namespace nwidget {

template<typename T>
class TableWidgetIdT : public TableViewIdT<T>
{
public:
    N_ID_PROPERTY(int, rowCount   , N_GETTER(rowCount   ), N_SETTER(setRowCount   ), N_NO_NOTIFY)
    N_ID_PROPERTY(int, columnCount, N_GETTER(columnCount), N_SETTER(setColumnCount), N_NO_NOTIFY)
};

using TableWidgetId = TableWidgetIdT<QTableWidget>;



template<typename S, typename T>
class TableWidgetBuilder : public TableViewBuilder<S, T>
{
    N_BUILDER

public:
    TableWidgetBuilder()                      : TableViewBuilder<S, T>(new T) {}
    TableWidgetBuilder(int rows, int columns) : TableViewBuilder<S, T>(new T(rows, columns)) {}
    explicit
    TableWidgetBuilder(T* target)             : TableViewBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(int, rowCount   , setRowCount   )
    N_BUILDER_PROPERTY(int, columnCount, setColumnCount)

    S& item(int row, int column, QTableWidgetItem* item)                            { t->setItem(row, column, item)           ; return self(); }
    S& verticalHeaderItem(int row, QTableWidgetItem* item)                          { t->setVerticalHeaderItem(row, item)     ; return self(); }
    S& horizontalHeaderItem(int column, QTableWidgetItem* item)                     { t->setHorizontalHeaderItem(column, item); return self(); }
    S& verticalHeaderLabels(const QStringList& labels)                              { t->setVerticalHeaderLabels(labels)      ; return self(); }
    S& horizontalHeaderLabels(const QStringList& labels)                            { t->setHorizontalHeaderLabels(labels)    ; return self(); }
    S& currentItem(QTableWidgetItem* item)                                          { t->setCurrentItem(item)                 ; return self(); }
    S& currentItem(QTableWidgetItem* item, QItemSelectionModel::SelectionFlags cmd) { t->setCurrentItem(item, cmd)            ; return self(); }
    S& currentCell(int row, int column)                                             { t->setCurrentCell(row, column)          ; return self(); }
    S& currentCell(int row, int column, QItemSelectionModel::SelectionFlags cmd)    { t->setCurrentCell(row, column, cmd)     ; return self(); }
    S& sortingEnabled(bool enable)                                                  { t->setSortingEnabled(enable)            ; return self(); }
    S& cellWidget(int row, int column, QWidget* widget)                             { t->setCellWidget(row, column, widget)   ; return self(); }
    S& rangeSelected(const QTableWidgetSelectionRange& range, bool select)          { t->setRangeSelected(range, select)      ; return self(); }
    S& itemPrototype(const QTableWidgetItem* item)                                  { t->setItemPrototype(item)               ; return self(); }

    N_BUILDER_SIGNAL(onItemPressed         , itemPressed         )
    N_BUILDER_SIGNAL(onItemClicked         , itemClicked         )
    N_BUILDER_SIGNAL(onItemDoubleClicked   , itemDoubleClicked   )
    N_BUILDER_SIGNAL(onItemActivated       , itemActivated       )
    N_BUILDER_SIGNAL(onItemEntered         , itemEntered         )
    N_BUILDER_SIGNAL(onItemChanged         , itemChanged         )
    N_BUILDER_SIGNAL(onCurrentItemChanged  , currentItemChanged  )
    N_BUILDER_SIGNAL(onItemSelectionChanged, itemSelectionChanged)
    N_BUILDER_SIGNAL(onCellPressed         , cellPressed         )
    N_BUILDER_SIGNAL(onCellClicked         , cellClicked         )
    N_BUILDER_SIGNAL(onCellDoubleClicked   , cellDoubleClicked   )
    N_BUILDER_SIGNAL(onCellActivated       , cellActivated       )
    N_BUILDER_SIGNAL(onCellEntered         , cellEntered         )
    N_BUILDER_SIGNAL(onCellChanged         , cellChanged         )
};

N_DECL_BUILDER(TableWidgetBuilder, QTableWidget, TableWidget);

}

#endif // NWIDGET_TABLEWIDGET_H
