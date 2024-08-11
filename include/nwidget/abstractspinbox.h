#ifndef ABSTRACTSPINBOX_H
#define ABSTRACTSPINBOX_H

#include <QAbstractSpinBox>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class AbstractSpinBoxBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    AbstractSpinBoxBuilder()                   : WidgetBuilder<S, T>(new T) {}
    explicit AbstractSpinBoxBuilder(T* target) : WidgetBuilder<S, T>(target) {}

    N_SIGNAL(onEditingFinished, QAbstractSpinBox::editingFinished)
};

N_BUILDER_IMPL(AbstractSpinBoxBuilder, QAbstractSpinBox, AbstractSpinBox);



template<typename T>
class AbstractSpinBoxRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

    N_PROPERTY(bool                            , wrapping          , N_GETTER(wrapping             ), N_SETTER(setWrapping           ), N_NO_NOTIFY)
    N_PROPERTY(bool                            , frame             , N_GETTER(hasFrame             ), N_SETTER(setFrame              ), N_NO_NOTIFY)
    N_PROPERTY(Qt::Alignment                   , alignment         , N_GETTER(alignment            ), N_SETTER(setAlignment          ), N_NO_NOTIFY)
    N_PROPERTY(bool                            , readOnly          , N_GETTER(isReadOnly           ), N_SETTER(setReadOnly           ), N_NO_NOTIFY)
    N_PROPERTY(QAbstractSpinBox::ButtonSymbols , buttonSymbols     , N_GETTER(buttonSymbols        ), N_SETTER(setButtonSymbols      ), N_NO_NOTIFY)
    N_PROPERTY(QString                         , specialValueText  , N_GETTER(specialValueText     ), N_SETTER(setSpecialValueText   ), N_NO_NOTIFY)
    N_PROPERTY(QString                         , text              , N_GETTER(text                 ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_PROPERTY(bool                            , accelerated       , N_GETTER(isAccelerated        ), N_SETTER(setAccelerated        ), N_NO_NOTIFY)
    N_PROPERTY(QAbstractSpinBox::CorrectionMode, correctionMode    , N_GETTER(correctionMode       ), N_SETTER(setCorrectionMode     ), N_NO_NOTIFY)
    N_PROPERTY(bool                            , acceptableInput   , N_GETTER(hasAcceptableInput   ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_PROPERTY(bool                            , keyboardTracking  , N_GETTER(keyboardTracking     ), N_SETTER(setKeyboardTracking   ), N_NO_NOTIFY)
    N_PROPERTY(bool                            , showGroupSeparator, N_GETTER(isGroupSeparatorShown), N_SETTER(setGroupSeparatorShown), N_NO_NOTIFY)
};

using AbstractSpinBoxRef = AbstractSpinBoxRefT<QAbstractSpinBox>;

}

#endif // ABSTRACTSPINBOX_H
