#ifndef ABSTRACTSPINBOX_H
#define ABSTRACTSPINBOX_H

#include <QAbstractSpinBox>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class AbstractSpinBoxBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    AbstractSpinBoxBuilder()                   : WidgetBuilder<S, T>(new T) {}
    explicit AbstractSpinBoxBuilder(T* target) : WidgetBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(bool                            , wrapping          , setWrapping           )
    N_BUILDER_PROPERTY(bool                            , frame             , setFrame              )
    N_BUILDER_PROPERTY(Qt::Alignment                   , alignment         , setAlignment          )
    N_BUILDER_PROPERTY(bool                            , readOnly          , setReadOnly           )
    N_BUILDER_PROPERTY(QAbstractSpinBox::ButtonSymbols , buttonSymbols     , setButtonSymbols      )
    N_BUILDER_PROPERTY(QString                         , specialValueText  , setSpecialValueText   )
    N_BUILDER_PROPERTY(bool                            , accelerated       , setAccelerated        )
    N_BUILDER_PROPERTY(QAbstractSpinBox::CorrectionMode, correctionMode    , setCorrectionMode     )
    N_BUILDER_PROPERTY(bool                            , keyboardTracking  , setKeyboardTracking   )
    N_BUILDER_PROPERTY(bool                            , showGroupSeparator, setGroupSeparatorShown)

    S& groupSeparatorShown(bool shown) { t->setGroupSeparatorShown(shown); return self(); }
    S& lineEdit(QLineEdit *edit)       { t->setLineEdit(edit)            ; return self(); }

    N_BUILDER_SIGNAL(onEditingFinished, editingFinished)
};

N_DECL_BUILDER(AbstractSpinBoxBuilder, QAbstractSpinBox, AbstractSpinBox);



template<typename T>
class AbstractSpinBoxIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool                            , wrapping          , N_GETTER(wrapping             ), N_SETTER(setWrapping           ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                            , frame             , N_GETTER(hasFrame             ), N_SETTER(setFrame              ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Alignment                   , alignment         , N_GETTER(alignment            ), N_SETTER(setAlignment          ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                            , readOnly          , N_GETTER(isReadOnly           ), N_SETTER(setReadOnly           ), N_NO_NOTIFY)
    N_ID_PROPERTY(QAbstractSpinBox::ButtonSymbols , buttonSymbols     , N_GETTER(buttonSymbols        ), N_SETTER(setButtonSymbols      ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                         , specialValueText  , N_GETTER(specialValueText     ), N_SETTER(setSpecialValueText   ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                         , text              , N_GETTER(text                 ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_ID_PROPERTY(bool                            , accelerated       , N_GETTER(isAccelerated        ), N_SETTER(setAccelerated        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QAbstractSpinBox::CorrectionMode, correctionMode    , N_GETTER(correctionMode       ), N_SETTER(setCorrectionMode     ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                            , acceptableInput   , N_GETTER(hasAcceptableInput   ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_ID_PROPERTY(bool                            , keyboardTracking  , N_GETTER(keyboardTracking     ), N_SETTER(setKeyboardTracking   ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                            , showGroupSeparator, N_GETTER(isGroupSeparatorShown), N_SETTER(setGroupSeparatorShown), N_NO_NOTIFY)
};

using AbstractSpinBoxId = AbstractSpinBoxIdT<QAbstractSpinBox>;

}

#endif // ABSTRACTSPINBOX_H
