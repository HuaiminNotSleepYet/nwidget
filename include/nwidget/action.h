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

}

#endif // ACTION_H
