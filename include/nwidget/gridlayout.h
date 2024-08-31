#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QGridLayout>

#include "layout.h"

namespace nw {

class GridLayoutItem : public BuilderItem<QGridLayout>
{
public:
    GridLayoutItem(int row, int col,                                                QWidget* widget  ) : GridLayoutItem(row, col, 1      , 1      , {}   , widget) {}
    GridLayoutItem(int row, int col,                                                QLayout* layout  ) : GridLayoutItem(row, col, 1      , 1      , {}   , layout) {}
    GridLayoutItem(int row, int col,                                                QLayoutItem* item) : GridLayoutItem(row, col, 1      , 1      , {}   , item  ) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan,                      QWidget* widget  ) : GridLayoutItem(row, col, rowSpan, colSpan, {}   , widget) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan,                      QLayout* layout  ) : GridLayoutItem(row, col, rowSpan, colSpan, {}   , layout) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan,                      QLayoutItem* item) : GridLayoutItem(row, col, rowSpan, colSpan, {}   , item  ) {}
    GridLayoutItem(int row, int col,                           Qt::Alignment align, QWidget* widget  ) : GridLayoutItem(row, col, 1      , 1      , align, widget) {}
    GridLayoutItem(int row, int col,                           Qt::Alignment align, QLayout* layout  ) : GridLayoutItem(row, col, 1      , 1      , align, layout) {}
    GridLayoutItem(int row, int col,                           Qt::Alignment align, QLayoutItem* item) : GridLayoutItem(row, col, 1      , 1      , align, item  ) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, QWidget* widget  ) : BuilderItem([row, col, rowSpan, colSpan, align, widget](QGridLayout* l){ l->addWidget(widget, row, col, rowSpan, colSpan, align); }) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, QLayout* layout  ) : BuilderItem([row, col, rowSpan, colSpan, align, layout](QGridLayout* l){ l->addLayout(layout, row, col, rowSpan, colSpan, align); }) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, QLayoutItem* item) : BuilderItem([row, col, rowSpan, colSpan, align, item  ](QGridLayout* l){ l->addItem(item, row, col, rowSpan, colSpan, align); }) {}

    GridLayoutItem(ItemGenerator<GridLayoutItem> generator) : BuilderItem(generator) {}
};

template<typename S, typename T>
class GridLayoutBuilder : public LayoutBuilder<S, T>
{
    N_BUILDER

public:
    GridLayoutBuilder()                                                       : LayoutBuilder<S, T>(new T) {}
    GridLayoutBuilder(std::initializer_list<GridLayoutItem> items)            : LayoutBuilder<S, T>(new T) { addItems(items); }
    explicit
    GridLayoutBuilder(T* target)                                              : LayoutBuilder<S, T>(target) {}
    GridLayoutBuilder(T* target, std::initializer_list<GridLayoutItem> items) : LayoutBuilder<S, T>(target) { addItems(items); }

    S& items(std::initializer_list<LayoutItem> items) = delete;
    S& items(std::initializer_list<GridLayoutItem> items) { addItems(items); return self(); }

    N_BUILDER_PROPERTY(int, horizontalSpacing, setHorizontalSpacing)
    N_BUILDER_PROPERTY(int, verticalSpacing  , setVerticalSpacing  )

    S& rowStretch(int row, int stretch)                  { t->setRowStretch(row, stretch)        ; return self(); }
    S& columnStretch(int col, int stretch)               { t->setColumnStretch(col, stretch)     ; return self(); }
    S& rowMinimumHeight(int row, int minSize)            { t->setRowMinimumHeight(row, minSize)  ; return self(); }
    S& columnMinimumWidth(int col, int minSize)          { t->setColumnMinimumWidth(col, minSize); return self(); }
    S& originCorner(Qt::Corner corner)                   { t->setOriginCorner(corner)            ; return self(); }
    S& defaultPositioning(int n, Qt::Orientation orient) { t->setDefaultPositioning(n, orient)   ; return self(); }
};

N_DECL_BUILDER(GridLayoutBuilder, QGridLayout, GridLayout);



template<typename T>
class GridLayoutIdT : public LayoutIdT<T>
{
public:
    using LayoutIdT<T>::LayoutIdT;

    N_ID_PROPERTY(int, horizontalSpacing, N_GETTER(horizontalSpacing), N_SETTER(setHorizontalSpacing), N_NO_NOTIFY)
    N_ID_PROPERTY(int, verticalSpacing  , N_GETTER(verticalSpacing  ), N_SETTER(setVerticalSpacing  ), N_NO_NOTIFY)
};

using GridLayoutId = GridLayoutIdT<QGridLayout>;

}

#endif // GRIDLAYOUT_H
