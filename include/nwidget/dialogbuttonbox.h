#ifndef DIALOGBUTTONBOX_H
#define DIALOGBUTTONBOX_H

#include <QDialogButtonBox>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class DialogButtonBoxBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    DialogButtonBoxBuilder()                                                             : WidgetBuilder<S, T>(new T) {}
    explicit DialogButtonBoxBuilder(T* target)                                           : WidgetBuilder<S, T>(target) {}
    explicit DialogButtonBoxBuilder(Qt::Orientation o)                                   : WidgetBuilder<S, T>(new T(o)) {}
    explicit DialogButtonBoxBuilder(QDialogButtonBox::StandardButtons buttons)           : WidgetBuilder<S, T>(new T(buttons)) {}
    DialogButtonBoxBuilder(QDialogButtonBox::StandardButtons buttons, Qt::Orientation o) : WidgetBuilder<S, T>(new T(buttons, o)) {}

    N_SIGNAL(onClicked      , QDialogButtonBox::clicked      )
    N_SIGNAL(onAccepted     , QDialogButtonBox::accepted     )
    N_SIGNAL(onHelpRequested, QDialogButtonBox::helpRequested)
    N_SIGNAL(onRejected     , QDialogButtonBox::rejected     )
};

N_BUILDER_IMPL(DialogButtonBoxBuilder, QDialogButtonBox, DialogButtonBox);



template <typename T>
class DialogButtonBoxRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

    N_PROPERTY(Qt::Orientation, orientation    , N_GETTER(orientation    ), N_SETTER(setOrientation    ), N_NO_NOTIFY)
    N_PROPERTY(QDialogButtonBox::StandardButtons
                              , standardButtons, N_GETTER(standardButtons), N_SETTER(setStandardButtons), N_NO_NOTIFY)
    N_PROPERTY(bool           , centerButtons  , N_GETTER(centerButtons  ), N_SETTER(setCenterButtons  ), N_NO_NOTIFY)
};

using DialogButtonBoxRef = DialogButtonBoxRefT<QDialogButtonBox>;

}

#endif // DIALOGBUTTONBOX_H
