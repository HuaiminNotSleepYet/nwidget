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

    S& frameStyle(int style)                { t->setFrameStyle(style)  ; return self(); }
    S& frameShape(QFrame::Shape shape)      { t->setFrameShape(shape)  ; return self(); }
    S& frameShadow(QFrame::Shadow shadow)   { t->setFrameShadow(shadow); return self(); }
    S& lineWidth(int width)                 { t->setLineWidth(width)   ; return self(); }
    S& midLineWidth(int width)              { t->setMidLineWidth(width); return self(); }
    S& frameRect(const QRect& rect)         { t->setFrameRect(rect)    ; return self(); }
};

N_BUILDER_IMPL(FrameBuilder, QFrame, Frame);



template<typename T>
class FrameIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_PROPERTY(QFrame::Shape , frameShape  , N_GETTER(frameShape  ), N_SETTER(setFrameShape  ), N_NO_NOTIFY)
    N_PROPERTY(QFrame::Shadow, frameShadow , N_GETTER(frameShadow ), N_SETTER(setFrameShadow ), N_NO_NOTIFY)
    N_PROPERTY(int           , lineWidth   , N_GETTER(lineWidth   ), N_SETTER(setLineWidth   ), N_NO_NOTIFY)
    N_PROPERTY(int           , midLineWidth, N_GETTER(midLineWidth), N_SETTER(setMidLineWidth), N_NO_NOTIFY)
    N_PROPERTY(int           , frameWidth  , N_GETTER(frameWidth  ), N_NO_SETTER              , N_NO_NOTIFY)
    N_PROPERTY(QRect         , frameRect   , N_GETTER(frameRect   ), N_SETTER(setFrameRect   ), N_NO_NOTIFY)
};

using FrameId = FrameIdT<QFrame>;

}

#endif // FRAME_H
