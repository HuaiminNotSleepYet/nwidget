#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QAbstractButton>
#include <QToolButton>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class AbstractButtonBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    AbstractButtonBuilder()                   : WidgetBuilder<S, T>(new T) {}
    explicit AbstractButtonBuilder(T* target) : WidgetBuilder<S, T>(target) {}

    S& text(const QString& text) { t->setText(text);            return self(); }
    S& icon(const QIcon& ico)    { t->setIcon(ico);             return self(); }
    S& checkable(bool b)         { t->setCheckable(b);          return self(); }
    S& down(bool b)              { t->setDown(b);               return self(); }
    S& autoRepeat(bool b)        { t->setAutoRepeat(b);         return self(); }
    S& autoRepeatDelay(int b)    { t->setAutoRepeatDelay(b);    return self(); }
    S& autoRepeatInterval(int b) { t->setAutoRepeatInterval(b); return self(); }
    S& autoExclusive(bool b)     { t->setAutoExclusive(b);      return self(); }

    S& checked(bool b)           { t->setChecked(b);            return self(); }
    S& iconSize(const QSize& s)  { t->setIconSize(s);           return self(); }

    N_SIGNAL(onClicked , QAbstractButton::clicked )
    N_SIGNAL(onPressed , QAbstractButton::pressed )
    N_SIGNAL(onReleased, QAbstractButton::released)
    N_SIGNAL(onToggled , QAbstractButton::toggled )
};

N_BUILDER_IMPL(AbstractButtonBuilder, QAbstractButton, AbstractButton);

}

#endif // ABSTRACTBUTTON_H
