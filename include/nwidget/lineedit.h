#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

#include "widget.h"

namespace nw {

template<typename S, typename T>
class LineEditBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    LineEditBuilder()                       : WidgetBuilder<S, T>(new T) {}
    explicit LineEditBuilder(T* target)     : WidgetBuilder<S, T>(target) {}
    LineEditBuilder(const QString& content) : WidgetBuilder<S, T>(new T(content)) {}

    S& placeholderText(const QString& s)          { t->setPlaceHolderText(s);            return self(); }
    S& maxLength(int len)                         { t->setMaxLength(len);                return self(); }
    S& frame(bool b)                              { t->setFrame(b);                      return self(); }
    S& clearButtonEnabled(bool b)                 { t->setClearButtonEnabled(b);         return self(); }
    S& echoMode(QLineEdit::EchoMode mode)         { t->setEchoMode(mode);                return self(); }
    S& readOnly(bool b)                           { t->setReadOnly(b);                   return self(); }

#ifndef QT_NO_VALIDATOR
    S& validator(const QValidator* v)             { t->setValidator(v);                  return self(); }
#endif

#if QT_CONFIG(completer)
    S& completer(const QCompleter* c)             { t->setCompleter(c);                  return self(); }
#endif

    S& cursorPosition(int pos)                    { t->setCursorPosition(pos);           return self(); }
    S& alignment(Qt::Alignment align)             { t->setAlignment(align);              return self(); }
    S& modified(bool b)                           { t->setModified(b);                   return self(); }
    S& selection(int begin, int end)              { t->setSelection(begin, end);         return self(); }
    S& dragEnabled(bool b)                        { t->setDragEnabled(b);                return self(); }
    S& cursorMoveStyle(Qt::CursorMoveStyle style) { t->setCursorMoveStyle(style);        return self(); }
    S& inputMask(const QString& mask)             { t->setInputMask(mask);               return self(); }
    S& textMargins(int l, int t, int r, int b)    { this->t->setTextMargins(l, t, r, b); return self(); }
    S& textMargins(const QMargins& margin)        { this->t->setTextMargins(margin);     return self(); }

    S& text(const QString& s)                     { t->setText(s);                       return self(); }

    N_SIGNAL(onTextChanged          , QLineEdit::textChanged          )
    N_SIGNAL(onTextEdited           , QLineEdit::textEdited           )
    N_SIGNAL(onCursorPositionChanged, QLineEdit::cursorPositionChanged)
    N_SIGNAL(onReturnPressed        , QLineEdit::returnPressed        )
    N_SIGNAL(onEditingFinished      , QLineEdit::editingFinished      )
    N_SIGNAL(onSelectionChanged     , QLineEdit::selectionChanged     )
    N_SIGNAL(onInputRejected        , QLineEdit::inputRejected        )
};

N_BUILDER_IMPL(LineEditBuilder, QLineEdit, LineEdit);

}

#endif // LINEEDIT_H
