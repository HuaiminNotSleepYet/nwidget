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

    N_ID_PROPERTY(bool        , showGrid           , N_GETTER(showGrid             ), N_SETTER(setShowGrid           ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::PenStyle, gridStyle          , N_GETTER(gridStyle            ), N_SETTER(setGridStyle          ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool        , sortingEnabled     , N_GETTER(isSortingEnabled     ), N_SETTER(setSortingEnabled     ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool        , wordWrap           , N_GETTER(wordWrap             ), N_SETTER(setWordWrap           ), N_NO_NOTIFY)
#if QT_CONFIG(abstractbutton)
    N_ID_PROPERTY(bool        , cornerButtonEnabled, N_GETTER(isCornerButtonEnabled), N_SETTER(setCornerButtonEnabled), N_NO_NOTIFY)
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

    S& horizontalHeader(QHeaderView* header)                  { t->setHorizontalHeader(header)        ; return self(); }
    S& verticalHeader(QHeaderView* header)                    { t->setVerticalHeader(header)          ; return self(); }
    S& rowHeight(int row, int height)                         { t->setRowHeight(row, height)          ; return self(); }
    S& columnWidth(int column, int width)                     { t->setColumnWidth(column, width)      ; return self(); }
    S& rowHidden(int row, bool hide)                          { t->setRowHidden(row, hide)            ; return self(); }
    S& columnHidden(int column, bool hide)                    { t->setColumnHidden(column, hide)      ; return self(); }
    S& span(int row, int column, int rowSpan, int colSpan) { t->setSpan(row, column, rowSpan, colSpan); return self(); }
};

N_DECLARE_BUILDER(TableView, TableViewBuilder, QTableView);

}

#endif // NWIDGET_TABLEVIEW_H
