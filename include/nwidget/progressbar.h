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

    N_ID_PROPERTY(int                    , minimum           , N_READ minimum            N_WRITE setMinimum           )
    N_ID_PROPERTY(int                    , maximum           , N_READ maximum            N_WRITE setMaximum           )
    N_ID_PROPERTY(QString                , text              , N_READ text                                            )
    N_ID_PROPERTY(int                    , value             , N_READ value              N_WRITE setValue             N_NOTIFY valueChanged)
    N_ID_PROPERTY(Qt::Alignment          , alignment         , N_READ alignment          N_WRITE setAlignment         )
    N_ID_PROPERTY(bool                   , textVisible       , N_READ isTextVisible      N_WRITE setTextVisible       )
    N_ID_PROPERTY(Qt::Orientation        , orientation       , N_READ orientation        N_WRITE setOrientation       )
    N_ID_PROPERTY(bool                   , invertedAppearance, N_READ invertedAppearance N_WRITE setInvertedAppearance)
    N_ID_PROPERTY(QProgressBar::Direction, textDirection     , N_READ textDirection      N_WRITE setTextDirection     )
    N_ID_PROPERTY(QString                , format            , N_READ format             N_WRITE setFormat            )
};

N_DECLARE_ID(ProgressBar, ProgressBarIdT, QProgressBar)

}

#endif // NWIDGET_PROGRESSBAR_H
