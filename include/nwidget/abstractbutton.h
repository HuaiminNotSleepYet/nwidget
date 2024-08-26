#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QAbstractButton>
#include <QButtonGroup>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class AbstractButtonBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    AbstractButtonBuilder()                   : WidgetBuilder<S, T>(new T) {}
    explicit AbstractButtonBuilder(T* target) : WidgetBuilder<S, T>(target) {}

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

    S& group(QButtonGroup* g) { g->addButton(t); return self(); }

    N_SIGNAL(onClicked , QAbstractButton::clicked )
    N_SIGNAL(onPressed , QAbstractButton::pressed )
    N_SIGNAL(onReleased, QAbstractButton::released)
    N_SIGNAL(onToggled , QAbstractButton::toggled )
};

N_BUILDER_IMPL(AbstractButtonBuilder, QAbstractButton, AbstractButton);



template<typename T>
class AbstractButtonIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_PROPERTY(QString     , text              , N_GETTER(text              ), N_SETTER(setText              ), N_NO_NOTIFY)
    N_PROPERTY(QIcon       , icon              , N_GETTER(icon              ), N_SETTER(setIcon              ), N_NO_NOTIFY)
    N_PROPERTY(QSize       , iconSize          , N_GETTER(iconSize          ), N_SETTER(setIconSize          ), N_NO_NOTIFY)
#ifndef QT_NO_SHORTCUT
    N_PROPERTY(QKeySequence, shortcut          , N_GETTER(shortcut          ), N_SETTER(setShortcut          ), N_NO_NOTIFY)
#endif
    N_PROPERTY(bool        , checkable         , N_GETTER(isCheckable       ), N_SETTER(setCheckable         ), N_NO_NOTIFY)
    N_PROPERTY(bool        , checked           , N_GETTER(isChecked         ), N_SETTER(setChecked           ), N_NOTIFY(toggled))
    N_PROPERTY(bool        , autoRepeat        , N_GETTER(autoRepeat        ), N_SETTER(setAutoRepeat        ), N_NO_NOTIFY)
    N_PROPERTY(bool        , autoExclusive     , N_GETTER(autoExclusive     ), N_SETTER(setAutoExclusive     ), N_NO_NOTIFY)
    N_PROPERTY(int         , autoRepeatDelay   , N_GETTER(autoRepeatDelay   ), N_SETTER(setAutoRepeatDelay   ), N_NO_NOTIFY)
    N_PROPERTY(int         , autoRepeatInterval, N_GETTER(autoRepeatInterval), N_SETTER(setAutoRepeatInterval), N_NO_NOTIFY)
    N_PROPERTY(bool        , down              , N_GETTER(isDown            ), N_SETTER(setDown              ), N_NO_NOTIFY)
};

using AbstractButtonId = AbstractButtonIdT<QAbstractButton>;

}

#endif // ABSTRACTBUTTON_H
