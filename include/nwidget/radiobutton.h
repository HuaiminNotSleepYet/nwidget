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
    explicit RadioButtonBuilder(T* target)  : AbstractButtonBuilder<S, T>(target) {}
    RadioButtonBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T(text)) {}
};

N_BUILDER_IMPL(RadioButtonBuilder, QRadioButton, RadioButton);

}

#endif // RADIOBUTTON_H
