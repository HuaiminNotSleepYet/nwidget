#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QCheckBox>

#include "abstractbutton.h"

namespace nw {

template<typename S, typename T>
class CheckBoxBuilder : public AbstractButtonBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractButtonBuilder, S, T)

public:
    CheckBoxBuilder()                               : AbstractButtonBuilder<S, T>(new T) {}
    explicit CheckBoxBuilder(const QString& text)   : AbstractButtonBuilder<S, T>(new T(text)) {}
    explicit CheckBoxBuilder(T* target)             : AbstractButtonBuilder<S, T>(target) {}
    CheckBoxBuilder(T* target, const QString& text) : AbstractButtonBuilder<S, T>(target) { t->setText(text); }

    N_BUILDER_PROPERTY(bool          , tristate  , setTristate  )
    N_BUILDER_PROPERTY(Qt::CheckState, checkState, setCheckState)

    N_SIGNAL(onStateChanged, QCheckBox::stateChanged)
};

N_BUILDER_IMPL(CheckBoxBuilder, QCheckBox, CheckBox);



template<typename T>
class CheckBoxIdT : public AbstractButtonIdT<T>
{
public:
    using AbstractButtonIdT<T>::AbstractButtonIdT;

    N_PROPERTY(bool          , tristate  , N_GETTER(isTristate), N_SETTER(setTristate  ), N_NO_NOTIFY)
    N_PROPERTY(Qt::CheckState, checkState, N_GETTER(checkState), N_SETTER(setCheckState), N_NO_NOTIFY)
};

using CheckBoxId = CheckBoxIdT<QCheckBox>;

}

#endif // CHECKBOX_H
