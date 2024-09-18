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
    N_BUILDER_SETTER1(menu, setMenu)
#endif
};

N_DECLARE_BUILDER(ToolButton, ToolButtonBuilder, QToolButton);



template<typename T>
class ToolButtonIdT : public AbstractButtonIdT<T>
{
public:
    using AbstractButtonIdT<T>::AbstractButtonIdT;

#if QT_CONFIG(menu)
    N_ID_PROPERTY(QToolButton::ToolButtonPopupMode, popupMode, N_READ popupMode N_WRITE setPopupMode)
#endif
    N_ID_PROPERTY(Qt::ToolButtonStyle, toolButtonStyle, N_READ toolButtonStyle N_WRITE setToolButtonStyle)
    N_ID_PROPERTY(bool               , autoRaise      , N_READ autoRaise       N_WRITE setAutoRaise      )
    N_ID_PROPERTY(Qt::ArrowType      , arrowType      , N_READ arrowType       N_WRITE setArrowType      )
};

N_DECLARE_ID(ToolButton, ToolButtonIdT, QToolButton)

}

#endif // NWIDGET_TOOLBUTTON_H
