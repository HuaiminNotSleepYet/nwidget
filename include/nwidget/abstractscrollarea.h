#ifndef NWIDGET_ABSTRACTSCROLLAREABUILDER_H
#define NWIDGET_ABSTRACTSCROLLAREABUILDER_H

#include <QAbstractScrollArea>

#include "frame.h"

namespace nwidget {

template<typename S, typename T>
class AbstractScrollAreaBuilder : public FrameBuilder<S, T>
{
    N_BUILDER

public:
    using FrameBuilder<S, T>::FrameBuilder;

    N_BUILDER_PROPERTY(Qt::ScrollBarPolicy                  , verticalScrollBarPolicy  , setVerticalScrollBarPolicy  )
    N_BUILDER_PROPERTY(Qt::ScrollBarPolicy                  , horizontalScrollBarPolicy, setHorizontalScrollBarPolicy)
    N_BUILDER_PROPERTY(QAbstractScrollArea::SizeAdjustPolicy, sizeAdjustPolicy         , setSizeAdjustPolicy         )
};

N_DECLARE_BUILDER(AbstractScrollArea, AbstractScrollAreaBuilder, QAbstractScrollArea);



template<typename T>
class AbstractScrollAreaIdT : public FrameIdT<T>
{
public:
    using FrameIdT<T>::FrameIdT;

    N_ID_PROPERTY(Qt::ScrollBarPolicy, verticalScrollBarPolicy  , N_GETTER(verticalScrollBarPolicy  ), N_SETTER(setVerticalScrollBarPolicy  ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::ScrollBarPolicy, horizontalScrollBarPolicy, N_GETTER(horizontalScrollBarPolicy), N_SETTER(setHorizontalScrollBarPolicy), N_NO_NOTIFY)
    N_ID_PROPERTY(QAbstractScrollArea::SizeAdjustPolicy, sizeAdjustPolicy, N_GETTER(sizeAdjustPolicy), N_SETTER(setSizeAdjustPolicy         ), N_NO_NOTIFY)
};

N_DECLARE_ID(AbstractScrollArea, AbstractScrollAreaIdT, QAbstractScrollArea)

}

#endif // NWIDGET_ABSTRACTSCROLLAREABUILDER_H
