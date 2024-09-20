#ifndef NWIDGET_ABSTRACTBUTTON_H
#define NWIDGET_ABSTRACTBUTTON_H

#include <QAbstractButton>
#include <QButtonGroup>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class AbstractButtonBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    AbstractButtonBuilder()          : WidgetBuilder<S, T>(new T) {}
    explicit
    AbstractButtonBuilder(T* target) : WidgetBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(QString     , text              , setText              )
    N_BUILDER_PROPERTY(QIcon       , icon              , setIcon              )
    N_BUILDER_PROPERTY(QSize       , iconSize          , setIconSize          )
#ifndef QT_NO_SHORTCUT
    N_BUILDER_PROPERTY(QKeySequence, shortcut          , setShortcut          )
#endif
    N_BUILDER_PROPERTY(bool        , checkable         , setCheckable         )
    N_BUILDER_PROPERTY(bool        , checked           , setChecked           )
    N_BUILDER_PROPERTY(bool        , autoRepeat        , setAutoRepeat        )
    N_BUILDER_PROPERTY(bool        , autoExclusive     , setAutoExclusive     )
    N_BUILDER_PROPERTY(int         , autoRepeatDelay   , setAutoRepeatDelay   )
    N_BUILDER_PROPERTY(int         , autoRepeatInterval, setAutoRepeatInterval)
    N_BUILDER_PROPERTY(bool        , down              , setDown              )

    N_BUILDER_SETTER S& group(QButtonGroup* g, int id = -1) { g->addButton(target(), id); return self(); }

    N_BUILDER_SIGNAL(onClicked , clicked )
    N_BUILDER_SIGNAL(onPressed , pressed )
    N_BUILDER_SIGNAL(onReleased, released)
    N_BUILDER_SIGNAL(onToggled , toggled )
};

N_DECLARE_BUILDER(AbstractButton, AbstractButtonBuilder, QAbstractButton)



template<typename T>
class AbstractButtonIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(QString     , text              , N_READ text               N_WRITE setText              )
    N_ID_PROPERTY(QIcon       , icon              , N_READ icon               N_WRITE setIcon              )
    N_ID_PROPERTY(QSize       , iconSize          , N_READ iconSize           N_WRITE setIconSize          )
#ifndef QT_NO_SHORTCUT
    N_ID_PROPERTY(QKeySequence, shortcut          , N_READ shortcut           N_WRITE setShortcut          )
#endif
    N_ID_PROPERTY(bool        , checkable         , N_READ isCheckable        N_WRITE setCheckable         )
    N_ID_PROPERTY(bool        , checked           , N_READ isChecked          N_WRITE setChecked           N_NOTIFY toggled)
    N_ID_PROPERTY(bool        , autoRepeat        , N_READ autoRepeat         N_WRITE setAutoRepeat        )
    N_ID_PROPERTY(bool        , autoExclusive     , N_READ autoExclusive      N_WRITE setAutoExclusive     )
    N_ID_PROPERTY(int         , autoRepeatDelay   , N_READ autoRepeatDelay    N_WRITE setAutoRepeatDelay   )
    N_ID_PROPERTY(int         , autoRepeatInterval, N_READ autoRepeatInterval N_WRITE setAutoRepeatInterval)
    N_ID_PROPERTY(bool        , down              , N_READ isDown             N_WRITE setDown              )
};

N_DECLARE_ID(AbstractButton, AbstractButtonIdT, QAbstractButton)

}

N_REGISTER_ID(nwidget::AbstractButton, QAbstractButton)
N_REGISTER_BUILDER(nwidget::AbstractButton, QAbstractButton)

#endif // NWIDGET_ABSTRACTBUTTON_H
