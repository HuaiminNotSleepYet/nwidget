#ifndef SPLITTER_H
#define SPLITTER_H

#include <QSplitter>

#include "frame.h"

namespace nw {

template<typename S, typename T>
class SplitterBuilder : public FrameBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(FrameBuilder, S, T)

public:
    SplitterBuilder()                                      : FrameBuilder<S, T>(new T) {}
    explicit SplitterBuilder(T* target)                    : FrameBuilder<S, T>(target) {}
    SplitterBuilder(std::initializer_list<Widget> widgets) : FrameBuilder<S, T>(new T) { applyWidgets(widgets); }

    S& orientation(Qt::Orientation o) { t->setOrientation(o); return self(); }

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
class SplitterRefT : public FrameRefT<T>
{
public:
    using FrameRefT<T>::FrameRefT;

    N_PROPERTY(Qt::Orientation, orientation        , N_GETTER(orientation        ), N_SETTER(setOrientation        ), N_NO_NOTIFY)
    N_PROPERTY(bool           , opaqueResize       , N_GETTER(opaqueResize       ), N_SETTER(setOpaqueResize       ), N_NO_NOTIFY)
    N_PROPERTY(int            , handleWidth        , N_GETTER(handleWidth        ), N_SETTER(setHandleWidth        ), N_NO_NOTIFY)
    N_PROPERTY(bool           , childrenCollapsible, N_GETTER(childrenCollapsible), N_SETTER(setChildrenCollapsible), N_NO_NOTIFY)
};

using SplitterRef = SplitterRefT<QSplitter>;

}


#endif // SPLITTER_H
