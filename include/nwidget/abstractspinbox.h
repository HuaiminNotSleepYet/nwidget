#ifndef NWIDGET_ABSTRACTSPINBOX_H
#define NWIDGET_ABSTRACTSPINBOX_H

#include <QAbstractSpinBox>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class AbstractSpinBoxBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    AbstractSpinBoxBuilder()          : WidgetBuilder<S, T>(new T) {}
    explicit
    AbstractSpinBoxBuilder(T* target) : WidgetBuilder<S, T>(target) {}

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

    N_BUILDER_SETTER1(groupSeparatorShown, setGroupSeparatorShown)

    N_BUILDER_SIGNAL(onEditingFinished, editingFinished)
};

N_DECLARE_BUILDER(AbstractSpinBox, AbstractSpinBoxBuilder, QAbstractSpinBox);



template<typename T>
class AbstractSpinBoxIdT : public WidgetIdT<T>
{
    using ButtonSymbols = QAbstractSpinBox::ButtonSymbols;
    using CorrectionMode = QAbstractSpinBox::CorrectionMode;

public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool          , wrapping          , N_READ wrapping              N_WRITE setWrapping           )
    N_ID_PROPERTY(bool          , frame             , N_READ hasFrame              N_WRITE setFrame              )
    N_ID_PROPERTY(Qt::Alignment , alignment         , N_READ alignment             N_WRITE setAlignment          )
    N_ID_PROPERTY(bool          , readOnly          , N_READ isReadOnly            N_WRITE setReadOnly           )
    N_ID_PROPERTY(ButtonSymbols , buttonSymbols     , N_READ buttonSymbols         N_WRITE setButtonSymbols      )
    N_ID_PROPERTY(QString       , specialValueText  , N_READ specialValueText      N_WRITE setSpecialValueText   )
    N_ID_PROPERTY(QString       , text              , N_READ text                                                )
    N_ID_PROPERTY(bool          , accelerated       , N_READ isAccelerated         N_WRITE setAccelerated        )
    N_ID_PROPERTY(CorrectionMode, correctionMode    , N_READ correctionMode        N_WRITE setCorrectionMode     )
    N_ID_PROPERTY(bool          , acceptableInput   , N_READ hasAcceptableInput                                  )
    N_ID_PROPERTY(bool          , keyboardTracking  , N_READ keyboardTracking      N_WRITE setKeyboardTracking   )
    N_ID_PROPERTY(bool          , showGroupSeparator, N_READ isGroupSeparatorShown N_WRITE setGroupSeparatorShown)
};

N_DECLARE_ID(AbstractSpinBox, AbstractSpinBoxIdT, QAbstractSpinBox)

}

#endif // NWIDGET_ABSTRACTSPINBOX_H
