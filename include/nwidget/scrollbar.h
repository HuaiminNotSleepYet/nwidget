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
    ScrollBarBuilder()                            : AbstractSliderBuilder<S, T>(new T) {}
    explicit ScrollBarBuilder(T* target)          : AbstractSliderBuilder<S, T>(target) {}
    ScrollBarBuilder(Qt::Orientation orientation) : AbstractSliderBuilder<S, T>(new T(orientation)) {}
};

N_BUILDER_IMPL(ScrollBarBuilder, QScrollBar, ScrollBar);

}

#endif // SCROLLBAR_H
