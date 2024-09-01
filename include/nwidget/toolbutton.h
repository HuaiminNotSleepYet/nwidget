#ifndef NWIDGET_TOOLBUTTON_H
#define NWIDGET_TOOLBUTTON_H

#include <QToolButton>

#include "abstractbutton.h"

namespace nwidget {

template<typename S, typename T>
class ToolButtonBuilder : public AbstractButtonBuilder<S, T>
{
    N_BUILDER

public:
    ToolButtonBuilder()                    : AbstractButtonBuilder<S, T>(new T) {}
    explicit
    ToolButtonBuilder(const QString& text) : AbstractButtonBuilder<S, T>(new T) { t->setText(text); }
    explicit
    ToolButtonBuilder(T* target)           : AbstractButtonBuilder<S, T>(target) {}


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

N_DECL_BUILDER(ToolButtonBuilder, QToolButton, ToolButton);



template<typename T>
class ToolButtonIdT : public AbstractButtonIdT<T>
{
public:
    using AbstractButtonIdT<T>::AbstractButtonIdT;

#if QT_CONFIG(menu)
    N_ID_PROPERTY(QToolButton::ToolButtonPopupMode, popupMode, N_GETTER(popupMode), N_SETTER(setPopupMode), N_NO_NOTIFY)
#endif
    N_ID_PROPERTY(Qt::ToolButtonStyle, toolButtonStyle, N_GETTER(toolButtonStyle), N_SETTER(setToolButtonStyle), N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , autoRaise      , N_GETTER(autoRaise      ), N_SETTER(setAutoRaise      ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::ArrowType      , arrowType      , N_GETTER(arrowType      ), N_SETTER(setArrowType      ), N_NO_NOTIFY)
};

using ToolButtonId = AbstractButtonIdT<QToolButton>;

}

#endif // NWIDGET_TOOLBUTTON_H
