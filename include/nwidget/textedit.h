#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

#include "abstractscrollarea.h"

namespace nw {

template<typename S, typename T>
class TextEditBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractScrollAreaBuilder, S, T)

public:
    TextEditBuilder()                    : AbstractScrollAreaBuilder<S, T>(new T) {}
    TextEditBuilder(const QString& text) : AbstractScrollAreaBuilder<S, T>(new T(text)) {}
    explicit TextEditBuilder(T* target)  : AbstractScrollAreaBuilder<S, T>(target) {}
    TextEditBuilder(T* target, const QString& text) : AbstractScrollAreaBuilder<S, T>(target) { t->setPlainText(text); }

    N_SIGNAL(onTextChanged             , QTextEdit::textChanged             )
    N_SIGNAL(onUndoAvailable           , QTextEdit::undoAvailable           )
    N_SIGNAL(onRedoAvailable           , QTextEdit::redoAvailable           )
    N_SIGNAL(onCurrentCharFormatChanged, QTextEdit::currentCharFormatChanged)
    N_SIGNAL(onCopyAvailable           , QTextEdit::copyAvailable           )
    N_SIGNAL(onSelectionChanged        , QTextEdit::selectionChanged        )
    N_SIGNAL(onCursorPositionChanged   , QTextEdit::cursorPositionChanged   )
};

N_BUILDER_IMPL(TextEditBuilder, QTextEdit, TextEdit);

}

#endif // TEXTEDIT_H
