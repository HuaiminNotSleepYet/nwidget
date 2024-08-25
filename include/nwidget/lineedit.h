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
    LineEditBuilder()                    : WidgetBuilder<S, T>(new T) {}
    LineEditBuilder(const QString& text) : WidgetBuilder<S, T>(new T(text)) {}

    explicit LineEditBuilder(T* target)             : WidgetBuilder<S, T>(target) {}
    LineEditBuilder(T* target, const QString& text) : WidgetBuilder<S, T>(target) { t->setText(text); }

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



template<typename T>
class LineEditIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_PROPERTY(QString            , inputMask         , N_GETTER(inputMask           ), N_SETTER(setInputMask         ), N_NO_NOTIFY)
    N_PROPERTY(QString            , text              , N_GETTER(text                ), N_SETTER(setText              ), N_NOTIFY(textChanged))
    N_PROPERTY(int                , maxLength         , N_GETTER(maxLength           ), N_SETTER(setMaxLength         ), N_NO_NOTIFY)
    N_PROPERTY(bool               , frame             , N_GETTER(hasFrame            ), N_SETTER(setFrame             ), N_NO_NOTIFY)
    N_PROPERTY(QLineEdit::EchoMode, echoMode          , N_GETTER(echoMode            ), N_SETTER(setEchoMode          ), N_NO_NOTIFY)
    N_PROPERTY(QString            , displayText       , N_GETTER(displayText         ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(int                , cursorPosition    , N_GETTER(cursorPosition      ), N_SETTER(setCursorPosition    ), N_NO_NOTIFY)
    N_PROPERTY(Qt::Alignment      , alignment         , N_GETTER(alignment           ), N_SETTER(setAlignment         ), N_NO_NOTIFY)
    N_PROPERTY(bool               , modified          , N_GETTER(isModified          ), N_SETTER(setModified          ), N_NO_NOTIFY)
    N_PROPERTY(bool               , hasSelectedText   , N_GETTER(hasSelectedText     ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(QString            , selectedText      , N_GETTER(selectedText        ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(bool               , dragEnabled       , N_GETTER(dragEnabled         ), N_SETTER(setDragEnabled       ), N_NO_NOTIFY)
    N_PROPERTY(bool               , readOnly          , N_GETTER(isReadOnly          ), N_SETTER(setReadOnly          ), N_NO_NOTIFY)
    N_PROPERTY(bool               , undoAvailable     , N_GETTER(isUndoAvailable     ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(bool               , redoAvailable     , N_GETTER(isRedoAvailable     ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(bool               , acceptableInput   , N_GETTER(hasAcceptableInput  ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_PROPERTY(QString            , placeholderText   , N_GETTER(placeholderText     ), N_SETTER(setPlaceholderText   ), N_NO_NOTIFY)
    N_PROPERTY(Qt::CursorMoveStyle, cursorMoveStyle   , N_GETTER(cursorMoveStyle     ), N_SETTER(setCursorMoveStyle   ), N_NO_NOTIFY)
    N_PROPERTY(bool               , clearButtonEnabled, N_GETTER(isClearButtonEnabled), N_SETTER(setClearButtonEnabled), N_NO_NOTIFY)
};

using LineEditId = LineEditIdT<QLineEdit>;

}

#endif // LINEEDIT_H
