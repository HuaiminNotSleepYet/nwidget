#ifndef DIAL_H
#define DIAL_H

#include <QDial>

#include "abstractslider.h"

namespace nw {

template<typename S, typename T>
class DialBuilder : public AbstractSliderBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractSliderBuilder, S, T)

public:
    DialBuilder()                   : AbstractSliderBuilder<S, T>(new T) {}
    explicit DialBuilder(T* target) : AbstractSliderBuilder<S, T>(target) {}

    inline S& notchTarget(double d)     { t->setNotchTarget();     return self(); }

    inline S& notchesVisible(bool b)    { t->setNotchesVisible(b); return self(); }
    inline S& wrapping(bool b)          { t->setWrapping(b);       return self(); };
};

N_BUILDER_IMPL(DialBuilder, QDial, Dial);

}

#endif // DIAL_H
