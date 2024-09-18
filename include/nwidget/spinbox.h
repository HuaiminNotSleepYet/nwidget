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

    N_BUILDER_SETTER2(range, setRange)

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

    N_BUILDER_SETTER2(range, setRange)

    N_BUILDER_SIGNAL(onValueChanged, valueChanged)
    N_BUILDER_SIGNAL(onTextChanged , textChanged )
};

N_DECLARE_BUILDER(DoubleSpinBox, DoubleSpinBoxBuilder, QDoubleSpinBox)



template<typename T>
class SpinBoxIdT : public AbstractSpinBoxIdT<T>
{
public:
    using AbstractSpinBoxIdT<T>::AbstractSpinBoxIdT;

    N_ID_PROPERTY(QString           , suffix            , N_READ suffix             N_WRITE setSuffix    )
    N_ID_PROPERTY(QString           , prefix            , N_READ prefix             N_WRITE setPrefix    )
    N_ID_PROPERTY(QString           , cleanText         , N_READ cleanText                               )
    N_ID_PROPERTY(int               , minimum           , N_READ minimum            N_WRITE setMinimum   )
    N_ID_PROPERTY(int               , maximum           , N_READ maximum            N_WRITE setMaximum   )
    N_ID_PROPERTY(int               , singleStep        , N_READ singleStep         N_WRITE setSingleStep)
    N_ID_PROPERTY(QSpinBox::StepType, stepType          , N_READ stepType           N_WRITE setStepType  )
    N_ID_PROPERTY(int               , value             , N_READ value              N_WRITE setValue     N_NOTIFY valueChanged)
    N_ID_PROPERTY(int               , displayIntegerBase, N_READ displayIntegerBase N_WRITE setDisplayIntegerBase)
};

template<typename T>
class DoubleSpinBoxIdT : public AbstractSpinBoxIdT<T>
{
public:
    using AbstractSpinBoxIdT<T>::AbstractSpinBoxIdT;

    N_ID_PROPERTY(QString           , suffix            , N_READ suffix     N_WRITE setSuffix    )
    N_ID_PROPERTY(QString           , prefix            , N_READ prefix     N_WRITE setPrefix    )
    N_ID_PROPERTY(QString           , cleanText         , N_READ cleanText                       )
    N_ID_PROPERTY(int               , decimals          , N_READ decimals   N_WRITE setDecimals  )
    N_ID_PROPERTY(double            , minimum           , N_READ minimum    N_WRITE setMinimum   )
    N_ID_PROPERTY(double            , maximum           , N_READ maximum    N_WRITE setMaximum   )
    N_ID_PROPERTY(double            , singleStep        , N_READ singleStep N_WRITE setSingleStep)
    N_ID_PROPERTY(QSpinBox::StepType, stepType          , N_READ stepType   N_WRITE setStepType  )
    N_ID_PROPERTY(double            , value             , N_READ value      N_WRITE setValue     N_NOTIFY valueChanged)
};
N_DECLARE_ID(SpinBox, SpinBoxIdT, QSpinBox)
N_DECLARE_ID(DoubleSpinBox, DoubleSpinBoxIdT, QDoubleSpinBox)

}

#endif // NWIDGET_SPINBOX_H
