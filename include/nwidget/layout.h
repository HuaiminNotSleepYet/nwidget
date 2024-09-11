#ifndef NWIDGET_LAYOUT_H
#define NWIDGET_LAYOUT_H

#include <QLayout>

#include "object.h"

namespace nwidget {

template<typename T> class WidgetIdT;
template<typename S, typename T> class LayoutBuilder;
template<typename S, typename T> class WidgetBuilder;

template<typename T>
class LayoutIdT : public ObjectIdT<T>
{
public:
    using ObjectIdT<T>::ObjectIdT;

    N_ID_PROPERTY(int                    , spacing        , N_GETTER(spacing        ),  N_SETTER(setSpacing        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QMargins               , contentsMargins, N_GETTER(contentsMargins),  N_SETTER(setContentsMargins), N_NO_NOTIFY)
    N_ID_PROPERTY(QLayout::SizeConstraint, sizeConstraint , N_GETTER(sizeConstraint ),  N_SETTER(setSizeConstraint ), N_NO_NOTIFY)
};

N_DECLARE_ID(Layout, LayoutIdT, QLayout)



// QLayoutItem is usually used during the layout process, so we did not add a LayoutItemBuilder.
class LayoutItem : public BuilderItem<QLayout>
{
public:
    LayoutItem(QWidget* widget)   : BuilderItem([widget](QLayout* l){ l->addWidget(widget); }) {}
    LayoutItem(QLayoutItem* item) : BuilderItem([item]  (QLayout* l){ l->addItem(item)    ; }) {}
    template<typename T> LayoutItem(const WidgetIdT<T>& widget) : LayoutItem((T*)widget) {}
    template<typename T> LayoutItem(const LayoutIdT<T>& layout) : LayoutItem((T*)layout) {}
    template<typename S, typename T> LayoutItem(const WidgetBuilder<S, T>& widget) : LayoutItem((T*)widget) {}
    template<typename S, typename T> LayoutItem(const LayoutBuilder<S, T>& layout) : LayoutItem((T*)layout) {}

    LayoutItem(ItemGenerator<LayoutItem> generator) : BuilderItem(generator) {}
};

template<typename S, typename T>
class LayoutBuilder : public ObjectBuilder<S, T>
{
    N_BUILDER

public:
    LayoutBuilder()                                                   : ObjectBuilder<S, T>(new T) {}
    LayoutBuilder(std::initializer_list<LayoutItem> items)            : ObjectBuilder<S, T>(new T) { addItems(items); }
    explicit
    LayoutBuilder(T* target)                                          : ObjectBuilder<S, T>(target) {}
    LayoutBuilder(T* target, std::initializer_list<LayoutItem> items) : ObjectBuilder<S, T>(target) { addItems(items); }

    S& items(std::initializer_list<LayoutItem> items) { addItems(items); return self(); }

    N_BUILDER_PROPERTY(int                    , spacing        , setSpacing        )
    N_BUILDER_PROPERTY(QMargins               , contentsMargins, setContentsMargins)
    N_BUILDER_PROPERTY(QLayout::SizeConstraint, sizeConstraint , setSizeConstraint )

    S& alignment(Qt::Alignment a)                  { t->setAlignment(a)                     ; return self(); }
    S& contentsMargins(int l, int t, int r, int b) { this->t->setContentsMargins(l, t, r, b); return self(); }
};

N_DECLARE_BUILDER(Layout, LayoutBuilder, QLayout)

}

#endif // NWIDGET_LAYOUT_H
