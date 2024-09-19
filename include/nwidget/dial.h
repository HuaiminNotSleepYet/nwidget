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

N_DECLARE_BUILDER_N(Dial, DialBuilder, QDial)



template <typename T>
class DialIdT : public AbstractSliderIdT<T>
{
public:
    using AbstractSliderIdT<T>::AbstractSliderIdT;

    N_ID_PROPERTY(bool , wrapping      , N_READ wrapping       N_WRITE setWrapping      )
    N_ID_PROPERTY(int  , notchSize     , N_READ notchSize                               )
    N_ID_PROPERTY(qreal, notchTarget   , N_READ notchTarget    N_WRITE setNotchTarget   )
    N_ID_PROPERTY(bool , notchesVisible, N_READ notchesVisible N_WRITE setNotchesVisible)
};

N_DECLARE_ID_N(Dial, DialIdT, QDial)

}

#endif // NWIDGET_DIAL_H
