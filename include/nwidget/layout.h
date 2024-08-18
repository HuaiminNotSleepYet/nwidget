#ifndef LAYOUT_H
#define LAYOUT_H

#include <QLayout>

#include "builder.h"
#include "object.h"

namespace nw {

template<typename S, typename T> class LayoutItemBuilder;
template<typename S, typename T> class LayoutBuilder;
template<typename S, typename T> class WidgetBuilder;

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



class WidgetOrLayoutItem : public BuilderItem<QLayout>
{
public:
    WidgetOrLayoutItem(QWidget* widget)   : BuilderItem([widget](QLayout* l){ l->addWidget(widget); }) {}
    WidgetOrLayoutItem(QLayoutItem* item) : BuilderItem([item]  (QLayout* l){ l->addItem(item)    ; }) {}
    template<typename S, typename T> WidgetOrLayoutItem(const WidgetBuilder<S, T>& widget)   : WidgetOrLayoutItem((QWidget*)widget) {}
    template<typename S, typename T> WidgetOrLayoutItem(const LayoutItemBuilder<S, T>& item) : WidgetOrLayoutItem((QLayoutItem*)item) {}

    WidgetOrLayoutItem(ItemGenerator<WidgetOrLayoutItem> generator) : BuilderItem(generator) {}
};

template<typename S, typename T>
class LayoutBuilder : public LayoutItemBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(LayoutItemBuilder, S, T)

public:
    LayoutBuilder()                                                           : LayoutItemBuilder<S, T>(new T) {}
    LayoutBuilder(std::initializer_list<WidgetOrLayoutItem> items)            : LayoutItemBuilder<S, T>(new T) { addItems(items); }
    explicit LayoutBuilder(T* target)                                         : LayoutItemBuilder<S, T>(target) {}
    LayoutBuilder(T* target, std::initializer_list<WidgetOrLayoutItem> items) : LayoutItemBuilder<S, T>(target) { addItems(items); }

    S& spacing(int v) { t->setSpacing(v); return self(); }

    S& contentsMargins(int l, int t, int r, int b)   { this->t->setContentsMargins(l, t, r, b); return self(); }
    S& contentsMargins(const QMargins& margins)      { t->setContentsMargins(margins);          return self(); }
};

N_BUILDER_IMPL(LayoutBuilder, QLayout, Layout);


template<typename T>
class LayoutRefT : public ObjectRefT<T>
{
public:
    using ObjectRefT<T>::ObjectRefT;

    N_PROPERTY(int                    , spacing        , N_GETTER(spacing        ),  N_SETTER(setSpacing        ), N_NO_NOTIFY)
    N_PROPERTY(QMargins               , contentsMargins, N_GETTER(contentsMargins),  N_SETTER(setContentsMargins), N_NO_NOTIFY)
    N_PROPERTY(QLayout::SizeConstraint, sizeConstraint , N_GETTER(sizeConstraint ),  N_SETTER(setSizeConstraint ), N_NO_NOTIFY)
};

using LayoutRef = LayoutRefT<QLayout>;

}

#endif // LAYOUT_H
