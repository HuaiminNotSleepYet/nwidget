#ifndef NWIDGET_CHECKBOX_H
#define NWIDGET_CHECKBOX_H

#include <QCheckBox>

#include "abstractbutton.h"

namespace nwidget {

template<typename S, typename T>
class CheckBoxBuilder : public AbstractButtonBuilder<S, T>
{
    N_BUILDER

public:
    CheckBoxBuilder()                    : AbstractButtonBuilder<S, T>(new T) {}
    explicit
    CheckBoxBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T(text)) {}
    explicit
    CheckBoxBuilder(T* target)           : AbstractButtonBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(bool          , tristate  , setTristate  )
    N_BUILDER_PROPERTY(Qt::CheckState, checkState, setCheckState)

    N_BUILDER_SIGNAL(onStateChanged, stateChanged)
};

N_DECLARE_BUILDER(CheckBox, CheckBoxBuilder, QCheckBox)



template<typename T>
class CheckBoxIdT : public AbstractButtonIdT<T>
{
public:
    using AbstractButtonIdT<T>::AbstractButtonIdT;

    N_ID_PROPERTY(bool          , tristate  , N_READ isTristate N_WRITE setTristate  )
    N_ID_PROPERTY(Qt::CheckState, checkState, N_READ checkState N_WRITE setCheckState)
};

N_DECLARE_ID(CheckBox, CheckBoxIdT, QCheckBox)

}

N_REGISTER_ID(nwidget::CheckBox, QCheckBox)
N_REGISTER_BUILDER(nwidget::CheckBox, QCheckBox)

#endif // NWIDGET_CHECKBOX_H
