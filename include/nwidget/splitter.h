#ifndef SPLITTER_H
#define SPLITTER_H

#include <QSplitter>

#include "frame.h"

namespace nw {

class SplitterItem : public BuilderItem<QSplitter>
{
public:
    SplitterItem(QWidget* widget) : BuilderItem([widget](QSplitter* s){ s->addWidget(widget); }) {}

    template<typename T>
    SplitterItem(const WidgetIdT<T>& widget) : SplitterItem((T*)widget) {}

    template<typename S, typename T>
    SplitterItem(const WidgetBuilder<S, T>& widget) : SplitterItem((T*)widget) {}

    SplitterItem(ItemGenerator<SplitterItem> generator) : BuilderItem(generator) {}
};

template<typename S, typename T>
class SplitterBuilder : public FrameBuilder<S, T>
{
    N_BUILDER

public:
    SplitterBuilder()                                                       : FrameBuilder<S, T>(new T) {}
    SplitterBuilder(std::initializer_list<SplitterItem> widgets)            : FrameBuilder<S, T>(new T) { addItems(widgets); }
    explicit
    SplitterBuilder(T* target)                                              : FrameBuilder<S, T>(target) {}
    SplitterBuilder(T* target, std::initializer_list<SplitterItem> widgets) : FrameBuilder<S, T>(target) { addItems(widgets); }

    S& items(std::initializer_list<SplitterItem> widgets) { addItems(widgets); return self(); }

    N_BUILDER_PROPERTY(Qt::Orientation, orientation        , setOrientation        )
    N_BUILDER_PROPERTY(bool           , opaqueResize       , setOpaqueResize       )
    N_BUILDER_PROPERTY(int            , handleWidth        , setHandleWidth        )
    N_BUILDER_PROPERTY(bool           , childrenCollapsible, setChildrenCollapsible)
};

N_DECL_BUILDER(SplitterBuilder, QSplitter, Splitter);



template <typename T>
class SplitterIdT : public FrameIdT<T>
{
public:
    using FrameIdT<T>::FrameIdT;

    N_ID_PROPERTY(Qt::Orientation, orientation        , N_GETTER(orientation        ), N_SETTER(setOrientation        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool           , opaqueResize       , N_GETTER(opaqueResize       ), N_SETTER(setOpaqueResize       ), N_NO_NOTIFY)
    N_ID_PROPERTY(int            , handleWidth        , N_GETTER(handleWidth        ), N_SETTER(setHandleWidth        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool           , childrenCollapsible, N_GETTER(childrenCollapsible), N_SETTER(setChildrenCollapsible), N_NO_NOTIFY)
};

using SplitterId = SplitterIdT<QSplitter>;

}


#endif // SPLITTER_H
