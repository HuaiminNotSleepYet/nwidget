#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QProgressBar>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class ProgressBarBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    ProgressBarBuilder()                   : WidgetBuilder<S, T>(new T) {}
    explicit ProgressBarBuilder(T* target) : WidgetBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(int                    , minimum           , setMinimum           )
    N_BUILDER_PROPERTY(int                    , maximum           , setMaximum           )
    N_BUILDER_PROPERTY(int                    , value             , setValue             )
    N_BUILDER_PROPERTY(Qt::Alignment          , alignment         , setAlignment         )
    N_BUILDER_PROPERTY(bool                   , textVisible       , setTextVisible       )
    N_BUILDER_PROPERTY(Qt::Orientation        , orientation       , setOrientation       )
    N_BUILDER_PROPERTY(bool                   , invertedAppearance, setInvertedAppearance)
    N_BUILDER_PROPERTY(QProgressBar::Direction, textDirection     , setTextDirection     )
    N_BUILDER_PROPERTY(QString                , format            , setFormat            )

    S& range(int min, int max) { t->setRange(min, max); return self(); }

    N_SIGNAL(onValueChanged, QProgressBar::valueChanged)
};

N_BUILDER_IMPL(ProgressBarBuilder, QProgressBar, ProgressBar);



template<typename T>
class ProgressBarIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_PROPERTY(int                    , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ), N_NO_NOTIFY)
    N_PROPERTY(int                    , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ), N_NO_NOTIFY)
    N_PROPERTY(QString                , text              , N_GETTER(text              ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(int                    , value             , N_GETTER(value             ), N_SETTER(setValue             ), N_NOTIFY(valueChanged))
    N_PROPERTY(Qt::Alignment          , alignment         , N_GETTER(alignment         ), N_SETTER(setAlignment         ), N_NO_NOTIFY)
    N_PROPERTY(bool                   , textVisible       , N_GETTER(isTextVisible     ), N_SETTER(setTextVisible       ), N_NO_NOTIFY)
    N_PROPERTY(Qt::Orientation        , orientation       , N_GETTER(orientation       ), N_SETTER(setOrientation       ), N_NO_NOTIFY)
    N_PROPERTY(bool                   , invertedAppearance, N_GETTER(invertedAppearance), N_SETTER(setInvertedAppearance), N_NO_NOTIFY)
    N_PROPERTY(QProgressBar::Direction, textDirection     , N_GETTER(textDirection     ), N_SETTER(setTextDirection     ), N_NO_NOTIFY)
    N_PROPERTY(QString                , format            , N_GETTER(format            ), N_SETTER(setFormat            ), N_NO_NOTIFY)
};

using ProgressBarId = ProgressBarIdT<QProgressBar>;

}

#endif // PROGRESSBAR_H
