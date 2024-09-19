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

    N_BUILDER_SETTER1(currentWidget, setCurrentWidget)
};

N_DECLARE_BUILDER_N(StackedLayout, StackedLayoutBuilder, QStackedLayout)



template<typename T>
class StackedLayoutIdT : public LayoutIdT<T>
{
    using StackingMode = QStackedLayout::StackingMode;

public:
    using LayoutIdT<T>::LayoutIdT;

    N_ID_PROPERTY(int         , currentIndex, N_READ currentIndex N_WRITE setCurrentIndex N_NOTIFY currentChanged)
    N_ID_PROPERTY(StackingMode, stackingMode, N_READ stackingMode N_WRITE setStackingMode)
    N_ID_PROPERTY(int         , count       , N_READ count)
};

N_DECLARE_ID_N(StackedLayout, StackedLayoutIdT, QStackedLayout)

}

#endif // NWIDGET_STACKEDLAYOUT_H
