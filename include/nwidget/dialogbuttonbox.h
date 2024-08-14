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
    DialogButtonBoxBuilder()                                                   : WidgetBuilder<S, T>(new T) {}
    explicit DialogButtonBoxBuilder(Qt::Orientation orientation)               : WidgetBuilder<S, T>(new T(orientation)) {}
    explicit DialogButtonBoxBuilder(QDialogButtonBox::StandardButtons buttons) : WidgetBuilder<S, T>(new T(buttons)) {}
    DialogButtonBoxBuilder(QDialogButtonBox::StandardButtons buttons,
                           Qt::Orientation orientation)                        : WidgetBuilder<S, T>(new T(buttons, orientation)) {}

    explicit DialogButtonBoxBuilder(T* target)                                   : WidgetBuilder<S, T>(target) {}
    DialogButtonBoxBuilder(T* target, Qt::Orientation orientation)               : WidgetBuilder<S, T>(target) { t->setOrientation(orientation); }
    DialogButtonBoxBuilder(T* target, QDialogButtonBox::StandardButtons buttons) : WidgetBuilder<S, T>(target) { t->setStandardButtons(buttons); }
    DialogButtonBoxBuilder(T* target, QDialogButtonBox::StandardButtons buttons,
                                      Qt::Orientation orientation)               : WidgetBuilder<S, T>(target) { t->setOrientation(orientation);
                                                                                                                 t->setStandardButtons(buttons); }

    N_SIGNAL(onClicked      , QDialogButtonBox::clicked      )
    N_SIGNAL(onAccepted     , QDialogButtonBox::accepted     )
    N_SIGNAL(onHelpRequested, QDialogButtonBox::helpRequested)
    N_SIGNAL(onRejected     , QDialogButtonBox::rejected     )
};

N_BUILDER_IMPL(DialogButtonBoxBuilder, QDialogButtonBox, DialogButtonBox);

}

#endif // DIALOGBUTTONBOX_H
