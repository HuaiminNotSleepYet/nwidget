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

private:
    void applyItems(std::initializer_list<GridLayoutItem> items)
    {
        const auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(t);
    }
};

N_BUILDER_IMPL(GridLayoutBuilder, QGridLayout, GridLayout);



template<typename T>
class GridLayoutRefT : public LayoutRefT<T>
{
public:
    using LayoutRefT<T>::LayoutRefT;

    N_PROPERTY(int, horizontalSpacing, N_GETTER(horizontalSpacing), N_SETTER(setHorizontalSpacing), N_NO_NOTIFY)
    N_PROPERTY(int, verticalSpacing  , N_GETTER(verticalSpacing  ), N_SETTER(setVerticalSpacing  ), N_NO_NOTIFY)
};

using GridLayoutRef = GridLayoutRefT<QGridLayout>;

}

#endif // GRIDLAYOUT_H
