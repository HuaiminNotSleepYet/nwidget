#ifndef LAYOUT_H
#define LAYOUT_H

#include <QLayout>

#include "builder.h"

#define N_LAYOUT_BUILDER_IMPL(BUILDER, TARGET, NAME)            \
class NAME : public BUILDER<NAME, TARGET>                       \
{                                                               \
public:                                                         \
    using BUILDER::BUILDER;                                     \
                                                                \
    template<typename S, typename T>                            \
    NAME(const BUILDER<S, T>& builder)                          \
        : BUILDER(builder.LayoutItemBuilder::operator T*()) {}  \
}

namespace nw {

template<typename S, typename T> class LayoutItemBuilder;
template<typename S, typename T> class LayoutBuilder;
template<typename S, typename T> class WidgetBuilder;

struct WidgetOrLayoutItem
{
    std::function<void(QLayout*)> addTo;

    WidgetOrLayoutItem() {}
    WidgetOrLayoutItem(QWidget* widget)   { addTo = [widget](QLayout* l){ l->addWidget(widget); }; }
    WidgetOrLayoutItem(QLayoutItem* item) { addTo = [item  ](QLayout* l){ l->addItem(item)    ; }; }
    template<typename S, typename T> WidgetOrLayoutItem(const WidgetBuilder<S, T>& widget) : WidgetOrLayoutItem(widget.operator QWidget*()) {}
    template<typename S, typename T> WidgetOrLayoutItem(const LayoutItemBuilder<S, T>& item) : WidgetOrLayoutItem(item.operator QLayoutItem*()) {}

    WidgetOrLayoutItem(ItemGenerator<WidgetOrLayoutItem> generator)
    {
        addTo = [generator](QLayout* l){
            auto item = generator();
            while (item) {
                item->addTo(l);
                item = generator();
            }
        };
    }
};



template<typename S, typename T>
class LayoutItemBuilder : public Builder<S, T>
{
    N_USING_BUILDER_MEMBER(Builder, S, T)

public:
    LayoutItemBuilder()          : Builder<S, T>(new T) {}
    LayoutItemBuilder(T* target) : Builder<S, T>(target) {}

    S& alignment(Qt::Alignment a)    { t->setAlignment(a); return self(); }
    S& geometry(const QRect &rect)   { t->setGeometry(rect); return self(); }
};

N_BUILDER_IMPL(LayoutItemBuilder, QLayoutItem, LayoutItem);



template<typename S, typename T>
class LayoutBuilder : public LayoutItemBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(LayoutItemBuilder, S, T)

public:
    LayoutBuilder()                                                           : LayoutItemBuilder<S, T>(new T) {}
    LayoutBuilder(std::initializer_list<WidgetOrLayoutItem> items)            : LayoutItemBuilder<S, T>(new T) { applyItems(items); }
    explicit LayoutBuilder(T* target)                                         : LayoutItemBuilder<S, T>(target) {}
    LayoutBuilder(T* target, std::initializer_list<WidgetOrLayoutItem> items) : LayoutItemBuilder<S, T>(target) { applyItems(items); }

    S& spacing(int v) { t->setSpacing(v); return self(); }

    S& contentsMargins(int l, int t, int r, int b)   { this->t->setContentsMargins(l, t, r, b); return self(); }
    S& contentsMargins(const QMargins& margins)      { t->setContentsMargins(margins);          return self(); }

private:
    void applyItems(std::initializer_list<WidgetOrLayoutItem> items)
    {
        auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(t);
    }
};

N_BUILDER_IMPL(LayoutBuilder, QLayout, Layout);

}

#endif // LAYOUT_H
