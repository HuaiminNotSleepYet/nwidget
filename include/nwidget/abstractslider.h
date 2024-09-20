#ifndef NWIDGET_ABSTRACTSLIDER_H
#define NWIDGET_ABSTRACTSLIDER_H

#include <QAbstractSlider>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class AbstractSliderBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    AbstractSliderBuilder()          : WidgetBuilder<S, T>(new T) {}
    explicit
    AbstractSliderBuilder(T* target) : WidgetBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(int            , minimum           , setMinimum           )
    N_BUILDER_PROPERTY(int            , maximum           , setMaximum           )
    N_BUILDER_PROPERTY(int            , singleStep        , setSingleStep        )
    N_BUILDER_PROPERTY(int            , pageStep          , setPageStep          )
    N_BUILDER_PROPERTY(int            , value             , setValue             )
    N_BUILDER_PROPERTY(int            , sliderPosition    , setSliderPosition    )
    N_BUILDER_PROPERTY(bool           , tracking          , setTracking          )
    N_BUILDER_PROPERTY(Qt::Orientation, orientation       , setOrientation       )
    N_BUILDER_PROPERTY(bool           , invertedAppearance, setInvertedAppearance)
    N_BUILDER_PROPERTY(bool           , invertedControls  , setInvertedControls  )

    N_BUILDER_SETTER2(range, setRange)

    N_BUILDER_SIGNAL(onValueChanged   , valueChanged   )
    N_BUILDER_SIGNAL(onSliderPressed  , sliderPressed  )
    N_BUILDER_SIGNAL(onSliderMoved    , sliderMoved    )
    N_BUILDER_SIGNAL(onSliderReleased , sliderReleased )
    N_BUILDER_SIGNAL(onRangeChanged   , rangeChanged   )
    N_BUILDER_SIGNAL(onActionTriggered, actionTriggered)
};

N_DECLARE_BUILDER(AbstractSlider, AbstractSliderBuilder, QAbstractSlider)



template<typename T>
class AbstractSliderIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(int            , minimum           , N_READ minimum            N_WRITE setMinimum           )
    N_ID_PROPERTY(int            , maximum           , N_READ maximum            N_WRITE setMaximum           )
    N_ID_PROPERTY(int            , singleStep        , N_READ singleStep         N_WRITE setSingleStep        )
    N_ID_PROPERTY(int            , pageStep          , N_READ pageStep           N_WRITE setPageStep          )
    N_ID_PROPERTY(int            , value             , N_READ value              N_WRITE setValue             N_NOTIFY valueChanged)
    N_ID_PROPERTY(int            , sliderPosition    , N_READ sliderPosition     N_WRITE setSliderPosition    N_NOTIFY sliderMoved)
    N_ID_PROPERTY(bool           , tracking          , N_READ hasTracking        N_WRITE setTracking          )
    N_ID_PROPERTY(Qt::Orientation, orientation       , N_READ orientation        N_WRITE setOrientation       )
    N_ID_PROPERTY(bool           , invertedAppearance, N_READ invertedAppearance N_WRITE setInvertedAppearance)
    N_ID_PROPERTY(bool           , invertedControls  , N_READ invertedControls   N_WRITE setInvertedControls  )
};

N_DECLARE_ID(AbstractSlider, AbstractSliderIdT, QAbstractSlider)

}

N_REGISTER_ID(nwidget::AbstractSlider, QAbstractSlider)
N_REGISTER_BUILDER(nwidget::AbstractSlider, QAbstractSlider)

#endif // NWIDGET_ABSTRACTSLIDER_H
