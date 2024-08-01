#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "object.h"

namespace nw {

template<typename S, typename T>
class WidgetBuilder : public ObjectBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(ObjectBuilder, S, T)

public:
    WidgetBuilder()                           : ObjectBuilder<S, T>(new T) {}
    WidgetBuilder(QLayout* layout)            : ObjectBuilder<S, T>(new T) { t->setLayout(layout); }
    explicit WidgetBuilder(T* target)         : ObjectBuilder<S, T>(target) {}
    WidgetBuilder(T* target, QLayout* layout) : ObjectBuilder<S, T>(target) { t->setLayout(layout); }

    inline S& minimumSize(const QSize& s)   { t->setMinimumSize(s);      return self(); }
    inline S& minimumSize(int w, int h)     { t->setMinimumSize(w, h);   return self(); }
    inline S& maximumSize(const QSize& s)   { t->setMaximumSize(s);      return self(); }
    inline S& maximumSize(int w, int h)     { t->setMaximumSize(w, h);   return self(); }
    inline S& minimumWidth(int w)           { t->setMinimumWidth(w);     return self(); }
    inline S& minimumHeight(int h)          { t->setMinimumHeight(h);    return self(); }
    inline S& maximumWidth(int w)           { t->setMaximumWidth(w);     return self(); }
    inline S& maximumHeight(int h)          { t->setMaximumHeight(h);    return self(); }

    inline S& sizeIncrement(const QSize& s) { t->setSizeIncrement(s);    return self(); }
    inline S& sizeIncrement(int w, int h)   { t->setSizeIncrement(w, h); return self(); }
    inline S& baseSize(const QSize& s)      { t->setBaseSize(s);         return self(); }
    inline S& baseSize(int w, int h)        { t->setBaseSize(w, h);      return self(); }

    inline S& fixedSize(const QSize& s)     { t->setFixedSize(s);        return self(); }
    inline S& fixedSize(int w, int h)       { t->setFixedSize(w, h);     return self(); }
    inline S& fixedWidth(int w)             { t->setFixedWidth(w);       return self(); }
    inline S& fixedHeight(int h)            { t->setFixedHeight(h);      return self(); }

    inline S& layout(QLayout* l)            { t->setLayout(l);           return self(); }

    inline S& sizePolicy(QSizePolicy::Policy h, QSizePolicy::Policy v) { t->setSizePolicy(h, v); return self(); };
};

N_BUILDER_IMPL(WidgetBuilder, QWidget, Widget);

}

#endif // WIDGET_H
