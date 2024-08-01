#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QGroupBox>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class GroupBoxBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    GroupBoxBuilder()                                      : WidgetBuilder<S, T>(new T) {};
    GroupBoxBuilder(const QString& title)                  : WidgetBuilder<S, T>(new T(title)) {};
    GroupBoxBuilder(const QString& title, QLayout* layout) : WidgetBuilder<S, T>(new T(title), layout) {}
    explicit GroupBoxBuilder(T* target)                    : WidgetBuilder<S, T>(target) {};
    GroupBoxBuilder(T* target, QLayout* layout)            : WidgetBuilder<S, T>(target, layout) {};

    inline S& title(const QString& s)   { t->setTitle(s);         return self(); }
    inline S& alignment(int align)      { t->setAlignment(align); return self(); }
    inline S& flat(bool b)              { t->setFlat(b);          return self(); }
    inline S& checkable(bool b)         { t->setCheckable(b);     return self(); }
    inline S& checked(bool b)           { t->setChecked(b);       return self(); }
};

N_BUILDER_IMPL(GroupBoxBuilder, QGroupBox, GroupBox);

}

#endif // GROUPBOX_H
