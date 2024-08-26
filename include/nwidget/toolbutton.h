#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>

#include "abstractbutton.h"

namespace nw {

template<typename S, typename T>
class ToolButtonBuilder : public AbstractButtonBuilder<S, T>
{
    N_BUILDER

public:
    ToolButtonBuilder()                    : AbstractButtonBuilder<S, T>(new T) {}
    ToolButtonBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T) { t->setText(text); }
    explicit ToolButtonBuilder(T* target)  : AbstractButtonBuilder<S, T>(target) {}
    ToolButtonBuilder(T* target, const QString& text) : AbstractButtonBuilder<S, T>(target) { t->setText(text); }

#if QT_CONFIG(menu)
    N_BUILDER_PROPERTY(QToolButton::ToolButtonPopupMode, popupMode, setPopupMode)
#endif
    N_BUILDER_PROPERTY(Qt::ToolButtonStyle, toolButtonStyle, setToolButtonStyle)
    N_BUILDER_PROPERTY(bool               , autoRaise      , setAutoRaise      )
    N_BUILDER_PROPERTY(Qt::ArrowType      , arrowType      , setArrowType      )

#if QT_CONFIG(menu)
    S& menu(QMenu* m) { t->setMenu(m); return self(); }
#endif
};

N_BUILDER_IMPL(ToolButtonBuilder, QToolButton, ToolButton);



template<typename T>
class ToolButtonIdT : public AbstractButtonIdT<T>
{
public:
    using AbstractButtonIdT<T>::AbstractButtonIdT;

#if QT_CONFIG(menu)
    N_PROPERTY(QToolButton::ToolButtonPopupMode, popupMode, N_GETTER(popupMode), N_SETTER(setPopupMode), N_NO_NOTIFY)
#endif
    N_PROPERTY(Qt::ToolButtonStyle, toolButtonStyle, N_GETTER(toolButtonStyle), N_SETTER(setToolButtonStyle), N_NO_NOTIFY)
    N_PROPERTY(bool               , autoRaise      , N_GETTER(autoRaise      ), N_SETTER(setAutoRaise      ), N_NO_NOTIFY)
    N_PROPERTY(Qt::ArrowType      , arrowType      , N_GETTER(arrowType      ), N_SETTER(setArrowType      ), N_NO_NOTIFY)
};

using ToolButtonId = AbstractButtonIdT<QToolButton>;

}

#endif // TOOLBUTTON_H
