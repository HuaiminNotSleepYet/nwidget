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



template<typename T>
class AbstractScrollAreaRefT : public FrameRefT<T>
{
public:
    using FrameRefT<T>::FrameRefT;

    N_PROPERTY(Qt::ScrollBarPolicy, verticalScrollBarPolicy  , N_GETTER(verticalScrollBarPolicy  ), N_SETTER(setVerticalScrollBarPolicy  ), N_NO_NOTIFY)
    N_PROPERTY(Qt::ScrollBarPolicy, horizontalScrollBarPolicy, N_GETTER(horizontalScrollBarPolicy), N_SETTER(setHorizontalScrollBarPolicy), N_NO_NOTIFY)
    N_PROPERTY(QAbstractScrollArea::SizeAdjustPolicy, sizeAdjustPolicy, N_GETTER(sizeAdjustPolicy), N_SETTER(setSizeAdjustPolicy         ), N_NO_NOTIFY)
};

using AbstractScrollAreaRef = AbstractScrollAreaRefT<QAbstractScrollArea>;

}

#endif // ABSTRACTSCROLLAREABUILDER_H
