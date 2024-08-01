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

    inline S& textVisible(bool b)                               { t->TextVisible(b);           return self(); }
    inline S& alignment(Qt::Alignment align)                    { t->Alignment(align);         return self(); }
    inline S& invertedAppearance(bool b)                        { t->InvertedAppearance(b);    return self(); }
    inline S& textDirection(QProgressBar::Direction direction)  { t->TextDirection(direction); return self(); }
    inline S& format(const QString &s)                          { t->Format(s);                return self(); }

    inline S& range(int min, int max)                           { t->setRange(min, max);       return self(); }
    inline S& minimum(int min)                                  { t->setMinimum(min);          return self(); }
    inline S& maximum(int max)                                  { t->setMaximum(max);          return self(); }
    inline S& value(int v)                                      { t->setValue(v);              return self(); }
    inline S& orientation(Qt::Orientation o)                    { t->setOrientation(o);        return self(); }

    N_SIGNAL(onValueChanged, QProgressBar::valueChanged)
};

N_BUILDER_IMPL(ProgressBarBuilder, QProgressBar, ProgressBar);

}

#endif // PROGRESSBAR_H
