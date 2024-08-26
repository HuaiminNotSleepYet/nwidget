#ifndef STACKEDLAYOUT_H
#define STACKEDLAYOUT_H

#include <QStackedLayout>

#include "layout.h"

namespace nw {

template<typename S, typename T>
class StackedLayoutBuilder : public LayoutBuilder<S, T>
{
    N_BUILDER

public:
    using LayoutBuilder<S, T>::LayoutBuilder;

    N_BUILDER_PROPERTY(int                         , currentIndex, setCurrentIndex)
    N_BUILDER_PROPERTY(QStackedLayout::StackingMode, stackingMode, setStackingMode)

    S& currentWidget(QWidget* widget)    { t->setCurrentWidget(widget); return self(); }
};

N_BUILDER_IMPL(StackedLayoutBuilder, QStackedLayout, StackedLayout);



template<typename T>
class StackedLayoutIdT : public LayoutIdT<T>
{
public:
    using LayoutIdT<T>::LayoutIdT;

    N_PROPERTY(int                         , currentIndex, N_GETTER(currentIndex), N_SETTER(setCurrentIndex), N_NOTIFY(currentChanged))
    N_PROPERTY(QStackedLayout::StackingMode, stackingMode, N_GETTER(stackingMode), N_SETTER(setStackingMode), N_NO_NOTIFY)
    N_PROPERTY(int                         , count       , N_GETTER(count       ), N_NO_SETTER              , N_NO_NOTIFY)
};

using StackedLayoutId = StackedLayoutIdT<QStackedLayout>;

}

#endif // STACKEDLAYOUT_H
