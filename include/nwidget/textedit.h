#ifndef NWIDGET_TEXTEDIT_H
#define NWIDGET_TEXTEDIT_H

#include <QTextEdit>

#include "abstractscrollarea.h"

namespace nwidget {

template<typename S, typename T>
class TextEditBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_BUILDER

public:
    TextEditBuilder()                    : AbstractScrollAreaBuilder<S, T>(new T) {}
    TextEditBuilder(const QString& text) : AbstractScrollAreaBuilder<S, T>(new T(text)) {}
    explicit
    TextEditBuilder(T* target)           : AbstractScrollAreaBuilder<S, T>(target) {}


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

    N_BUILDER_SIGNAL(onTextChanged             , textChanged             )
    N_BUILDER_SIGNAL(onUndoAvailable           , undoAvailable           )
    N_BUILDER_SIGNAL(onRedoAvailable           , redoAvailable           )
    N_BUILDER_SIGNAL(onCurrentCharFormatChanged, currentCharFormatChanged)
    N_BUILDER_SIGNAL(onCopyAvailable           , copyAvailable           )
    N_BUILDER_SIGNAL(onSelectionChanged        , selectionChanged        )
    N_BUILDER_SIGNAL(onCursorPositionChanged   , cursorPositionChanged   )
};

N_DECL_BUILDER(TextEditBuilder, QTextEdit, TextEdit);



template <typename T> class TextEditIdT : public AbstractScrollAreaIdT<T>
{
public:
    using AbstractScrollAreaIdT<T>::AbstractScrollAreaIdT;

    N_ID_PROPERTY(QTextEdit::AutoFormatting, autoFormatting       , N_GETTER(autoFormatting       ), N_SETTER(setAutoFormatting       ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                     , tabChangesFocus      , N_GETTER(tabChangesFocus      ), N_SETTER(setTabChangesFocus      ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                  , documentTitle        , N_GETTER(documentTitle        ), N_SETTER(setDocumentTitle        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                     , undoRedoEnabled      , N_GETTER(isUndoRedoEnabled    ), N_SETTER(setUndoRedoEnabled      ), N_NO_NOTIFY)
    N_ID_PROPERTY(QTextEdit::LineWrapMode  , lineWrapMode         , N_GETTER(lineWrapMode         ), N_SETTER(setLineWrapMode         ), N_NO_NOTIFY)
    N_ID_PROPERTY(QTextOption::WrapMode    , wordWrapMode         , N_GETTER(wordWrapMode         ), N_SETTER(setWordWrapMode         ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                      , lineWrapColumnOrWidth, N_GETTER(lineWrapColumnOrWidth), N_SETTER(setLineWrapColumnOrWidth), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                     , readOnly             , N_GETTER(isReadOnly           ), N_SETTER(setReadOnly             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                  , markdown             , N_GETTER(toMarkdown           ), N_SETTER(setMarkdown             ), N_NOTIFY(textChanged))
    N_ID_PROPERTY(QString                  , html                 , N_GETTER(toHtml               ), N_SETTER(setHtml                 ), N_NOTIFY(textChanged))
    N_ID_PROPERTY(QString                  , plainText            , N_GETTER(toPlainText          ), N_SETTER(setPlainText            ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                     , overwriteMode        , N_GETTER(overwriteMode        ), N_SETTER(setOverwriteMode        ), N_NO_NOTIFY)
    N_ID_PROPERTY(qreal                    , tabStopDistance      , N_GETTER(tabStopDistance      ), N_SETTER(setTabStopDistance      ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                     , acceptRichText       , N_GETTER(acceptRichText       ), N_SETTER(setAcceptRichText       ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                      , cursorWidth          , N_GETTER(cursorWidth          ), N_SETTER(setCursorWidth          ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::TextInteractionFlags , textInteractionFlags , N_GETTER(textInteractionFlags ), N_SETTER(setTextInteractionFlags ), N_NO_NOTIFY)
    N_ID_PROPERTY(QTextDocument*           , document             , N_GETTER(document             ), N_SETTER(setDocument             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                  , placeholderText      , N_GETTER(placeholderText      ), N_SETTER(setPlaceholderText      ), N_NO_NOTIFY)
};

using TextEditId = TextEditIdT<QTextEdit>;

}

#endif // NWIDGET_TEXTEDIT_H
