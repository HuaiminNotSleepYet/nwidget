#ifndef ABSTRACTSLIDER_H
#define ABSTRACTSLIDER_H

#include <QAbstractSlider>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class AbstractSliderBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    using WidgetBuilder<S, T>::WidgetBuilder;

    inline S& value(int v)                      { t->setValue(v);        return self(); }
    inline S& orientation(Qt::Orientation o)    { t->setOrientation(o);  return self(); }
    inline S& range(int min, int max)           { t->setRange(min, max); return self(); }

    N_SIGNAL(onValueChanged   , QAbstractSlider::valueChanged   )
    N_SIGNAL(onSliderPressed  , QAbstractSlider::sliderPressed  )
    N_SIGNAL(onSliderMoved    , QAbstractSlider::sliderMoved    )
    N_SIGNAL(onSliderReleased , QAbstractSlider::sliderReleased )
    N_SIGNAL(onRangeChanged   , QAbstractSlider::rangeChanged   )
    N_SIGNAL(onActionTriggered, QAbstractSlider::actionTriggered)
};

N_BUILDER_IMPL(AbstractSliderBuilder, QAbstractSlider, AbstractSlider);

}

#endif // ABSTRACTSLIDER_H
