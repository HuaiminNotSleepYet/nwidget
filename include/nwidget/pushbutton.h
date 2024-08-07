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
    explicit PushButtonBuilder(T* target)                     : AbstractButtonBuilder<S, T>(target) {}
    PushButtonBuilder(const QString& text)                    : AbstractButtonBuilder<S, T>(new T(text)) {}
    PushButtonBuilder(const QIcon& icon, const QString& text) : AbstractButtonBuilder<S, T>(new T(icon, text)) {}

    S& autoDefault(bool b)   { t->setAutoDefault(b); return self(); }
    S& default_(bool b)      { t->setDefault(b);     return self(); }
    S& flat(bool b)          { t->setFlat(b);        return self(); }
    S& menu(QMenu* m)        { t->setMenu(m);        return self(); }
};

N_BUILDER_IMPL(PushButtonBuilder, QPushButton, PushButton);

}

#endif // PUSHBUTTON_H
