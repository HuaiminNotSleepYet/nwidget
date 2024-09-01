#ifndef NWIDGET_ACTION_H
#define NWIDGET_ACTION_H

#include <QAction>

#include "object.h"

namespace nwidget {

template<typename S, typename T>
class ActionBuilder : public ObjectBuilder<S, T>
{
    N_BUILDER

public:
    ActionBuilder()                                       : ObjectBuilder<S, T>(new T) {}
    explicit
    ActionBuilder(const QString& text)                    : ObjectBuilder<S, T>(new T(text)) {}
    ActionBuilder(const QIcon& icon, const QString& text) : ObjectBuilder<S, T>(new T(icon, text)) {}
    explicit
    ActionBuilder(T* target)                              : ObjectBuilder<S, T>(target) {}


    N_BUILDER_PROPERTY(bool               , checkable        , setCheckable      )
    N_BUILDER_PROPERTY(bool               , checked          , setChecked        )
    N_BUILDER_PROPERTY(bool               , enabled          , setEnabled        )
    N_BUILDER_PROPERTY(QIcon              , icon             , setIcon           )
    N_BUILDER_PROPERTY(QString            , text             , setText           )
    N_BUILDER_PROPERTY(QString            , iconText         , setIconText       )
    N_BUILDER_PROPERTY(QString            , toolTip          , setToolTip        )
    N_BUILDER_PROPERTY(QString            , statusTip        , setStatusTip      )
    N_BUILDER_PROPERTY(QString            , whatsThis        , setWhatsThis      )
    N_BUILDER_PROPERTY(QFont              , font             , setFont           )
#if QT_CONFIG(shortcut)
    N_BUILDER_PROPERTY(QKeySequence       , shortcut         , setShortcut       )
    N_BUILDER_PROPERTY(Qt::ShortcutContext, shortcutContext  , setShortcutContext)
    N_BUILDER_PROPERTY(bool               , autoRepeat       , setAutoRepeat     )
#endif
    N_BUILDER_PROPERTY(bool               , visible          , setVisible        )
    N_BUILDER_PROPERTY(QAction::MenuRole  , menuRole         , setMenuRole       )
    N_BUILDER_PROPERTY(bool               , iconVisibleInMenu, setIconVisibleInMe)
    N_BUILDER_PROPERTY(bool               , shortcutVisibleInContextMenu, setShortcutVisibleInContextMenu)
    N_BUILDER_PROPERTY(QAction::Priority  , priority         , setPriority       )

    N_BUILDER_SIGNAL(onChanged         , changed         )
    N_BUILDER_SIGNAL(onEnabledChanged  , enabledChanged  )
    N_BUILDER_SIGNAL(onCheckableChanged, checkableChanged)
    N_BUILDER_SIGNAL(onVisibleChanged  , visibleChanged  )
    N_BUILDER_SIGNAL(onTriggered       , triggered       )
    N_BUILDER_SIGNAL(onHovered         , hovered         )
    N_BUILDER_SIGNAL(onToggled         , toggled         )
};

N_DECL_BUILDER(ActionBuilder, QAction, Action);



template <typename T>
class ActionIdT : public ObjectIdT<T>
{
public:
    using ObjectIdT<T>::ObjectIdT;

    N_ID_PROPERTY(bool               , checkable        , N_GETTER(isCheckable    ), N_SETTER(setCheckable      ), N_NOTIFY(checkableChanged))
    N_ID_PROPERTY(bool               , checked          , N_GETTER(isChecked      ), N_SETTER(setChecked        ), N_NOTIFY(toggled         ))
    N_ID_PROPERTY(bool               , enabled          , N_GETTER(isEnabled      ), N_SETTER(setEnabled        ), N_NOTIFY(enabledChanged  ))
    N_ID_PROPERTY(QIcon              , icon             , N_GETTER(icon           ), N_SETTER(setIcon           ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(QString            , text             , N_GETTER(text           ), N_SETTER(setText           ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(QString            , iconText         , N_GETTER(iconText       ), N_SETTER(setIconText       ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(QString            , toolTip          , N_GETTER(toolTip        ), N_SETTER(setToolTip        ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(QString            , statusTip        , N_GETTER(statusTip      ), N_SETTER(setStatusTip      ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(QString            , whatsThis        , N_GETTER(whatsThis      ), N_SETTER(setWhatsThis      ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(QFont              , font             , N_GETTER(font           ), N_SETTER(setFont           ), N_NOTIFY(changed         ))
#if QT_CONFIG(shortcut)
    N_ID_PROPERTY(QKeySequence       , shortcut         , N_GETTER(shortcut       ), N_SETTER(setShortcut       ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(Qt::ShortcutContext, shortcutContext  , N_GETTER(shortcutContext), N_SETTER(setShortcutContext), N_NOTIFY(changed         ))
    N_ID_PROPERTY(bool               , autoRepeat       , N_GETTER(autoRepeat     ), N_SETTER(setAutoRepeat     ), N_NOTIFY(changed         ))
#endif
    N_ID_PROPERTY(bool               , visible          , N_GETTER(isVisible      ), N_SETTER(setVisible        ), N_NOTIFY(visibleChanged  ))
    N_ID_PROPERTY(QAction::MenuRole  , menuRole         , N_GETTER(menuRole       ), N_SETTER(setMenuRole       ), N_NOTIFY(changed         ))
    N_ID_PROPERTY(bool               , iconVisibleInMenu, N_GETTER(isIconVisibleIn), N_SETTER(setIconVisibleInMe), N_NOTIFY(changed         ))
    N_ID_PROPERTY(bool               , shortcutVisibleInContextMenu,
               N_GETTER(isShortcutVisibleInContextMenu), N_SETTER(setShortcutVisibleInContextMenu), N_NOTIFY(changed))
    N_ID_PROPERTY(QAction::Priority  , priority         , N_GETTER(priority       ), N_SETTER(setPriority       ), N_NOTIFY(changed         ))
};

using ActionId = ActionIdT<QAction>;

}

#endif // NWIDGET_ACTION_H
