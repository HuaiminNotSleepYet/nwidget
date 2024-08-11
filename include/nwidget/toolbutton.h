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



template<typename T>
class ToolButtonRefT : public AbstractButtonRefT<T>
{
public:
    using AbstractButtonRefT<T>::AbstractButtonRefT;

#if QT_CONFIG(menu)
    N_PROPERTY(QToolButton::ToolButtonPopupMode, popupMode, N_GETTER(popupMode), N_SETTER(setPopupMode), N_NO_NOTIFY)
#endif
    N_PROPERTY(Qt::ToolButtonStyle, toolButtonStyle, N_GETTER(toolButtonStyle), N_SETTER(setToolButtonStyle), N_NO_NOTIFY)
    N_PROPERTY(bool               , autoRaise      , N_GETTER(autoRaise      ), N_SETTER(setAutoRaise      ), N_NO_NOTIFY)
    N_PROPERTY(Qt::ArrowType      , arrowType      , N_GETTER(arrowType      ), N_SETTER(setArrowType      ), N_NO_NOTIFY)
};

using ToolButtonRef = AbstractButtonRefT<QToolButton>;

}

#endif // TOOLBUTTON_H
