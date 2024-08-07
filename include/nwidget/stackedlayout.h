#ifndef STACKEDLAYOUT_H
#define STACKEDLAYOUT_H

#include <QStackedLayout>

#include "layout.h"

namespace nw {

template<typename S, typename T>
class StackedLayoutBuilder : public LayoutBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(LayoutBuilder, S, T)

public:
    using LayoutBuilder<S, T>::LayoutBuilder;

    S& currentIndex(int index)           { t->setCurrentIndex(index); return self(); }
    S& currentWidget(QWidget* widget)    { t->setCurrentWidget(widget); return self(); }
};

N_BUILDER_IMPL(StackedLayoutBuilder, QStackedLayout, StackedLayout);

}

#endif // STACKEDLAYOUT_H
