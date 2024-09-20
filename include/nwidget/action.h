#ifndef NWIDGET_ACTION_H
#define NWIDGET_ACTION_H

#include <QAction>
#include <QFont>

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
    N_BUILDER_PROPERTY(bool               , iconVisibleInMenu, setIconVisibleInMenu)
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

N_DECLARE_BUILDER(Action, ActionBuilder, QAction)



template <typename T>
class ActionIdT : public ObjectIdT<T>
{
public:
    using ObjectIdT<T>::ObjectIdT;

    N_ID_PROPERTY(bool               , checkable        , N_READ isCheckable     N_WRITE setCheckable       N_NOTIFY checkableChanged)
    N_ID_PROPERTY(bool               , checked          , N_READ isChecked       N_WRITE setChecked         N_NOTIFY toggled         )
    N_ID_PROPERTY(bool               , enabled          , N_READ isEnabled       N_WRITE setEnabled         N_NOTIFY enabledChanged  )
    N_ID_PROPERTY(QIcon              , icon             , N_READ icon            N_WRITE setIcon            N_NOTIFY changed         )
    N_ID_PROPERTY(QString            , text             , N_READ text            N_WRITE setText            N_NOTIFY changed         )
    N_ID_PROPERTY(QString            , iconText         , N_READ iconText        N_WRITE setIconText        N_NOTIFY changed         )
    N_ID_PROPERTY(QString            , toolTip          , N_READ toolTip         N_WRITE setToolTip         N_NOTIFY changed         )
    N_ID_PROPERTY(QString            , statusTip        , N_READ statusTip       N_WRITE setStatusTip       N_NOTIFY changed         )
    N_ID_PROPERTY(QString            , whatsThis        , N_READ whatsThis       N_WRITE setWhatsThis       N_NOTIFY changed         )
    N_ID_PROPERTY(QFont              , font             , N_READ font            N_WRITE setFont            N_NOTIFY changed         )
#if QT_CONFIG(shortcut)
    N_ID_PROPERTY(QKeySequence       , shortcut         , N_READ shortcut        N_WRITE setShortcut        N_NOTIFY changed         )
    N_ID_PROPERTY(Qt::ShortcutContext, shortcutContext  , N_READ shortcutContext N_WRITE setShortcutContext N_NOTIFY changed         )
    N_ID_PROPERTY(bool               , autoRepeat       , N_READ autoRepeat      N_WRITE setAutoRepeat      N_NOTIFY changed         )
#endif
    N_ID_PROPERTY(bool               , visible          , N_READ isVisible       N_WRITE setVisible         N_NOTIFY visibleChanged  )
    N_ID_PROPERTY(QAction::MenuRole  , menuRole         , N_READ menuRole        N_WRITE setMenuRole        N_NOTIFY changed         )
    N_ID_PROPERTY(bool               , iconVisibleInMenu, N_READ isIconVisibleInMenu
                                                          N_WRITE setIconVisibleInMenu
                                                          N_NOTIFY changed)
    N_ID_PROPERTY(bool    , shortcutVisibleInContextMenu, N_READ isShortcutVisibleInContextMenu
                                                          N_WRITE setShortcutVisibleInContextMenu
                                                          N_NOTIFY changed)
    N_ID_PROPERTY(QAction::Priority  , priority         , N_READ priority        N_WRITE setPriority        N_NOTIFY changed         )
};

N_DECLARE_ID(Action, ActionIdT, QAction)

}

N_REGISTER_ID(nwidget::Action, QAction)
N_REGISTER_BUILDER(nwidget::Action, QAction)

#endif // NWIDGET_ACTION_H
