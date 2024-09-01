#ifndef NWIDGET_LINEEDIT_H
#define NWIDGET_LINEEDIT_H

#include <QLineEdit>

#include "widget.h"

namespace nwidget {

template<typename S, typename T>
class LineEditBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    LineEditBuilder()                    : WidgetBuilder<S, T>(new T) {}
    explicit
    LineEditBuilder(const QString& text) : WidgetBuilder<S, T>(new T(text)) {}
    explicit
    LineEditBuilder(T* target)           : WidgetBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(QString            , inputMask         , setInputMask         )
    N_BUILDER_PROPERTY(QString            , text              , setText              )
    N_BUILDER_PROPERTY(int                , maxLength         , setMaxLength         )
    N_BUILDER_PROPERTY(bool               , frame             , setFrame             )
    N_BUILDER_PROPERTY(QLineEdit::EchoMode, echoMode          , setEchoMode          )
    N_BUILDER_PROPERTY(int                , cursorPosition    , setCursorPosition    )
    N_BUILDER_PROPERTY(Qt::Alignment      , alignment         , setAlignment         )
    N_BUILDER_PROPERTY(bool               , modified          , setModified          )
    N_BUILDER_PROPERTY(bool               , dragEnabled       , setDragEnabled       )
    N_BUILDER_PROPERTY(bool               , readOnly          , setReadOnly          )
    N_BUILDER_PROPERTY(QString            , placeholderText   , setPlaceholderText   )
    N_BUILDER_PROPERTY(Qt::CursorMoveStyle, cursorMoveStyle   , setCursorMoveStyle   )
    N_BUILDER_PROPERTY(bool               , clearButtonEnabled, setClearButtonEnabled)

#ifndef QT_NO_VALIDATOR
    S& validator(const QValidator* v)             { t->setValidator(v);                  return self(); }
#endif
#if QT_CONFIG(completer)
    S& completer(const QCompleter* c)             { t->setCompleter(c);                  return self(); }
#endif
    S& selection(int begin, int end)              { t->setSelection(begin, end);         return self(); }
    S& textMargins(int l, int t, int r, int b)    { this->t->setTextMargins(l, t, r, b); return self(); }
    S& textMargins(const QMargins& margin)        { this->t->setTextMargins(margin);     return self(); }

    N_BUILDER_SIGNAL(onTextChanged          , textChanged          )
    N_BUILDER_SIGNAL(onTextEdited           , textEdited           )
    N_BUILDER_SIGNAL(onCursorPositionChanged, cursorPositionChanged)
    N_BUILDER_SIGNAL(onReturnPressed        , returnPressed        )
    N_BUILDER_SIGNAL(onEditingFinished      , editingFinished      )
    N_BUILDER_SIGNAL(onSelectionChanged     , selectionChanged     )
    N_BUILDER_SIGNAL(onInputRejected        , inputRejected        )
};

N_DECL_BUILDER(LineEditBuilder, QLineEdit, LineEdit);



template<typename T>
class LineEditIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(QString            , inputMask         , N_GETTER(inputMask           ), N_SETTER(setInputMask         ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString            , text              , N_GETTER(text                ), N_SETTER(setText              ), N_NOTIFY(textChanged))
    N_ID_PROPERTY(int                , maxLength         , N_GETTER(maxLength           ), N_SETTER(setMaxLength         ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , frame             , N_GETTER(hasFrame            ), N_SETTER(setFrame             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QLineEdit::EchoMode, echoMode          , N_GETTER(echoMode            ), N_SETTER(setEchoMode          ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString            , displayText       , N_GETTER(displayText         ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(int                , cursorPosition    , N_GETTER(cursorPosition      ), N_SETTER(setCursorPosition    ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Alignment      , alignment         , N_GETTER(alignment           ), N_SETTER(setAlignment         ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , modified          , N_GETTER(isModified          ), N_SETTER(setModified          ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , hasSelectedText   , N_GETTER(hasSelectedText     ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(QString            , selectedText      , N_GETTER(selectedText        ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , dragEnabled       , N_GETTER(dragEnabled         ), N_SETTER(setDragEnabled       ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , readOnly          , N_GETTER(isReadOnly          ), N_SETTER(setReadOnly          ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , undoAvailable     , N_GETTER(isUndoAvailable     ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , redoAvailable     , N_GETTER(isRedoAvailable     ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , acceptableInput   , N_GETTER(hasAcceptableInput  ), N_NO_SETTER                    , N_NO_NOTIFY)
    N_ID_PROPERTY(QString            , placeholderText   , N_GETTER(placeholderText     ), N_SETTER(setPlaceholderText   ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::CursorMoveStyle, cursorMoveStyle   , N_GETTER(cursorMoveStyle     ), N_SETTER(setCursorMoveStyle   ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool               , clearButtonEnabled, N_GETTER(isClearButtonEnabled), N_SETTER(setClearButtonEnabled), N_NO_NOTIFY)
};

using LineEditId = LineEditIdT<QLineEdit>;

}

#endif // NWIDGET_LINEEDIT_H
