#ifndef ABSTRACTSLIDER_H
#define ABSTRACTSLIDER_H

#include <QAbstractSlider>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class AbstractSliderBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    using WidgetBuilder<S, T>::WidgetBuilder;

    S& value(int v)                      { t->setValue(v);        return self(); }
    S& orientation(Qt::Orientation o)    { t->setOrientation(o);  return self(); }
    S& range(int min, int max)           { t->setRange(min, max); return self(); }

    N_SIGNAL(onValueChanged   , QAbstractSlider::valueChanged   )
    N_SIGNAL(onSliderPressed  , QAbstractSlider::sliderPressed  )
    N_SIGNAL(onSliderMoved    , QAbstractSlider::sliderMoved    )
    N_SIGNAL(onSliderReleased , QAbstractSlider::sliderReleased )
    N_SIGNAL(onRangeChanged   , QAbstractSlider::rangeChanged   )
    N_SIGNAL(onActionTriggered, QAbstractSlider::actionTriggered)
};

N_BUILDER_IMPL(AbstractSliderBuilder, QAbstractSlider, AbstractSlider);



template<typename T>
class AbstractSliderRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

    N_PROPERTY(int            , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ) , N_NO_NOTIFY)
    N_PROPERTY(int            , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ) , N_NO_NOTIFY)
    N_PROPERTY(int            , singleStep        , N_GETTER(singleStep        ), N_SETTER(setSingleStep        ) , N_NO_NOTIFY)
    N_PROPERTY(int            , pageStep          , N_GETTER(pageStep          ), N_SETTER(setPageStep          ) , N_NO_NOTIFY)
    N_PROPERTY(int            , value             , N_GETTER(value             ), N_SETTER(setValue             ) , N_NOTIFY(valueChanged))
    N_PROPERTY(int            , sliderPosition    , N_GETTER(sliderPosition    ), N_SETTER(setSliderPosition    ) , N_NOTIFY(sliderMoved))
    N_PROPERTY(bool           , tracking          , N_GETTER(hasTracking       ), N_SETTER(setTracking          ) , N_NO_NOTIFY)
    N_PROPERTY(Qt::Orientation, orientation       , N_GETTER(orientation       ), N_SETTER(setOrientation       ) , N_NO_NOTIFY)
    N_PROPERTY(bool           , invertedAppearance, N_GETTER(invertedAppearance), N_SETTER(setInvertedAppearance) , N_NO_NOTIFY)
    N_PROPERTY(bool           , invertedControls  , N_GETTER(invertedControls  ), N_SETTER(setInvertedControls  ) , N_NO_NOTIFY)
};

using AbstractSliderRef = AbstractSliderRefT<QAbstractSlider>;

}

#endif // ABSTRACTSLIDER_H
