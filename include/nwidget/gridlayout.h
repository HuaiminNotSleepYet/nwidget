#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QGridLayout>

#include "layout.h"

namespace nw {

struct GridLayoutItem
{
    std::function<void(QGridLayout*)> addTo;

    GridLayoutItem(int row, int col, QWidget* widget)                                                  : GridLayoutItem(row, col, 1      , 1      , Qt::Alignment(), widget) {}
    GridLayoutItem(int row, int col, QLayout* layout)                                                  : GridLayoutItem(row, col, 1      , 1      , Qt::Alignment(), layout) {}
    GridLayoutItem(int row, int col, Qt::Alignment align, QWidget* widget)                             : GridLayoutItem(row, col, 1      , 1      , align          , widget) {}
    GridLayoutItem(int row, int col, Qt::Alignment align, QLayout* layout)                             : GridLayoutItem(row, col, 1      , 1      , align          , layout) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, QWidget* widget)                        : GridLayoutItem(row, col, rowSpan, colSpan, Qt::Alignment(), widget) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, QLayout* layout)                        : GridLayoutItem(row, col, rowSpan, colSpan, Qt::Alignment(), layout) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, QWidget* widget)   { addTo = [row, col, rowSpan, colSpan, align, widget](QGridLayout* l){ l->addWidget(widget, row, col, rowSpan, colSpan, align); }; }
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, QLayout* layout)   { addTo = [row, col, rowSpan, colSpan, align, layout](QGridLayout* l){ l->addLayout(layout, row, col, rowSpan, colSpan, align); }; }

    GridLayoutItem(int row, int col, QLayoutItem* item)                                                : GridLayoutItem(row, col, 1      , 1      , Qt::Alignment(), item) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, QLayoutItem* item)                      : GridLayoutItem(row, col, rowSpan, colSpan, Qt::Alignment(), item) {}
    GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, QLayoutItem* item) { addTo = [row, col, rowSpan, colSpan, align, item](QGridLayout* l){ l->addItem(item, row, col, rowSpan, colSpan, align); }; }

    template<typename S, typename T> GridLayoutItem(int row, int col, const LayoutBuilder<S, T>& layout)                                                  : GridLayoutItem(row, col, 1      , 1      , Qt::Alignment(), layout.operator T*()) {}
    template<typename S, typename T> GridLayoutItem(int row, int col, int rowSpan, int colSpan, const LayoutBuilder<S, T>& layout)                        : GridLayoutItem(row, col, rowSpan, colSpan, Qt::Alignment(), layout.operator T*()) {}
    template<typename S, typename T> GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, const LayoutBuilder<S, T>& layout)   : GridLayoutItem(row, col, rowSpan, colSpan, Qt::Alignment(), layout.operator T*()) {}

    template<typename S, typename T> GridLayoutItem(int row, int col, const LayoutItemBuilder<S, T>& item)                                                : GridLayoutItem(row, col, 1      , 1      , Qt::Alignment(), item.operator T*()) {}
    template<typename S, typename T> GridLayoutItem(int row, int col, int rowSpan, int colSpan, const LayoutItemBuilder<S, T>& item)                      : GridLayoutItem(row, col, rowSpan, colSpan, Qt::Alignment(), item.operator T*()) {}
    template<typename S, typename T> GridLayoutItem(int row, int col, int rowSpan, int colSpan, Qt::Alignment align, const LayoutItemBuilder<S, T>& item) : GridLayoutItem(row, col, rowSpan, colSpan, Qt::Alignment(), item.operator T*()) {}

    GridLayoutItem(ItemGenerator<GridLayoutItem> generator)
    {
        addTo = [generator](QGridLayout* l){
            auto item = generator();
            while (item) {
                item->addTo(l);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class GridLayoutBuilder : public LayoutBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(LayoutBuilder, S, T)

public:
    GridLayoutBuilder()                                                       : LayoutBuilder<S, T>(new T) {}
    GridLayoutBuilder(std::initializer_list<GridLayoutItem> items)            : LayoutBuilder<S, T>(new T) { applyItems(items); }
    explicit GridLayoutBuilder(T* target)                                     : LayoutBuilder<S, T>(target) {}
    GridLayoutBuilder(T* target, std::initializer_list<GridLayoutItem> items) : LayoutBuilder<S, T>(target) { applyItems(items); }

    S& horizontalSpacing(int spacing)                    { t->setHorizontalSpacing(spacing)      ; return self(); }
    S& verticalSpacing(int spacing)                      { t->setVerticalSpacing(spacing)        ; return self(); }
    S& rowStretch(int row, int stretch)                  { t->setRowStretch(row, stretch)        ; return self(); }
    S& columnStretch(int col, int stretch)               { t->setColumnStretch(col, stretch)     ; return self(); }
    S& rowMinimumHeight(int row, int minSize)            { t->setRowMinimumHeight(row, minSize)  ; return self(); }
    S& columnMinimumWidth(int col, int minSize)          { t->setColumnMinimumWidth(col, minSize); return self(); }
    S& originCorner(Qt::Corner corner)                   { t->setOriginCorner(corner)            ; return self(); }
    S& defaultPositioning(int n, Qt::Orientation orient) { t->setDefaultPositioning(n, orient)   ; return self(); }

private:
    void applyItems(std::initializer_list<GridLayoutItem> items)
    {
        const auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(t);
    }
};

N_BUILDER_IMPL(GridLayoutBuilder, QGridLayout, GridLayout);

}

#endif // GRIDLAYOUT_H
