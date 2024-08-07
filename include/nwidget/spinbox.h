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
    SpinBoxBuilder()                   : AbstractSpinBoxBuilder<S, T>(new T) {}
    explicit SpinBoxBuilder(T* target) : AbstractSpinBoxBuilder<S, T>(target) {}

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
    DoubleSpinBoxBuilder()                   : AbstractSpinBoxBuilder<S, T>(new T) {}
    explicit DoubleSpinBoxBuilder(T* target) : AbstractSpinBoxBuilder<S, T>(target) {}

    S& prefix(const QString &s)          { t->setPrefix(s);            return self(); }
    S& suffix(const QString &s)          { t->setSuffix(s);            return self(); }
    S& singleStep(int val)               { t->setSingleStep(val);      return self(); }
    S& minimum(int min)                  { t->setMinimum(min);         return self(); }
    S& maximum(int max)                  { t->setMaximum(max);         return self(); }
    S& range(int min, int max)           { t->setRange(min, max);      return self(); }
    S& stepType(QSpinBox::StepType type) { t->setStepType(type);       return self(); }
    S& displayIntegerBase(int base)      { t->setDisplayInteger(base); return self(); }
    S& decimals(int prec)                { t->setDecimals(prec);       return self(); }
    S& value(int val)                    { t->setValue(val);           return self(); }

    N_SIGNAL(onValueChanged, QSpinBox::valueChanged)
    N_SIGNAL(onTextChanged , QSpinBox::textChanged )
};

N_BUILDER_IMPL(DoubleSpinBoxBuilder, QDoubleSpinBox, DoubleSpinBox);

}

#endif // SPINBOX_H
