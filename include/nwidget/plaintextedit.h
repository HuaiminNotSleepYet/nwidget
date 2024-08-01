#ifndef PLAINTEXTEDIT_H
#define PLAINTEXTEDIT_H

#include <QPlainTextEdit>

#include "abstractscrollarea.h"

namespace nw {

template<typename S, typename T>
class PlainTextEditBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractScrollAreaBuilder, S, T)

public:
    PlainTextEditBuilder()                    : AbstractScrollAreaBuilder<S, T>(new T) {}
    explicit PlainTextEditBuilder(T* target)  : AbstractScrollAreaBuilder<S, T>(target) {}
    PlainTextEditBuilder(const QString& text) : AbstractScrollAreaBuilder<S, T>(new T(text)) {}
};

N_BUILDER_IMPL(PlainTextEditBuilder, QPlainTextEdit, PlainTextEdit);

}

#endif // PLAINTEXTEDIT_H
