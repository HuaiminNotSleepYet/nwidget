#ifndef NWIDGET_PUSHBUTTON_H
#define NWIDGET_PUSHBUTTON_H

#include <QPushButton>

#include "abstractbutton.h"

namespace nwidget {

template<typename S, typename T>
class PushButtonBuilder : public AbstractButtonBuilder<S, T>
{
    N_BUILDER

public:
    PushButtonBuilder()                                       : AbstractButtonBuilder<S, T>(new T) {}
    explicit
    PushButtonBuilder(const QString& text)                    : AbstractButtonBuilder<S, T>(new T(text)) {}
    PushButtonBuilder(const QIcon& icon, const QString& text) : AbstractButtonBuilder<S, T>(new T(icon, text)) {}
    explicit
    PushButtonBuilder(T* target)                              : AbstractButtonBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(bool, autoDefault, setAutoDefault)
    N_BUILDER_PROPERTY(bool, default_   , setDefault    )
    N_BUILDER_PROPERTY(bool, flat       , setFlat       )

    S& menu(QMenu* m) { t->setMenu(m); return self(); }
};

N_DECLARE_BUILDER(PushButton, PushButtonBuilder, QPushButton)



template<typename T>
class PushButtonIdT : public AbstractButtonIdT<T>
{
public:
    using AbstractButtonIdT<T>::AbstractButtonIdT;

    N_ID_PROPERTY(bool, autoDefault, N_READ autoDefault N_WRITE setAutoDefault)
    N_ID_PROPERTY(bool, default_   , N_READ isDefault   N_WRITE setDefault    )
    N_ID_PROPERTY(bool, flat       , N_READ isFlat      N_WRITE setFlat       )
};

N_DECLARE_ID(PushButton, PushButtonIdT, QPushButton)

}

#endif // NWIDGET_PUSHBUTTON_H
