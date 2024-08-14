#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QRadioButton>

#include "abstractbutton.h"

namespace nw {

template<typename S, typename T>
class RadioButtonBuilder : public AbstractButtonBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractButtonBuilder, S, T)

public:
    RadioButtonBuilder()                    : AbstractButtonBuilder<S, T>(new T) {}
    RadioButtonBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T(text)) {}
    explicit RadioButtonBuilder(T* target)             : AbstractButtonBuilder<S, T>(target) {}
    RadioButtonBuilder(T* target, const QString& text) : AbstractButtonBuilder<S, T>(target) { t->setText(text); }
};

N_BUILDER_IMPL(RadioButtonBuilder, QRadioButton, RadioButton);

}

#endif // RADIOBUTTON_H
