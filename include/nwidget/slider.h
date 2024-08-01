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
    SliderBuilder()                            : AbstractSliderBuilder<S, T>(new T) {}
    explicit SliderBuilder(T* target)          : AbstractSliderBuilder<S, T>(target) {}
    SliderBuilder(Qt::Orientation orientation) : AbstractSliderBuilder<S, T>(new T(orientation)) {}
};

N_BUILDER_IMPL(SliderBuilder, QSlider, Slider);

}

#endif // SLIDER_H
