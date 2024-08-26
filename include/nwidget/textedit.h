#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

#include "abstractscrollarea.h"

namespace nw {

template<typename S, typename T>
class TextEditBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_BUILDER

public:
    TextEditBuilder()                    : AbstractScrollAreaBuilder<S, T>(new T) {}
    TextEditBuilder(const QString& text) : AbstractScrollAreaBuilder<S, T>(new T(text)) {}
    explicit TextEditBuilder(T* target)  : AbstractScrollAreaBuilder<S, T>(target) {}
    TextEditBuilder(T* target, const QString& text) : AbstractScrollAreaBuilder<S, T>(target) { t->setPlainText(text); }

    N_BUILDER_PROPERTY(QTextEdit::AutoFormatting, autoFormatting       , setAutoFormatting       )
    N_BUILDER_PROPERTY(bool                     , tabChangesFocus      , setTabChangesFocus      )
    N_BUILDER_PROPERTY(QString                  , documentTitle        , setDocumentTitle        )
    N_BUILDER_PROPERTY(bool                     , undoRedoEnabled      , setUndoRedoEnabled      )
    N_BUILDER_PROPERTY(QTextEdit::LineWrapMode  , lineWrapMode         , setLineWrapMode         )
    N_BUILDER_PROPERTY(QTextOption::WrapMode    , wordWrapMode         , setWordWrapMode         )
    N_BUILDER_PROPERTY(int                      , lineWrapColumnOrWidth, setLineWrapColumnOrWidth)
    N_BUILDER_PROPERTY(bool                     , readOnly             , setReadOnly             )
    N_BUILDER_PROPERTY(QString                  , markdown             , setMarkdown             )
    N_BUILDER_PROPERTY(QString                  , html                 , setHtml                 )
    N_BUILDER_PROPERTY(QString                  , plainText            , setPlainText            )
    N_BUILDER_PROPERTY(bool                     , overwriteMode        , setOverwriteMode        )
    N_BUILDER_PROPERTY(qreal                    , tabStopDistance      , setTabStopDistance      )
    N_BUILDER_PROPERTY(bool                     , acceptRichText       , setAcceptRichText       )
    N_BUILDER_PROPERTY(int                      , cursorWidth          , setCursorWidth          )
    N_BUILDER_PROPERTY(Qt::TextInteractionFlags , textInteractionFlags , setTextInteractionFlags )
    N_BUILDER_PROPERTY(QTextDocument*           , document             , setDocument             )
    N_BUILDER_PROPERTY(QString                  , placeholderText      , setPlaceholderText      )

    N_SIGNAL(onTextChanged             , QTextEdit::textChanged             )
    N_SIGNAL(onUndoAvailable           , QTextEdit::undoAvailable           )
    N_SIGNAL(onRedoAvailable           , QTextEdit::redoAvailable           )
    N_SIGNAL(onCurrentCharFormatChanged, QTextEdit::currentCharFormatChanged)
    N_SIGNAL(onCopyAvailable           , QTextEdit::copyAvailable           )
    N_SIGNAL(onSelectionChanged        , QTextEdit::selectionChanged        )
    N_SIGNAL(onCursorPositionChanged   , QTextEdit::cursorPositionChanged   )
};

N_BUILDER_IMPL(TextEditBuilder, QTextEdit, TextEdit);



template <typename T> class TextEditIdT : public AbstractScrollAreaIdT<T>
{
public:
    using AbstractScrollAreaIdT<T>::AbstractScrollAreaIdT;

    N_PROPERTY(QTextEdit::AutoFormatting, autoFormatting       , N_GETTER(autoFormatting       ), N_SETTER(setAutoFormatting       ), N_NO_NOTIFY)
    N_PROPERTY(bool                     , tabChangesFocus      , N_GETTER(tabChangesFocus      ), N_SETTER(setTabChangesFocus      ), N_NO_NOTIFY)
    N_PROPERTY(QString                  , documentTitle        , N_GETTER(documentTitle        ), N_SETTER(setDocumentTitle        ), N_NO_NOTIFY)
    N_PROPERTY(bool                     , undoRedoEnabled      , N_GETTER(isUndoRedoEnabled    ), N_SETTER(setUndoRedoEnabled      ), N_NO_NOTIFY)
    N_PROPERTY(QTextEdit::LineWrapMode  , lineWrapMode         , N_GETTER(lineWrapMode         ), N_SETTER(setLineWrapMode         ), N_NO_NOTIFY)
    N_PROPERTY(QTextOption::WrapMode    , wordWrapMode         , N_GETTER(wordWrapMode         ), N_SETTER(setWordWrapMode         ), N_NO_NOTIFY)
    N_PROPERTY(int                      , lineWrapColumnOrWidth, N_GETTER(lineWrapColumnOrWidth), N_SETTER(setLineWrapColumnOrWidth), N_NO_NOTIFY)
    N_PROPERTY(bool                     , readOnly             , N_GETTER(isReadOnly           ), N_SETTER(setReadOnly             ), N_NO_NOTIFY)
    N_PROPERTY(QString                  , markdown             , N_GETTER(toMarkdown           ), N_SETTER(setMarkdown             ), N_NOTIFY(textChanged))
    N_PROPERTY(QString                  , html                 , N_GETTER(toHtml               ), N_SETTER(setHtml                 ), N_NOTIFY(textChanged))
    N_PROPERTY(QString                  , plainText            , N_GETTER(toPlainText          ), N_SETTER(setPlainText            ), N_NO_NOTIFY)
    N_PROPERTY(bool                     , overwriteMode        , N_GETTER(overwriteMode        ), N_SETTER(setOverwriteMode        ), N_NO_NOTIFY)
    N_PROPERTY(qreal                    , tabStopDistance      , N_GETTER(tabStopDistance      ), N_SETTER(setTabStopDistance      ), N_NO_NOTIFY)
    N_PROPERTY(bool                     , acceptRichText       , N_GETTER(acceptRichText       ), N_SETTER(setAcceptRichText       ), N_NO_NOTIFY)
    N_PROPERTY(int                      , cursorWidth          , N_GETTER(cursorWidth          ), N_SETTER(setCursorWidth          ), N_NO_NOTIFY)
    N_PROPERTY(Qt::TextInteractionFlags , textInteractionFlags , N_GETTER(textInteractionFlags ), N_SETTER(setTextInteractionFlags ), N_NO_NOTIFY)
    N_PROPERTY(QTextDocument*           , document             , N_GETTER(document             ), N_SETTER(setDocument             ), N_NO_NOTIFY)
    N_PROPERTY(QString                  , placeholderText      , N_GETTER(placeholderText      ), N_SETTER(setPlaceholderText      ), N_NO_NOTIFY)
};

using TextEditId = TextEditIdT<QTextEdit>;

}

#endif // TEXTEDIT_H
