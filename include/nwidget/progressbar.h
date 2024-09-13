#ifndef NWIDGET_PROGRESSBAR_H
#define NWIDGET_PROGRESSBAR_H

#include <QProgressBar>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class ProgressBarBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    ProgressBarBuilder()          : WidgetBuilder<S, T>(new T) {}
    explicit
    ProgressBarBuilder(T* target) : WidgetBuilder<S, T>(target) {}

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

    N_BUILDER_SIGNAL(onValueChanged, valueChanged)
};

N_DECLARE_BUILDER(ProgressBar, ProgressBarBuilder, QProgressBar)



template<typename T>
class ProgressBarIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(int                    , minimum           , N_GETTER(minimum           ), N_SETTER(setMinimum           ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                    , maximum           , N_GETTER(maximum           ), N_SETTER(setMaximum           ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                , text              , N_GETTER(text              ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(int                    , value             , N_GETTER(value             ), N_SETTER(setValue             ), N_NOTIFY(valueChanged))
    N_ID_PROPERTY(Qt::Alignment          , alignment         , N_GETTER(alignment         ), N_SETTER(setAlignment         ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                   , textVisible       , N_GETTER(isTextVisible     ), N_SETTER(setTextVisible       ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Orientation        , orientation       , N_GETTER(orientation       ), N_SETTER(setOrientation       ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                   , invertedAppearance, N_GETTER(invertedAppearance), N_SETTER(setInvertedAppearance), N_NO_NOTIFY)
    N_ID_PROPERTY(QProgressBar::Direction, textDirection     , N_GETTER(textDirection     ), N_SETTER(setTextDirection     ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                , format            , N_GETTER(format            ), N_SETTER(setFormat            ), N_NO_NOTIFY)
};

N_DECLARE_ID(ProgressBar, ProgressBarIdT, QProgressBar)

}

#endif // NWIDGET_PROGRESSBAR_H
