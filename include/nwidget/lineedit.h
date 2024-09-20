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

    N_BUILDER_SETTER2(selection  , setSelection  )
    N_BUILDER_SETTER1(textMargins, setTextMargins)
    N_BUILDER_SETTER4(textMargins, setTextMargins)
#ifndef QT_NO_VALIDATOR
    N_BUILDER_SETTER1(validator  , setValidator  )
#endif
#if QT_CONFIG(completer)
    N_BUILDER_SETTER1(completer  , setCompleter  )
#endif

    N_BUILDER_SIGNAL(onTextChanged          , textChanged          )
    N_BUILDER_SIGNAL(onTextEdited           , textEdited           )
    N_BUILDER_SIGNAL(onCursorPositionChanged, cursorPositionChanged)
    N_BUILDER_SIGNAL(onReturnPressed        , returnPressed        )
    N_BUILDER_SIGNAL(onEditingFinished      , editingFinished      )
    N_BUILDER_SIGNAL(onSelectionChanged     , selectionChanged     )
    N_BUILDER_SIGNAL(onInputRejected        , inputRejected        )
};

N_DECLARE_BUILDER(LineEdit, LineEditBuilder, QLineEdit)



template<typename T>
class LineEditIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(QString            , inputMask         , N_READ inputMask            N_WRITE setInputMask         )
    N_ID_PROPERTY(QString            , text              , N_READ text                 N_WRITE setText              N_NOTIFY textChanged)
    N_ID_PROPERTY(int                , maxLength         , N_READ maxLength            N_WRITE setMaxLength         )
    N_ID_PROPERTY(bool               , frame             , N_READ hasFrame             N_WRITE setFrame             )
    N_ID_PROPERTY(QLineEdit::EchoMode, echoMode          , N_READ echoMode             N_WRITE setEchoMode          )
    N_ID_PROPERTY(QString            , displayText       , N_READ displayText                                       )
    N_ID_PROPERTY(int                , cursorPosition    , N_READ cursorPosition       N_WRITE setCursorPosition    )
    N_ID_PROPERTY(Qt::Alignment      , alignment         , N_READ alignment            N_WRITE setAlignment         )
    N_ID_PROPERTY(bool               , modified          , N_READ isModified           N_WRITE setModified          )
    N_ID_PROPERTY(bool               , hasSelectedText   , N_READ hasSelectedText                                   )
    N_ID_PROPERTY(QString            , selectedText      , N_READ selectedText                                      )
    N_ID_PROPERTY(bool               , dragEnabled       , N_READ dragEnabled          N_WRITE setDragEnabled       )
    N_ID_PROPERTY(bool               , readOnly          , N_READ isReadOnly           N_WRITE setReadOnly          )
    N_ID_PROPERTY(bool               , undoAvailable     , N_READ isUndoAvailable                                   )
    N_ID_PROPERTY(bool               , redoAvailable     , N_READ isRedoAvailable                                   )
    N_ID_PROPERTY(bool               , acceptableInput   , N_READ hasAcceptableInput                                )
    N_ID_PROPERTY(QString            , placeholderText   , N_READ placeholderText      N_WRITE setPlaceholderText   )
    N_ID_PROPERTY(Qt::CursorMoveStyle, cursorMoveStyle   , N_READ cursorMoveStyle      N_WRITE setCursorMoveStyle   )
    N_ID_PROPERTY(bool               , clearButtonEnabled, N_READ isClearButtonEnabled N_WRITE setClearButtonEnabled)
};

N_DECLARE_ID(LineEdit, LineEditIdT, QLineEdit)

}

N_REGISTER_ID(nwidget::LineEdit, QLineEdit)
N_REGISTER_BUILDER(nwidget::LineEdit, QLineEdit)

#endif // NWIDGET_LINEEDIT_H
