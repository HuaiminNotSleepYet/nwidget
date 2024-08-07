#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>

#include "abstractbutton.h"

namespace nw {

template<typename S, typename T>
class ToolButtonBuilder : public AbstractButtonBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractButtonBuilder, S, T)

public:
    ToolButtonBuilder()                    : AbstractButtonBuilder<S, T>(new T) {}
    explicit ToolButtonBuilder(T* target)  : AbstractButtonBuilder<S, T>(target) {}
    ToolButtonBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T) { t->setText(text); }

    S& arrowType(Qt::ArrowType type)                     { t->setArrowType(type); return self(); }
    S& popupMode(QToolButton::ToolButtonPopupMode mode)  { t->setPopupMode(mode); return self(); }
    S& autoRaise(bool b)                                 { t->setAutoRaise(b);    return self(); }
    S& menu(QMenu* m)                                    { t->setMenu(m);         return self(); }
};

N_BUILDER_IMPL(ToolButtonBuilder, QToolButton, ToolButton);

}

#endif // TOOLBUTTON_H
