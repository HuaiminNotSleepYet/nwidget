#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>

#include "abstractslider.h"

namespace nw {

template<typename S, typename T>
class SliderBuilder : public AbstractSliderBuilder<S, T>
{
    N_BUILDER

public:
    SliderBuilder()                  : AbstractSliderBuilder<S, T>(new T) {}
    SliderBuilder(Qt::Orientation o) : AbstractSliderBuilder<S, T>(new T(o)) {}
    explicit SliderBuilder(T* target)           : AbstractSliderBuilder<S, T>(target) {}
    SliderBuilder(T* target, Qt::Orientation o) : AbstractSliderBuilder<S, T>(target) { t->setOrientation(o); }

    N_BUILDER_PROPERTY(QSlider::TickPosition, tickPosition, setTickPosition)
    N_BUILDER_PROPERTY(int                  , tickInterval, setTickInterval)
};

N_DECL_BUILDER(SliderBuilder, QSlider, Slider);



template<typename T>
class SliderIdT : public AbstractSliderIdT<T>
{
public:
    using AbstractSliderIdT<T>::AbstractSliderIdT;

    N_ID_PROPERTY(QSlider::TickPosition, tickPosition, N_GETTER(tickPosition), N_SETTER(setTickPosition), N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , tickInterval, N_GETTER(tickInterval), N_SETTER(setTickInterval), N_NO_NOTIFY)
};

using SliderId = SliderIdT<QSlider>;

}

#endif // SLIDER_H
