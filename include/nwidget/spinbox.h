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

    inline S& prefix(const QString &s)          { t->setPrefix(s);            return self(); }
    inline S& suffix(const QString &s)          { t->setSuffix(s);            return self(); }
    inline S& singleStep(int val)               { t->setSingleStep(val);      return self(); }
    inline S& minimum(int min)                  { t->setMinimum(min);         return self(); }
    inline S& maximum(int max)                  { t->setMaximum(max);         return self(); }
    inline S& range(int min, int max)           { t->setRange(min, max);      return self(); }
    inline S& stepType(QSpinBox::StepType type) { t->setStepType(type);       return self(); }
    inline S& displayIntegerBase(int base)      { t->setDisplayInteger(base); return self(); }
    inline S& value(int val)                    { t->setValue(val);           return self(); }

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

    inline S& prefix(const QString &s)          { t->setPrefix(s);            return self(); }
    inline S& suffix(const QString &s)          { t->setSuffix(s);            return self(); }
    inline S& singleStep(int val)               { t->setSingleStep(val);      return self(); }
    inline S& minimum(int min)                  { t->setMinimum(min);         return self(); }
    inline S& maximum(int max)                  { t->setMaximum(max);         return self(); }
    inline S& range(int min, int max)           { t->setRange(min, max);      return self(); }
    inline S& stepType(QSpinBox::StepType type) { t->setStepType(type);       return self(); }
    inline S& displayIntegerBase(int base)      { t->setDisplayInteger(base); return self(); }
    inline S& decimals(int prec)                { t->setDecimals(prec);       return self(); }
    inline S& value(int val)                    { t->setValue(val);           return self(); }

    N_SIGNAL(onValueChanged, QSpinBox::valueChanged)
    N_SIGNAL(onTextChanged , QSpinBox::textChanged )
};

N_BUILDER_IMPL(DoubleSpinBoxBuilder, QDoubleSpinBox, DoubleSpinBox);

}

#endif // SPINBOX_H
