#ifndef ACTION_H
#define ACTION_H

#include <QAction>

#include "object.h"

namespace nw {

template<typename S, typename T>
class ActionBuilder : public ObjectBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(ObjectBuilder, S, T)

public:
    ActionBuilder()                                       : ObjectBuilder<S, T>(new T) {}
    ActionBuilder(const QString& text)                    : ObjectBuilder<S, T>(new T(text)) {}
    ActionBuilder(const QIcon& icon, const QString& text) : ObjectBuilder<S, T>(new T(icon, text)) {}
    explicit ActionBuilder(T* target)                     : ObjectBuilder<S, T>(target) {}

    N_SIGNAL(onChanged         , QAction::changed         )
    N_SIGNAL(onEnabledChanged  , QAction::enabledChanged  )
    N_SIGNAL(onCheckableChanged, QAction::checkableChanged)
    N_SIGNAL(onVisibleChanged  , QAction::visibleChanged  )
    N_SIGNAL(onTriggered       , QAction::triggered       )
    N_SIGNAL(onHovered         , QAction::hovered         )
    N_SIGNAL(onToggled         , QAction::toggled         )
};

N_BUILDER_IMPL(ActionBuilder, QAction, Action);



template <typename T>
class ActionRefT : public ObjectRefT<T>
{
public:
    using ObjectRefT<T>::ObjectRefT;

    N_PROPERTY(bool               , checkable        , N_GETTER(isCheckable    ), N_SETTER(setCheckable      ), N_NOTIFY(checkableChanged))
    N_PROPERTY(bool               , checked          , N_GETTER(isChecked      ), N_SETTER(setChecked        ), N_NOTIFY(toggled         ))
    N_PROPERTY(bool               , enabled          , N_GETTER(isEnabled      ), N_SETTER(setEnabled        ), N_NOTIFY(enabledChanged  ))
    N_PROPERTY(QIcon              , icon             , N_GETTER(icon           ), N_SETTER(setIcon           ), N_NOTIFY(changed         ))
    N_PROPERTY(QString            , text             , N_GETTER(text           ), N_SETTER(setText           ), N_NOTIFY(changed         ))
    N_PROPERTY(QString            , iconText         , N_GETTER(iconText       ), N_SETTER(setIconText       ), N_NOTIFY(changed         ))
    N_PROPERTY(QString            , toolTip          , N_GETTER(toolTip        ), N_SETTER(setToolTip        ), N_NOTIFY(changed         ))
    N_PROPERTY(QString            , statusTip        , N_GETTER(statusTip      ), N_SETTER(setStatusTip      ), N_NOTIFY(changed         ))
    N_PROPERTY(QString            , whatsThis        , N_GETTER(whatsThis      ), N_SETTER(setWhatsThis      ), N_NOTIFY(changed         ))
    N_PROPERTY(QFont              , font             , N_GETTER(font           ), N_SETTER(setFont           ), N_NOTIFY(changed         ))
#if QT_CONFIG(shortcut)
    N_PROPERTY(QKeySequence       , shortcut         , N_GETTER(shortcut       ), N_SETTER(setShortcut       ), N_NOTIFY(changed         ))
    N_PROPERTY(Qt::ShortcutContext, shortcutContext  , N_GETTER(shortcutContext), N_SETTER(setShortcutContext), N_NOTIFY(changed         ))
    N_PROPERTY(bool               , autoRepeat       , N_GETTER(autoRepeat     ), N_SETTER(setAutoRepeat     ), N_NOTIFY(changed         ))
#endif
    N_PROPERTY(bool               , visible          , N_GETTER(isVisible      ), N_SETTER(setVisible        ), N_NOTIFY(visibleChanged  ))
    N_PROPERTY(QAction::MenuRole  , menuRole         , N_GETTER(menuRole       ), N_SETTER(setMenuRole       ), N_NOTIFY(changed         ))
    N_PROPERTY(bool               , iconVisibleInMenu, N_GETTER(isIconVisibleIn), N_SETTER(setIconVisibleInMe), N_NOTIFY(changed         ))
    N_PROPERTY(bool               , shortcutVisibleInContextMenu,
               N_GETTER(isShortcutVisibleInContextMenu), N_SETTER(setShortcutVisibleInContextMenu), N_NOTIFY(changed))
    N_PROPERTY(QAction::Priority  , priority         , N_GETTER(priority       ), N_SETTER(setPriority       ), N_NOTIFY(changed         ))
};

using ActionRef = ActionRefT<QAction>;

}

#endif // ACTION_H
