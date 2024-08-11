#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QProgressBar>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class ProgressBarBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    ProgressBarBuilder()                                : WidgetBuilder<S, T>(new T) {}
    explicit ProgressBarBuilder(T* target)              : WidgetBuilder<S, T>(target) {}
    ProgressBarBuilder(int min, int max, int value = 0) : WidgetBuilder<S, T>(new T) { minimum(min).maximum(max).value(value); }

    S& textVisible(bool b)                               { t->TextVisible(b);           return self(); }
    S& alignment(Qt::Alignment align)                    { t->Alignment(align);         return self(); }
    S& invertedAppearance(bool b)                        { t->InvertedAppearance(b);    return self(); }
    S& textDirection(QProgressBar::Direction direction)  { t->TextDirection(direction); return self(); }
    S& format(const QString &s)                          { t->Format(s);                return self(); }

    S& range(int min, int max)                           { t->setRange(min, max);       return self(); }
    S& minimum(int min)                                  { t->setMinimum(min);          return self(); }
    S& maximum(int max)                                  { t->setMaximum(max);          return self(); }
    S& value(int v)                                      { t->setValue(v);              return self(); }
    S& orientation(Qt::Orientation o)                    { t->setOrientation(o);        return self(); }

    N_SIGNAL(onValueChanged, QProgressBar::valueChanged)
};

N_BUILDER_IMPL(ProgressBarBuilder, QProgressBar, ProgressBar);



template<typename T>
class ProgressBarRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

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

using ProgressBarRef = ProgressBarRefT<QProgressBar>;

}

#endif // PROGRESSBAR_H
