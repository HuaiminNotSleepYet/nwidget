#ifndef SPINBOX_H
#define SPINBOX_H

#include <QSpinBox>

#include "abstractspinbox.h"

namespace nw {

template<typename S, typename T>
class SpinBoxBuilder : public AbstractSpinBoxBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractSpinBoxBuilder, S, T)

public:
    using AbstractSpinBoxBuilder<S, T>::AbstractSpinBoxBuilder;

    S& prefix(const QString &s)          { t->setPrefix(s);            return self(); }
    S& suffix(const QString &s)          { t->setSuffix(s);            return self(); }
    S& singleStep(int val)               { t->setSingleStep(val);      return self(); }
    S& minimum(int min)                  { t->setMinimum(min);         return self(); }
    S& maximum(int max)                  { t->setMaximum(max);         return self(); }
    S& range(int min, int max)           { t->setRange(min, max);      return self(); }
    S& stepType(QSpinBox::StepType type) { t->setStepType(type);       return self(); }
    S& displayIntegerBase(int base)      { t->setDisplayInteger(base); return self(); }
    S& value(int val)                    { t->setValue(val);           return self(); }

    N_SIGNAL(onValueChanged, QSpinBox::valueChanged)
    N_SIGNAL(onTextChanged , QSpinBox::textChanged )
};

N_BUILDER_IMPL(SpinBoxBuilder, QSpinBox, SpinBox);

template<typename S, typename T>
class DoubleSpinBoxBuilder : public AbstractSpinBoxBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractSpinBoxBuilder, S, T)

public:
    using AbstractSpinBoxBuilder<S, T>::AbstractSpinBoxBuilder;

    S& prefix(const QString &s)          { t->setPrefix(s);            return self(); }
    S& suffix(const QString &s)          { t->setSuffix(s);            return self(); }
    S& singleStep(double val)            { t->setSingleStep(val);      return self(); }
    S& minimum(double min)               { t->setMinimum(min);         return self(); }
    S& maximum(double max)               { t->setMaximum(max);         return self(); }
    S& range(double min, double max)     { t->setRange(min, max);      return self(); }
    S& stepType(QSpinBox::StepType type) { t->setStepType(type);       return self(); }
    S& decimals(int prec)                { t->setDecimals(prec);       return self(); }
    S& value(double val)                 { t->setValue(val);           return self(); }

    N_SIGNAL(onValueChanged, QDoubleSpinBox::valueChanged)
    N_SIGNAL(onTextChanged , QDoubleSpinBox::textChanged )
};

N_BUILDER_IMPL(DoubleSpinBoxBuilder, QDoubleSpinBox, DoubleSpinBox);



template<typename T>
class SpinBoxRefT : public AbstractSpinBoxRefT<T>
{
public:
    using AbstractSpinBoxRefT<T>::AbstractSpinBoxRefT;

    N_PROPERTY(QString           , suffix            , N_GETTER(suffix            ), N_SETTER(setSuffix            ), N_NO_NOTIFY)
    N_PROPERTY(QString           , prefix            , N_GETTER(prefix            ), N_SETTER(setPrefix            ), N_NO_NOTIFY)
    N_PROPERTY(QString           , cleanText         , N_GETTER(cleanText         ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(int               , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ), N_NO_NOTIFY)
    N_PROPERTY(int               , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ), N_NO_NOTIFY)
    N_PROPERTY(int               , singleStep        , N_GETTER(singleStep        ), N_SETTER(setSingleStep        ), N_NO_NOTIFY)
    N_PROPERTY(QSpinBox::StepType, stepType          , N_GETTER(stepType          ), N_SETTER(setStepType          ), N_NO_NOTIFY)
    N_PROPERTY(int               , value             , N_GETTER(value             ), N_SETTER(setValue             ), N_NOTIFY(valueChanged))
    N_PROPERTY(int               , displayIntegerBase, N_GETTER(displayIntegerBase), N_SETTER(setDisplayIntegerBase), N_NO_NOTIFY)
};

using SpinBoxRef = SpinBoxRefT<QSpinBox>;

template<typename T>
class DoubleSpinBoxRefT : public AbstractSpinBoxRefT<T>
{
public:
    using AbstractSpinBoxRefT<T>::AbstractSpinBoxRefT;

    N_PROPERTY(QString           , suffix            , N_GETTER(suffix            ), N_SETTER(setSuffix            ), N_NO_NOTIFY)
    N_PROPERTY(QString           , prefix            , N_GETTER(prefix            ), N_SETTER(setPrefix            ), N_NO_NOTIFY)
    N_PROPERTY(QString           , cleanText         , N_GETTER(cleanText         ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(int               , decimals          , N_GETTER(decimals          ), N_SETTER(setDecimals          ), N_NO_NOTIFY)
    N_PROPERTY(double            , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ), N_NO_NOTIFY)
    N_PROPERTY(double            , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ), N_NO_NOTIFY)
    N_PROPERTY(double            , singleStep        , N_GETTER(singleStep        ), N_SETTER(setSingleStep        ), N_NO_NOTIFY)
    N_PROPERTY(QSpinBox::StepType, stepType          , N_GETTER(stepType          ), N_SETTER(setStepType          ), N_NO_NOTIFY)
    N_PROPERTY(double            , value             , N_GETTER(value             ), N_SETTER(setValue             ), N_NOTIFY(valueChanged))
};

using DoubleSpinBoxRef = DoubleSpinBoxRefT<QDoubleSpinBox>;

}

#endif // SPINBOX_H
