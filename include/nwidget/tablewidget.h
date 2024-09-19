#ifndef NWIDGET_TABLEWIDGET_H
#define NWIDGET_TABLEWIDGET_H

#include <QTableWidget>

#include "tableview.h"

namespace nwidget {

template<typename T>
class TableWidgetIdT : public TableViewIdT<T>
{
public:
    using TableViewIdT<T>::TableViewIdT;

    N_ID_PROPERTY(int, rowCount   , N_READ rowCount    N_WRITE setRowCount   )
    N_ID_PROPERTY(int, columnCount, N_READ columnCount N_WRITE setColumnCount)
};

N_DECLARE_ID_N(TableWidget, TableWidgetIdT, QTableWidget)



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

    N_BUILDER_SETTER3(item                  , setItem                  )
    N_BUILDER_SETTER2(verticalHeaderItem    , setVerticalHeaderItem    )
    N_BUILDER_SETTER2(horizontalHeaderItem  , setHorizontalHeaderItem  )
    N_BUILDER_SETTER1(verticalHeaderLabels  , setVerticalHeaderLabels  )
    N_BUILDER_SETTER1(horizontalHeaderLabels, setHorizontalHeaderLabels)
    N_BUILDER_SETTER1(currentItem           , setCurrentItem           )
    N_BUILDER_SETTER2(currentItem           , setCurrentItem           )
    N_BUILDER_SETTER2(currentCell           , setCurrentCell           )
    N_BUILDER_SETTER3(currentCell           , setCurrentCell           )
    N_BUILDER_SETTER1(sortingEnabled        , setSortingEnabled        )
    N_BUILDER_SETTER3(cellWidget            , setCellWidget            )
    N_BUILDER_SETTER2(rangeSelected         , setRangeSelected         )
    N_BUILDER_SETTER1(itemPrototype         , setItemPrototype         )

    S &model(QAbstractItemModel*) = delete;

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

N_DECLARE_BUILDER_N(TableWidget, TableWidgetBuilder, QTableWidget);

}

#endif // NWIDGET_TABLEWIDGET_H
