#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

#include "frame.h"

namespace nw {

template<typename S, typename T>
class LabelBuilder : public FrameBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(FrameBuilder, S, T)

public:
    LabelBuilder()                    : FrameBuilder<S, T>(new T) {}
    explicit LabelBuilder(T* target)  : FrameBuilder<S, T>(target) {}
    LabelBuilder(const QString& text) : FrameBuilder<S, T>(new T(text)) {}

    S& alignment(Qt::Alignment align) { t->setAlignment(align); return self(); }
};

N_BUILDER_IMPL(LabelBuilder, QLabel, Label);

}

#endif // LABEL_H
