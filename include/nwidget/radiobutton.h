#ifndef NWIDGET_RADIOBUTTON_H
#define NWIDGET_RADIOBUTTON_H

#include <QRadioButton>

#include "abstractbutton.h"

namespace nwidget {

template<typename S, typename T>
class RadioButtonBuilder : public AbstractButtonBuilder<S, T>
{
    N_BUILDER

public:
    RadioButtonBuilder()                    : AbstractButtonBuilder<S, T>(new T) {}
    explicit
    RadioButtonBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T(text)) {}
    explicit
    RadioButtonBuilder(T* target)           : AbstractButtonBuilder<S, T>(target) {}
};

N_DECL_BUILDER(RadioButtonBuilder, QRadioButton, RadioButton);



using RadioButtonId = AbstractButtonIdT<QRadioButton>;

}

#endif // NWIDGET_RADIOBUTTON_H
