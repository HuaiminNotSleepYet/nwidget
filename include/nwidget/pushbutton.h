#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

#include "abstractbutton.h"

namespace nw {

template<typename S, typename T>
class PushButtonBuilder : public AbstractButtonBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractButtonBuilder, S, T)

public:
    PushButtonBuilder()                                       : AbstractButtonBuilder<S, T>(new T) {}
    PushButtonBuilder(const QString& text)                    : AbstractButtonBuilder<S, T>(new T(text)) {}
    PushButtonBuilder(const QIcon& icon, const QString& text) : AbstractButtonBuilder<S, T>(new T(icon, text)) {}

    explicit PushButtonBuilder(T* target)                                : AbstractButtonBuilder<S, T>(target) {}
    PushButtonBuilder(T* target, const QString& text)                    : AbstractButtonBuilder<S, T>(target) { t->setText(text); }
    PushButtonBuilder(T* target, const QIcon& icon, const QString& text) : AbstractButtonBuilder<S, T>(target) { t->setIcon(icon); t->setText(text); }

    S& autoDefault(bool b)   { t->setAutoDefault(b); return self(); }
    S& default_(bool b)      { t->setDefault(b);     return self(); }
    S& flat(bool b)          { t->setFlat(b);        return self(); }
    S& menu(QMenu* m)        { t->setMenu(m);        return self(); }
};

N_BUILDER_IMPL(PushButtonBuilder, QPushButton, PushButton);



template<typename T>
class PushButtonIdT : public AbstractButtonIdT<T>
{
public:
    using AbstractButtonIdT<T>::AbstractButtonIdT;

    N_PROPERTY(bool, autoDefault, N_GETTER(autoDefault), N_SETTER(setAutoDefault), N_NO_NOTIFY)
    N_PROPERTY(bool, default_   , N_GETTER(isDefault  ), N_SETTER(setDefault    ), N_NO_NOTIFY)
    N_PROPERTY(bool, flat       , N_GETTER(isFlat     ), N_SETTER(setFlat       ), N_NO_NOTIFY)
};

using PushButtonId = PushButtonIdT<QPushButton>;

}

#endif // PUSHBUTTON_H
