#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>

#include "abstractslider.h"

namespace nw {

template<typename S, typename T>
class SliderBuilder : public AbstractSliderBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractSliderBuilder, S, T)

public:
    SliderBuilder()                  : AbstractSliderBuilder<S, T>(new T) {}
    SliderBuilder(Qt::Orientation o) : AbstractSliderBuilder<S, T>(new T(o)) {}
    explicit SliderBuilder(T* target)           : AbstractSliderBuilder<S, T>(target) {}
    SliderBuilder(T* target, Qt::Orientation o) : AbstractSliderBuilder<S, T>(target) { t->setOrientation(o); }
};

N_BUILDER_IMPL(SliderBuilder, QSlider, Slider);



template<typename T>
class SliderRefT : public AbstractSliderRefT<T>
{
public:
    using AbstractSliderRefT<T>::AbstractSliderRefT;

    N_PROPERTY(QSlider::TickPosition, tickPosition, N_GETTER(tickPosition), N_SETTER(setTickPosition), N_NO_NOTIFY)
    N_PROPERTY(int                  , tickInterval, N_GETTER(tickInterval), N_SETTER(setTickInterval), N_NO_NOTIFY)
};

using SliderRef = SliderRefT<QSlider>;

}

#endif // SLIDER_H
