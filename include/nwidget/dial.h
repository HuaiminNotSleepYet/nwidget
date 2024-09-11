#ifndef NWIDGET_DIAL_H
#define NWIDGET_DIAL_H

#include <QDial>

#include "abstractslider.h"

namespace nwidget {

template<typename S, typename T>
class DialBuilder : public AbstractSliderBuilder<S, T>
{
    N_BUILDER

public:
    DialBuilder()          : AbstractSliderBuilder<S, T>(new T) {}
    explicit
    DialBuilder(T* target) : AbstractSliderBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(bool , wrapping      , setWrapping      )
    N_BUILDER_PROPERTY(qreal, notchTarget   , setNotchTarget   )
    N_BUILDER_PROPERTY(bool , notchesVisible, setNotchesVisible)
};

N_DECLARE_BUILDER(Dial, DialBuilder, QDial)



template <typename T>
class DialIdT : public AbstractSliderIdT<T>
{
public:
    using AbstractSliderIdT<T>::AbstractSliderIdT;

    N_ID_PROPERTY(bool , wrapping      , N_GETTER(wrapping      ), N_SETTER(setWrapping      ), N_NO_NOTIFY)
    N_ID_PROPERTY(int  , notchSize     , N_GETTER(notchSize     ), N_NO_SETTER                , N_NO_NOTIFY)
    N_ID_PROPERTY(qreal, notchTarget   , N_GETTER(notchTarget   ), N_SETTER(setNotchTarget   ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool , notchesVisible, N_GETTER(notchesVisible), N_SETTER(setNotchesVisible), N_NO_NOTIFY)
};

N_DECLARE_ID(Dial, DialIdT, QDial)

}

#endif // NWIDGET_DIAL_H
