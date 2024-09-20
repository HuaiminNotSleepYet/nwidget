#ifndef NWIDGET_TABLEVIEW_H
#define NWIDGET_TABLEVIEW_H

#include <QTableView>

#include "abstractitemview.h"

namespace nwidget {

template<typename T>
class TableViewIdT : public AbstractItemViewIdT<T>
{
public:
    using AbstractItemViewIdT<T>::AbstractItemViewIdT;

    N_ID_PROPERTY(bool        , showGrid           , N_READ showGrid              N_WRITE setShowGrid           )
    N_ID_PROPERTY(Qt::PenStyle, gridStyle          , N_READ gridStyle             N_WRITE setGridStyle          )
    N_ID_PROPERTY(bool        , sortingEnabled     , N_READ isSortingEnabled      N_WRITE setSortingEnabled     )
    N_ID_PROPERTY(bool        , wordWrap           , N_READ wordWrap              N_WRITE setWordWrap           )
#if QT_CONFIG(abstractbutton)
    N_ID_PROPERTY(bool        , cornerButtonEnabled, N_READ isCornerButtonEnabled N_WRITE setCornerButtonEnabled)
#endif
};

N_DECLARE_ID(TableView, TableViewIdT, QTableView)



template<typename S, typename T>
class TableViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;

    N_BUILDER_PROPERTY(bool        , showGrid           , setShowGrid           )
    N_BUILDER_PROPERTY(Qt::PenStyle, gridStyle          , setGridStyle          )
    N_BUILDER_PROPERTY(bool        , sortingEnabled     , setSortingEnabled     )
    N_BUILDER_PROPERTY(bool        , wordWrap           , setWordWrap           )
#if QT_CONFIG(abstractbutton)
    N_BUILDER_PROPERTY(bool        , cornerButtonEnabled, setCornerButtonEnabled)
#endif

    N_BUILDER_SETTER1(horizontalHeader, setHorizontalHeader)
    N_BUILDER_SETTER1(verticalHeader  , setVerticalHeader  )
    N_BUILDER_SETTER2(rowHeight       , setRowHeight       )
    N_BUILDER_SETTER2(columnWidth     , setColumnWidth     )
    N_BUILDER_SETTER2(rowHidden       , setRowHidden       )
    N_BUILDER_SETTER2(columnHidden    , setColumnHidden    )
    N_BUILDER_SETTER4(span            , setSpan            )
};

N_DECLARE_BUILDER(TableView, TableViewBuilder, QTableView)

}

N_REGISTER_ID(nwidget::TableView, QTableView)
N_REGISTER_BUILDER(nwidget::TableView, QTableView)

#endif // NWIDGET_TABLEVIEW_H
