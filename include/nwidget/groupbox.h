#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QGroupBox>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class GroupBoxBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    GroupBoxBuilder()                                      : WidgetBuilder<S, T>(new T) {}
    explicit GroupBoxBuilder(const QString& title)         : WidgetBuilder<S, T>(new T(title)) {}
    GroupBoxBuilder(const QString& title, QLayout* layout) : WidgetBuilder<S, T>(new T(title), layout) {}

    explicit GroupBoxBuilder(T* target)                               : WidgetBuilder<S, T>(target) {}
    GroupBoxBuilder(T* target, QLayout* layout)                       : WidgetBuilder<S, T>(target, layout) {}
    GroupBoxBuilder(T* target, const QString& title, QLayout* layout) : WidgetBuilder<S, T>(target, layout) { this->title(title); }

    S& title(const QString& s)   { t->setTitle(s);         return self(); }
    S& alignment(int align)      { t->setAlignment(align); return self(); }
    S& flat(bool b)              { t->setFlat(b);          return self(); }
    S& checkable(bool b)         { t->setCheckable(b);     return self(); }
    S& checked(bool b)           { t->setChecked(b);       return self(); }
};

N_BUILDER_IMPL(GroupBoxBuilder, QGroupBox, GroupBox);



template <typename T>
class GroupBoxIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_PROPERTY(QString      , title    , N_GETTER(title      ), N_SETTER(setTitle    ), N_NO_NOTIFY)
    N_PROPERTY(Qt::Alignment, alignment, N_GETTER(alignment  ), N_SETTER(setAlignment), N_NO_NOTIFY)
    N_PROPERTY(bool         , flat     , N_GETTER(isFlat     ), N_SETTER(setFlat     ), N_NO_NOTIFY)
    N_PROPERTY(bool         , checkable, N_GETTER(isCheckable), N_SETTER(setCheckable), N_NO_NOTIFY)
    N_PROPERTY(bool         , checked  , N_GETTER(isChecked  ), N_SETTER(setChecked  ), N_NOTIFY(toggled))
};

using GroupBoxId = GroupBoxIdT<QGroupBox>;

}

#endif // GROUPBOX_H
