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

}

#endif // FRAME_H
