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

    S& range(int min, int max) { t->setRange(min, max); return self(); }

    N_BUILDER_SIGNAL(onValueChanged   , valueChanged   )
    N_BUILDER_SIGNAL(onSliderPressed  , sliderPressed  )
    N_BUILDER_SIGNAL(onSliderMoved    , sliderMoved    )
    N_BUILDER_SIGNAL(onSliderReleased , sliderReleased )
    N_BUILDER_SIGNAL(onRangeChanged   , rangeChanged   )
    N_BUILDER_SIGNAL(onActionTriggered, actionTriggered)
};

N_DECL_BUILDER(AbstractSliderBuilder, QAbstractSlider, AbstractSlider);



template<typename T>
class AbstractSliderIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(int            , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ) , N_NO_NOTIFY)
    N_ID_PROPERTY(int            , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ) , N_NO_NOTIFY)
    N_ID_PROPERTY(int            , singleStep        , N_GETTER(singleStep        ), N_SETTER(setSingleStep        ) , N_NO_NOTIFY)
    N_ID_PROPERTY(int            , pageStep          , N_GETTER(pageStep          ), N_SETTER(setPageStep          ) , N_NO_NOTIFY)
    N_ID_PROPERTY(int            , value             , N_GETTER(value             ), N_SETTER(setValue             ) , N_NOTIFY(valueChanged))
    N_ID_PROPERTY(int            , sliderPosition    , N_GETTER(sliderPosition    ), N_SETTER(setSliderPosition    ) , N_NOTIFY(sliderMoved))
    N_ID_PROPERTY(bool           , tracking          , N_GETTER(hasTracking       ), N_SETTER(setTracking          ) , N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Orientation, orientation       , N_GETTER(orientation       ), N_SETTER(setOrientation       ) , N_NO_NOTIFY)
    N_ID_PROPERTY(bool           , invertedAppearance, N_GETTER(invertedAppearance), N_SETTER(setInvertedAppearance) , N_NO_NOTIFY)
    N_ID_PROPERTY(bool           , invertedControls  , N_GETTER(invertedControls  ), N_SETTER(setInvertedControls  ) , N_NO_NOTIFY)
};

using AbstractSliderId = AbstractSliderIdT<QAbstractSlider>;

}

#endif // NWIDGET_ABSTRACTSLIDER_H
