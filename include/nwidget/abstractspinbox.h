#ifndef ABSTRACTSPINBOX_H
#define ABSTRACTSPINBOX_H

#include <QAbstractSpinBox>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class AbstractSpinBoxBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    AbstractSpinBoxBuilder()                   : WidgetBuilder<S, T>(new T) {}
    explicit AbstractSpinBoxBuilder(T* target) : WidgetBuilder<S, T>(target) {}

    N_SIGNAL(onEditingFinished, QAbstractSpinBox::editingFinished)
};

N_BUILDER_IMPL(AbstractSpinBoxBuilder, QAbstractSpinBox, AbstractSpinBox);

}

#endif // ABSTRACTSPINBOX_H
