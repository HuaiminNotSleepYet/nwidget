#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QScrollBar>

#include "abstractslider.h"

namespace nw {

template<typename S, typename T>
class ScrollBarBuilder : public AbstractSliderBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractSliderBuilder, S, T)

public:
    ScrollBarBuilder()                  : AbstractSliderBuilder<S, T>(new T) {}
    ScrollBarBuilder(Qt::Orientation o) : AbstractSliderBuilder<S, T>(new T(o)) {}
    explicit ScrollBarBuilder(T* target)           : AbstractSliderBuilder<S, T>(target) {}
    ScrollBarBuilder(T* target, Qt::Orientation o) : AbstractSliderBuilder<S, T>(target) { t->setOrientation(o); }
};

N_BUILDER_IMPL(ScrollBarBuilder, QScrollBar, ScrollBar);



using ScrollBarRef = AbstractSliderRefT<QAbstractSlider>;

}

#endif // SCROLLBAR_H
