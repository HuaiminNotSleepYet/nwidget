#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class FrameBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    using WidgetBuilder<S, T>::WidgetBuilder;
};

N_BUILDER_IMPL(FrameBuilder, QFrame, Frame);



template<typename T>
class FrameRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

    N_PROPERTY(QFrame::Shape , frameShape  , N_GETTER(frameShape  ), N_SETTER(setFrameShape  ), N_NO_NOTIFY)
    N_PROPERTY(QFrame::Shadow, frameShadow , N_GETTER(frameShadow ), N_SETTER(setFrameShadow ), N_NO_NOTIFY)
    N_PROPERTY(int           , lineWidth   , N_GETTER(lineWidth   ), N_SETTER(setLineWidth   ), N_NO_NOTIFY)
    N_PROPERTY(int           , midLineWidth, N_GETTER(midLineWidth), N_SETTER(setMidLineWidth), N_NO_NOTIFY)
    N_PROPERTY(int           , frameWidth  , N_GETTER(frameWidth  ), N_NO_SETTER              , N_NO_NOTIFY)
    N_PROPERTY(QRect         , frameRect   , N_GETTER(frameRect   ), N_SETTER(setFrameRect   ), N_NO_NOTIFY)
};

using FrameRef = FrameRefT<QFrame>;

}

#endif // FRAME_H
