#ifndef NWIDGET_SLIDER_H
#define NWIDGET_SLIDER_H

#include <QSlider>

#include "abstractslider.h"

namespace nwidget {

template<typename S, typename T>
class SliderBuilder : public AbstractSliderBuilder<S, T>
{
    N_BUILDER

public:
    SliderBuilder()                  : AbstractSliderBuilder<S, T>(new T) {}
    explicit
    SliderBuilder(Qt::Orientation o) : AbstractSliderBuilder<S, T>(new T(o)) {}
    explicit
    SliderBuilder(T* target)         : AbstractSliderBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(QSlider::TickPosition, tickPosition, setTickPosition)
    N_BUILDER_PROPERTY(int                  , tickInterval, setTickInterval)
};

N_DECLARE_BUILDER_N(Slider, SliderBuilder, QSlider)



template<typename T>
class SliderIdT : public AbstractSliderIdT<T>
{
public:
    using AbstractSliderIdT<T>::AbstractSliderIdT;

    N_ID_PROPERTY(QSlider::TickPosition, tickPosition, N_READ tickPosition N_WRITE setTickPosition)
    N_ID_PROPERTY(int                  , tickInterval, N_READ tickInterval N_WRITE setTickInterval)
};

N_DECLARE_ID_N(Slider, SliderIdT, QSlider)

}

#endif // NWIDGET_SLIDER_H
