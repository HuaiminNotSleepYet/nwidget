#ifndef SPLITTER_H
#define SPLITTER_H

#include <QSplitter>

#include "frame.h"

namespace nw {

template<typename S, typename T>
class SplitterBuilder : public FrameBuilder<S, T>
{
    N_BUILDER

public:
    SplitterBuilder()                                                 : FrameBuilder<S, T>(new T) {}
    SplitterBuilder(std::initializer_list<Widget> widgets)            : FrameBuilder<S, T>(new T) { applyWidgets(widgets); }
    explicit SplitterBuilder(T* target)                               : FrameBuilder<S, T>(target) {}
    SplitterBuilder(T* target, std::initializer_list<Widget> widgets) : FrameBuilder<S, T>(target) { applyWidgets(widgets); }

    N_BUILDER_PROPERTY(Qt::Orientation, orientation        , setOrientation        )
    N_BUILDER_PROPERTY(bool           , opaqueResize       , setOpaqueResize       )
    N_BUILDER_PROPERTY(int            , handleWidth        , setHandleWidth        )
    N_BUILDER_PROPERTY(bool           , childrenCollapsible, setChildrenCollapsible)

private:
    void applyWidgets(std::initializer_list<Widget> widgets)
    {
        auto end = widgets.end();
        for (auto i = widgets.begin(); i != end; ++i)
            t->addWidget(*i);
    }
};

N_BUILDER_IMPL(SplitterBuilder, QSplitter, Splitter);



template <typename T>
class SplitterIdT : public FrameIdT<T>
{
public:
    using FrameIdT<T>::FrameIdT;

    N_PROPERTY(Qt::Orientation, orientation        , N_GETTER(orientation        ), N_SETTER(setOrientation        ), N_NO_NOTIFY)
    N_PROPERTY(bool           , opaqueResize       , N_GETTER(opaqueResize       ), N_SETTER(setOpaqueResize       ), N_NO_NOTIFY)
    N_PROPERTY(int            , handleWidth        , N_GETTER(handleWidth        ), N_SETTER(setHandleWidth        ), N_NO_NOTIFY)
    N_PROPERTY(bool           , childrenCollapsible, N_GETTER(childrenCollapsible), N_SETTER(setChildrenCollapsible), N_NO_NOTIFY)
};

using SplitterId = SplitterIdT<QSplitter>;

}


#endif // SPLITTER_H
