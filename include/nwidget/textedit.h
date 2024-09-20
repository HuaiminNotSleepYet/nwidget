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

N_DECLARE_BUILDER(TextEdit, TextEditBuilder, QTextEdit)



template <typename T> class TextEditIdT : public AbstractScrollAreaIdT<T>
{
public:
    using AbstractScrollAreaIdT<T>::AbstractScrollAreaIdT;

    N_ID_PROPERTY(QTextEdit::AutoFormatting, autoFormatting       , N_READ autoFormatting        N_WRITE setAutoFormatting       )
    N_ID_PROPERTY(bool                     , tabChangesFocus      , N_READ tabChangesFocus       N_WRITE setTabChangesFocus      )
    N_ID_PROPERTY(QString                  , documentTitle        , N_READ documentTitle         N_WRITE setDocumentTitle        )
    N_ID_PROPERTY(bool                     , undoRedoEnabled      , N_READ isUndoRedoEnabled     N_WRITE setUndoRedoEnabled      )
    N_ID_PROPERTY(QTextEdit::LineWrapMode  , lineWrapMode         , N_READ lineWrapMode          N_WRITE setLineWrapMode         )
    N_ID_PROPERTY(QTextOption::WrapMode    , wordWrapMode         , N_READ wordWrapMode          N_WRITE setWordWrapMode         )
    N_ID_PROPERTY(int                      , lineWrapColumnOrWidth, N_READ lineWrapColumnOrWidth N_WRITE setLineWrapColumnOrWidth)
    N_ID_PROPERTY(bool                     , readOnly             , N_READ isReadOnly            N_WRITE setReadOnly             )
    N_ID_PROPERTY(QString                  , markdown             , N_READ toMarkdown            N_WRITE setMarkdown             N_NOTIFY textChanged)
    N_ID_PROPERTY(QString                  , html                 , N_READ toHtml                N_WRITE setHtml                 N_NOTIFY textChanged)
    N_ID_PROPERTY(QString                  , plainText            , N_READ toPlainText           N_WRITE setPlainText            )
    N_ID_PROPERTY(bool                     , overwriteMode        , N_READ overwriteMode         N_WRITE setOverwriteMode        )
    N_ID_PROPERTY(qreal                    , tabStopDistance      , N_READ tabStopDistance       N_WRITE setTabStopDistance      )
    N_ID_PROPERTY(bool                     , acceptRichText       , N_READ acceptRichText        N_WRITE setAcceptRichText       )
    N_ID_PROPERTY(int                      , cursorWidth          , N_READ cursorWidth           N_WRITE setCursorWidth          )
    N_ID_PROPERTY(Qt::TextInteractionFlags , textInteractionFlags , N_READ textInteractionFlags  N_WRITE setTextInteractionFlags )
    N_ID_PROPERTY(QTextDocument*           , document             , N_READ document              N_WRITE setDocument             )
    N_ID_PROPERTY(QString                  , placeholderText      , N_READ placeholderText       N_WRITE setPlaceholderText      )
};

N_DECLARE_ID(TextEdit, TextEditIdT, QTextEdit)

}

N_REGISTER_ID(nwidget::TextEdit, QTextEdit)
N_REGISTER_BUILDER(nwidget::TextEdit, QTextEdit)

#endif // NWIDGET_TEXTEDIT_H
