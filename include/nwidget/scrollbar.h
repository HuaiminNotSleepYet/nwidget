#ifndef NWIDGET_SCROLLBAR_H
#define NWIDGET_SCROLLBAR_H

#include <QScrollBar>

#include "abstractslider.h"

namespace nwidget {

N_DECLARE_ID_N(ScrollBar, AbstractSliderIdT, QScrollBar)

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

N_DECLARE_BUILDER_N(ScrollBar, ScrollBarBuilder, QScrollBar)

}

#endif // NWIDGET_SCROLLBAR_H
