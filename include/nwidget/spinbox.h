#ifndef NWIDGET_SPINBOX_H
#define NWIDGET_SPINBOX_H

#include <QSpinBox>

#include "abstractspinbox.h"

namespace nwidget {

template<typename S, typename T>
class SpinBoxBuilder : public AbstractSpinBoxBuilder<S, T>
{
    N_BUILDER

public:
    using AbstractSpinBoxBuilder<S, T>::AbstractSpinBoxBuilder;

    N_BUILDER_PROPERTY(QString           , suffix            , setSuffix            )
    N_BUILDER_PROPERTY(QString           , prefix            , setPrefix            )
    N_BUILDER_PROPERTY(int               , minimum           , setMinimum           )
    N_BUILDER_PROPERTY(int               , maximum           , setMaximum           )
    N_BUILDER_PROPERTY(int               , singleStep        , setSingleStep        )
    N_BUILDER_PROPERTY(QSpinBox::StepType, stepType          , setStepType          )
    N_BUILDER_PROPERTY(int               , value             , setValue             )
    N_BUILDER_PROPERTY(int               , displayIntegerBase, setDisplayIntegerBase)

    S& range(int min, int max) { t->setRange(min, max); return self(); }

    N_BUILDER_SIGNAL(onValueChanged, valueChanged)
    N_BUILDER_SIGNAL(onTextChanged , textChanged )
};

N_DECLARE_BUILDER(SpinBox, SpinBoxBuilder, QSpinBox);

template<typename S, typename T>
class DoubleSpinBoxBuilder : public AbstractSpinBoxBuilder<S, T>
{
    N_BUILDER

public:
    using AbstractSpinBoxBuilder<S, T>::AbstractSpinBoxBuilder;

    N_BUILDER_PROPERTY(QString           , suffix    ,  setSuffix    )
    N_BUILDER_PROPERTY(QString           , prefix    ,  setPrefix    )
    N_BUILDER_PROPERTY(int               , decimals  ,  setDecimals  )
    N_BUILDER_PROPERTY(double            , minimum   ,  setMinimum   )
    N_BUILDER_PROPERTY(double            , maximum   ,  setMaximum   )
    N_BUILDER_PROPERTY(double            , singleStep,  setSingleStep)
    N_BUILDER_PROPERTY(QSpinBox::StepType, stepType  ,  setStepType  )
    N_BUILDER_PROPERTY(double            , value     ,  setValue     )

    S& range(double min, double max) { t->setRange(min, max); return self(); }

    N_BUILDER_SIGNAL(onValueChanged, valueChanged)
    N_BUILDER_SIGNAL(onTextChanged , textChanged )
};

N_DECLARE_BUILDER(DoubleSpinBox, DoubleSpinBoxBuilder, QDoubleSpinBox)



template<typename T>
class SpinBoxIdT : public AbstractSpinBoxIdT<T>
{
public:
    using AbstractSpinBoxIdT<T>::AbstractSpinBoxIdT;

    N_ID_PROPERTY(QString           , suffix            , N_GETTER(suffix            ), N_SETTER(setSuffix            ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString           , prefix            , N_GETTER(prefix            ), N_SETTER(setPrefix            ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString           , cleanText         , N_GETTER(cleanText         ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(int               , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ), N_NO_NOTIFY)
    N_ID_PROPERTY(int               , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ), N_NO_NOTIFY)
    N_ID_PROPERTY(int               , singleStep        , N_GETTER(singleStep        ), N_SETTER(setSingleStep        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSpinBox::StepType, stepType          , N_GETTER(stepType          ), N_SETTER(setStepType          ), N_NO_NOTIFY)
    N_ID_PROPERTY(int               , value             , N_GETTER(value             ), N_SETTER(setValue             ), N_NOTIFY(valueChanged))
    N_ID_PROPERTY(int               , displayIntegerBase, N_GETTER(displayIntegerBase), N_SETTER(setDisplayIntegerBase), N_NO_NOTIFY)
};

template<typename T>
class DoubleSpinBoxIdT : public AbstractSpinBoxIdT<T>
{
public:
    using AbstractSpinBoxIdT<T>::AbstractSpinBoxIdT;

    N_ID_PROPERTY(QString           , suffix            , N_GETTER(suffix            ), N_SETTER(setSuffix            ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString           , prefix            , N_GETTER(prefix            ), N_SETTER(setPrefix            ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString           , cleanText         , N_GETTER(cleanText         ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(int               , decimals          , N_GETTER(decimals          ), N_SETTER(setDecimals          ), N_NO_NOTIFY)
    N_ID_PROPERTY(double            , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ), N_NO_NOTIFY)
    N_ID_PROPERTY(double            , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ), N_NO_NOTIFY)
    N_ID_PROPERTY(double            , singleStep        , N_GETTER(singleStep        ), N_SETTER(setSingleStep        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSpinBox::StepType, stepType          , N_GETTER(stepType          ), N_SETTER(setStepType          ), N_NO_NOTIFY)
    N_ID_PROPERTY(double            , value             , N_GETTER(value             ), N_SETTER(setValue             ), N_NOTIFY(valueChanged))
};

N_DECLARE_ID(SpinBox, SpinBoxIdT, QSpinBox)
N_DECLARE_ID(DoubleSpinBox, DoubleSpinBoxIdT, QDoubleSpinBox)

}

#endif // NWIDGET_SPINBOX_H
