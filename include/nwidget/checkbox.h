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

    S& checkState(Qt::CheckState state)  { t->setCheckState(state); return self(); }
    S& tristate(bool b = true)           { t->setTristate(b);       return self(); }

    N_SIGNAL(onStateChanged, QCheckBox::stateChanged)
};

N_BUILDER_IMPL(CheckBoxBuilder, QCheckBox, CheckBox);



template<typename T>
class CheckBoxRefT : public AbstractButtonRefT<T>
{
public:
    using AbstractButtonRefT<T>::AbstractButtonRefT;

    N_PROPERTY(bool          , tristate  , N_GETTER(isTristate), N_SETTER(setTristate  ), N_NO_NOTIFY)
    N_PROPERTY(Qt::CheckState, checkState, N_GETTER(checkState), N_SETTER(setCheckState), N_NO_NOTIFY)
};

using CheckBoxRef = CheckBoxRefT<QCheckBox>;

}

#endif // CHECKBOX_H
