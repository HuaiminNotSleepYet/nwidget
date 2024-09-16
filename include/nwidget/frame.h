#ifndef NWIDGET_FRAME_H
#define NWIDGET_FRAME_H

#include <QFrame>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class FrameBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    using WidgetBuilder<S, T>::WidgetBuilder;

    N_BUILDER_PROPERTY(QFrame::Shape , frameShape  , setFrameShape  )
    N_BUILDER_PROPERTY(QFrame::Shadow, frameShadow , setFrameShadow )
    N_BUILDER_PROPERTY(int           , lineWidth   , setLineWidth   )
    N_BUILDER_PROPERTY(int           , midLineWidth, setMidLineWidth)
    N_BUILDER_PROPERTY(QRect         , frameRect   , setFrameRect   )

    S& frameStyle(int style) { t->setFrameStyle(style); return self(); }
};

N_DECLARE_BUILDER(Frame, FrameBuilder, QFrame)



template<typename T>
class FrameIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(QFrame::Shape , frameShape  , N_READ frameShape   N_WRITE setFrameShape  )
    N_ID_PROPERTY(QFrame::Shadow, frameShadow , N_READ frameShadow  N_WRITE setFrameShadow )
    N_ID_PROPERTY(int           , lineWidth   , N_READ lineWidth    N_WRITE setLineWidth   )
    N_ID_PROPERTY(int           , midLineWidth, N_READ midLineWidth N_WRITE setMidLineWidth)
    N_ID_PROPERTY(int           , frameWidth  , N_READ frameWidth                          )
    N_ID_PROPERTY(QRect         , frameRect   , N_READ frameRect    N_WRITE setFrameRect   )
};

N_DECLARE_ID(Frame, FrameIdT, QFrame)

}

#endif // NWIDGET_FRAME_H
