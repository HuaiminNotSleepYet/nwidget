#ifndef NWIDGET_GROUPBOX_H
#define NWIDGET_GROUPBOX_H

#include <QGroupBox>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class GroupBoxBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    GroupBoxBuilder()                                                 : WidgetBuilder<S, T>(new T) {}
    explicit
    GroupBoxBuilder(const QString& title)                             : WidgetBuilder<S, T>(new T(title)) {}
    GroupBoxBuilder(const QString& title, QLayout* layout)            : WidgetBuilder<S, T>(new T(title), layout) {}
    explicit
    GroupBoxBuilder(T* target)                                        : WidgetBuilder<S, T>(target) {}
    GroupBoxBuilder(T* target, QLayout* layout)                       : WidgetBuilder<S, T>(target, layout) {}
    GroupBoxBuilder(T* target, const QString& title, QLayout* layout) : WidgetBuilder<S, T>(target, layout) { this->title(title); }

    N_BUILDER_PROPERTY(QString      , title    , setTitle    )
    N_BUILDER_PROPERTY(Qt::Alignment, alignment, setAlignment)
    N_BUILDER_PROPERTY(bool         , flat     , setFlat     )
    N_BUILDER_PROPERTY(bool         , checkable, setCheckable)
    N_BUILDER_PROPERTY(bool         , checked  , setChecked  )
};

N_DECL_BUILDER(GroupBoxBuilder, QGroupBox, GroupBox);



template <typename T>
class GroupBoxIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(QString      , title    , N_GETTER(title      ), N_SETTER(setTitle    ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Alignment, alignment, N_GETTER(alignment  ), N_SETTER(setAlignment), N_NO_NOTIFY)
    N_ID_PROPERTY(bool         , flat     , N_GETTER(isFlat     ), N_SETTER(setFlat     ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool         , checkable, N_GETTER(isCheckable), N_SETTER(setCheckable), N_NO_NOTIFY)
    N_ID_PROPERTY(bool         , checked  , N_GETTER(isChecked  ), N_SETTER(setChecked  ), N_NOTIFY(toggled))
};

using GroupBoxId = GroupBoxIdT<QGroupBox>;

}

#endif // NWIDGET_GROUPBOX_H
