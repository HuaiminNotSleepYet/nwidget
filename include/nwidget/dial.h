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

    S& notchTarget(double d)  { t->setNotchTarget();     return self(); }

    S& notchesVisible(bool b) { t->setNotchesVisible(b); return self(); }
    S& wrapping(bool b)       { t->setWrapping(b);       return self(); };
};

N_BUILDER_IMPL(DialBuilder, QDial, Dial);



template <typename T>
class DialIdT : public AbstractSliderIdT<T>
{
public:
    using AbstractSliderIdT<T>::AbstractSliderIdT;

    N_PROPERTY(bool , wrapping      , N_GETTER(wrapping      ), N_SETTER(setWrapping      ), N_NO_NOTIFY)
    N_PROPERTY(int  , notchSize     , N_GETTER(notchSize     ), N_NO_SETTER                , N_NO_NOTIFY)
    N_PROPERTY(qreal, notchTarget   , N_GETTER(notchTarget   ), N_SETTER(setNotchTarget   ), N_NO_NOTIFY)
    N_PROPERTY(bool , notchesVisible, N_GETTER(notchesVisible), N_SETTER(setNotchesVisible), N_NO_NOTIFY)
};

using DialId = DialIdT<QDial>;

}

#endif // DIAL_H
