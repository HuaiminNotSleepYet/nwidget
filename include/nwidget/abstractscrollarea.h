#ifndef ABSTRACTSCROLLAREABUILDER_H
#define ABSTRACTSCROLLAREABUILDER_H

#include <QAbstractScrollArea>

#include "frame.h"

namespace nw {

template<typename S, typename T>
class AbstractScrollAreaBuilder : public FrameBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(FrameBuilder, S, T)

public:
    using FrameBuilder<S, T>::FrameBuilder;
};

N_BUILDER_IMPL(AbstractScrollAreaBuilder, QAbstractScrollArea, AbstractScrollArea);

}

#endif // ABSTRACTSCROLLAREABUILDER_H
