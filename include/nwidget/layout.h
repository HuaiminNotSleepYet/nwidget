#ifndef LAYOUT_H
#define LAYOUT_H

#include <QLayout>

#include "object.h"

namespace nw {

template<typename S, typename T> class LayoutBuilder;
template<typename S, typename T> class WidgetBuilder;

// QLayoutItem is usually used during the layout process, so we did not add a LayoutItemBuilder.
class LayoutItem : public BuilderItem<QLayout>
{
public:
    LayoutItem(QWidget* widget)   : BuilderItem([widget](QLayout* l){ l->addWidget(widget); }) {}
    LayoutItem(QLayoutItem* item) : BuilderItem([item]  (QLayout* l){ l->addItem(item)    ; }) {}
    template<typename S, typename T> LayoutItem(const WidgetBuilder<S, T>& widget) : LayoutItem((T*)widget) {}
    template<typename S, typename T> LayoutItem(const LayoutBuilder<S, T>& item  ) : LayoutItem((T*)item  ) {}

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

N_DECL_BUILDER(LayoutBuilder, QLayout, Layout);


template<typename T>
class LayoutIdT : public ObjectIdT<T>
{
public:
    using ObjectIdT<T>::ObjectIdT;

    N_ID_PROPERTY(int                    , spacing        , N_GETTER(spacing        ),  N_SETTER(setSpacing        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QMargins               , contentsMargins, N_GETTER(contentsMargins),  N_SETTER(setContentsMargins), N_NO_NOTIFY)
    N_ID_PROPERTY(QLayout::SizeConstraint, sizeConstraint , N_GETTER(sizeConstraint ),  N_SETTER(setSizeConstraint ), N_NO_NOTIFY)
};

using LayoutId = LayoutIdT<QLayout>;

}

#endif // LAYOUT_H
