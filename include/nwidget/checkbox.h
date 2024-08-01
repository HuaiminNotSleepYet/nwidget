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
    CheckBoxBuilder()                    : AbstractButtonBuilder<S, T>(new T) {}
    CheckBoxBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T(text)) {}
    explicit CheckBoxBuilder(T* target)  : AbstractButtonBuilder<S, T>(target) {}

    inline S& checkState(Qt::CheckState state)  { t->setCheckState(state); return self(); }
    inline S& tristate(bool b = true)           { t->setTristate(b);       return self(); }
};

N_BUILDER_IMPL(CheckBoxBuilder, QCheckBox, CheckBox);

}

#endif // CHECKBOX_H
