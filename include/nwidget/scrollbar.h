#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QScrollBar>

#include "abstractslider.h"

namespace nw {

template<typename S, typename T>
class ScrollBarBuilder : public AbstractSliderBuilder<S, T>
{
    N_BUILDER

public:
    ScrollBarBuilder()                  : AbstractSliderBuilder<S, T>(new T) {}
    explicit
    ScrollBarBuilder(Qt::Orientation o) : AbstractSliderBuilder<S, T>(new T(o)) {}
    explicit
    ScrollBarBuilder(T* target)         : AbstractSliderBuilder<S, T>(target) {}
};

N_DECL_BUILDER(ScrollBarBuilder, QScrollBar, ScrollBar);



using ScrollBarId = AbstractSliderIdT<QAbstractSlider>;

}

#endif // SCROLLBAR_H
