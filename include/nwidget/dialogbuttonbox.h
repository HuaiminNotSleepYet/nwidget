#ifndef NWIDGET_DIALOGBUTTONBOX_H
#define NWIDGET_DIALOGBUTTONBOX_H

#include <QDialogButtonBox>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class DialogButtonBoxBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    DialogButtonBoxBuilder()                                          : WidgetBuilder<S, T>(new T) {}
    explicit
    DialogButtonBoxBuilder(Qt::Orientation orientation)               : WidgetBuilder<S, T>(new T(orientation)) {}
    explicit
    DialogButtonBoxBuilder(QDialogButtonBox::StandardButtons buttons) : WidgetBuilder<S, T>(new T(buttons)) {}
    DialogButtonBoxBuilder(QDialogButtonBox::StandardButtons buttons,
                           Qt::Orientation orientation)               : WidgetBuilder<S, T>(new T(buttons, orientation)) {}
    explicit
    DialogButtonBoxBuilder(T* target)                                 : WidgetBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(Qt::Orientation                  , orientation    , setOrientation    )
    N_BUILDER_PROPERTY(QDialogButtonBox::StandardButtons, standardButtons, setStandardButtons)
    N_BUILDER_PROPERTY(bool                             , centerButtons  , setCenterButtons  )

    N_BUILDER_SIGNAL(onClicked      , clicked      )
    N_BUILDER_SIGNAL(onAccepted     , accepted     )
    N_BUILDER_SIGNAL(onHelpRequested, helpRequested)
    N_BUILDER_SIGNAL(onRejected     , rejected     )
};

N_DECLARE_BUILDER(DialogButtonBox, DialogButtonBoxBuilder, QDialogButtonBox)



template <typename T>
class DialogButtonBoxIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(Qt::Orientation, orientation    , N_GETTER(orientation    ), N_SETTER(setOrientation    ), N_NO_NOTIFY)
    N_ID_PROPERTY(QDialogButtonBox::StandardButtons
                              , standardButtons, N_GETTER(standardButtons), N_SETTER(setStandardButtons), N_NO_NOTIFY)
    N_ID_PROPERTY(bool           , centerButtons  , N_GETTER(centerButtons  ), N_SETTER(setCenterButtons  ), N_NO_NOTIFY)
};

N_DECLARE_ID(DialogButtonBox, DialogButtonBoxIdT, QDialogButtonBox)

}

#endif // NWIDGET_DIALOGBUTTONBOX_H
