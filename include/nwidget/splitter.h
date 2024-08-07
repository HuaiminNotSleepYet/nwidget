#ifndef SPLITTER_H
#define SPLITTER_H

#include <QSplitter>

#include "frame.h"

namespace nw {

template<typename S, typename T>
class SplitterBuilder : public FrameBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(FrameBuilder, S, T)

public:
    SplitterBuilder()                                      : FrameBuilder<S, T>(new T) {}
    explicit SplitterBuilder(T* target)                    : FrameBuilder<S, T>(target) {}
    SplitterBuilder(std::initializer_list<Widget> widgets) : FrameBuilder<S, T>(new T) { applyWidgets(widgets); }

    S& orientation(Qt::Orientation o) { t->setOrientation(o); return self(); }

private:
    void applyWidgets(std::initializer_list<Widget> widgets)
    {
        auto end = widgets.end();
        for (auto i = widgets.begin(); i != end; ++i)
            t->addWidget(*i);
    }
};

N_BUILDER_IMPL(SplitterBuilder, QSplitter, Splitter);

}


#endif // SPLITTER_H
