#ifndef NWIDGET_STACKEDLAYOUT_H
#define NWIDGET_STACKEDLAYOUT_H

#include <QStackedLayout>

#include "layout.h"

namespace nwidget {

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

N_DECLARE_BUILDER(StackedLayout, StackedLayoutBuilder, QStackedLayout)



template<typename T>
class StackedLayoutIdT : public LayoutIdT<T>
{
public:
    using LayoutIdT<T>::LayoutIdT;

    N_ID_PROPERTY(int                         , currentIndex, N_GETTER(currentIndex), N_SETTER(setCurrentIndex), N_NOTIFY(currentChanged))
    N_ID_PROPERTY(QStackedLayout::StackingMode, stackingMode, N_GETTER(stackingMode), N_SETTER(setStackingMode), N_NO_NOTIFY)
    N_ID_PROPERTY(int                         , count       , N_GETTER(count       ), N_NO_SETTER              , N_NO_NOTIFY)
};

N_DECLARE_ID(StackedLayout, StackedLayoutIdT, QStackedLayout)

}

#endif // NWIDGET_STACKEDLAYOUT_H
