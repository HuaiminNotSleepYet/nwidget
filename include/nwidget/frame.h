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

}

#endif // FRAME_H
