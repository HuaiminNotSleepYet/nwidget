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

N_DECLARE_BUILDER(GroupBox, GroupBoxBuilder, QGroupBox)



template <typename T>
class GroupBoxIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(QString      , title    , N_READ title       N_WRITE setTitle    )
    N_ID_PROPERTY(Qt::Alignment, alignment, N_READ alignment   N_WRITE setAlignment)
    N_ID_PROPERTY(bool         , flat     , N_READ isFlat      N_WRITE setFlat     )
    N_ID_PROPERTY(bool         , checkable, N_READ isCheckable N_WRITE setCheckable)
    N_ID_PROPERTY(bool         , checked  , N_READ isChecked   N_WRITE setChecked  N_NOTIFY toggled)
};

N_DECLARE_ID(GroupBox, GroupBoxIdT, QGroupBox)

}

N_REGISTER_ID(nwidget::GroupBox, QGroupBox)
N_REGISTER_BUILDER(nwidget::GroupBox, QGroupBox)

#endif // NWIDGET_GROUPBOX_H
