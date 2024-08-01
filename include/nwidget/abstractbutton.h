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

    inline S& text(const QString& text) { t->setText(text);            return self(); }
    inline S& icon(const QIcon& ico)    { t->setIcon(ico);             return self(); }
    inline S& checkable(bool b)         { t->setCheckable(b);          return self(); }
    inline S& down(bool b)              { t->setDown(b);               return self(); }
    inline S& autoRepeat(bool b)        { t->setAutoRepeat(b);         return self(); }
    inline S& autoRepeatDelay(int b)    { t->setAutoRepeatDelay(b);    return self(); }
    inline S& autoRepeatInterval(int b) { t->setAutoRepeatInterval(b); return self(); }
    inline S& autoExclusive(bool b)     { t->setAutoExclusive(b);      return self(); }

    inline S& checked(bool b)           { t->setChecked(b);            return self(); }
    inline S& iconSize(const QSize& s)  { t->setIconSize(s);           return self(); }

    N_SIGNAL(onClicked , QAbstractButton::clicked )
    N_SIGNAL(onPressed , QAbstractButton::pressed )
    N_SIGNAL(onReleased, QAbstractButton::released)
    N_SIGNAL(onToggled , QAbstractButton::toggled )
};

N_BUILDER_IMPL(AbstractButtonBuilder, QAbstractButton, AbstractButton);

}

#endif // ABSTRACTBUTTON_H
