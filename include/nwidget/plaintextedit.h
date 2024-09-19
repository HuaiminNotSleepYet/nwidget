#ifndef NWIDGET_PLAINTEXTEDIT_H
#define NWIDGET_PLAINTEXTEDIT_H

#include <QPlainTextEdit>

#include "abstractscrollarea.h"

namespace nwidget {

template<typename S, typename T>
class PlainTextEditBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_BUILDER

public:
    PlainTextEditBuilder()                    : AbstractScrollAreaBuilder<S, T>(new T) {}
    explicit
    PlainTextEditBuilder(const QString& text) : AbstractScrollAreaBuilder<S, T>(new T(text)) {}
    explicit
    PlainTextEditBuilder(T* target)           : AbstractScrollAreaBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(bool                        , tabChangesFocus     , setTabChangesFocus     )
    N_BUILDER_PROPERTY(QString                     , documentTitle       , setDocumentTitle       )
    N_BUILDER_PROPERTY(bool                        , undoRedoEnabled     , setUndoRedoEnabled     )
    N_BUILDER_PROPERTY(QPlainTextEdit::LineWrapMode, lineWrapMode        , setLineWrapMode        )
    N_BUILDER_PROPERTY(QTextOption::WrapMode       , wordWrapMode        , setWordWrapMode        )
    N_BUILDER_PROPERTY(bool                        , readOnly            , setReadOnly            )
    N_BUILDER_PROPERTY(QString                     , plainText           , setPlainText           )
    N_BUILDER_PROPERTY(bool                        , overwriteMode       , setOverwriteMode       )
    N_BUILDER_PROPERTY(qreal                       , tabStopDistance     , setTabStopDistance     )
    N_BUILDER_PROPERTY(int                         , cursorWidth         , setCursorWidth         )
    N_BUILDER_PROPERTY(Qt::TextInteractionFlags    , textInteractionFlags, setTextInteractionFlags)
    N_BUILDER_PROPERTY(int                         , maximumBlockCount   , setMaximumBlockCount   )
    N_BUILDER_PROPERTY(bool                        , backgroundVisible   , setBackgroundVisible   )
    N_BUILDER_PROPERTY(bool                        , centerOnScroll      , setCenterOnScroll      )
    N_BUILDER_PROPERTY(QString                     , placeholderText     , setPlaceholderText     )
};

N_DECLARE_BUILDER_N(PlainTextEdit, PlainTextEditBuilder, QPlainTextEdit)



template <typename T>
class PlainTextEditIdT : public AbstractScrollAreaIdT<T>
{
public:
    using AbstractScrollAreaIdT<T>::AbstractScrollAreaIdT;

    N_ID_PROPERTY(bool                        , tabChangesFocus     , N_READ tabChangesFocus      N_WRITE setTabChangesFocus     )
    N_ID_PROPERTY(QString                     , documentTitle       , N_READ documentTitle        N_WRITE setDocumentTitle       )
    N_ID_PROPERTY(bool                        , undoRedoEnabled     , N_READ isUndoRedoEnabled    N_WRITE setUndoRedoEnabled     )
    N_ID_PROPERTY(QPlainTextEdit::LineWrapMode, lineWrapMode        , N_READ lineWrapMode         N_WRITE setLineWrapMode        )
    N_ID_PROPERTY(QTextOption::WrapMode       , wordWrapMode        , N_READ wordWrapMode         N_WRITE setWordWrapMode        )
    N_ID_PROPERTY(bool                        , readOnly            , N_READ isReadOnly           N_WRITE setReadOnly            )
    N_ID_PROPERTY(QString                     , plainText           , N_READ toPlainText          N_WRITE setPlainText           N_NOTIFY textChanged)
    N_ID_PROPERTY(bool                        , overwriteMode       , N_READ overwriteMode        N_WRITE setOverwriteMode       )
    N_ID_PROPERTY(qreal                       , tabStopDistance     , N_READ tabStopDistance      N_WRITE setTabStopDistance     )
    N_ID_PROPERTY(int                         , cursorWidth         , N_READ cursorWidth          N_WRITE setCursorWidth         )
    N_ID_PROPERTY(Qt::TextInteractionFlags    , textInteractionFlags, N_READ textInteractionFlags N_WRITE setTextInteractionFlags)
    N_ID_PROPERTY(int                         , blockCount          , N_READ blockCount                                          )
    N_ID_PROPERTY(int                         , maximumBlockCount   , N_READ maximumBlockCount    N_WRITE setMaximumBlockCount   )
    N_ID_PROPERTY(bool                        , backgroundVisible   , N_READ backgroundVisible    N_WRITE setBackgroundVisible   )
    N_ID_PROPERTY(bool                        , centerOnScroll      , N_READ centerOnScroll       N_WRITE setCenterOnScroll      )
    N_ID_PROPERTY(QString                     , placeholderText     , N_READ placeholderText      N_WRITE setPlaceholderText     )
};

N_DECLARE_ID_N(PlainTextEdit, PlainTextEditIdT, QPlainTextEdit)

}

#endif // NWIDGET_PLAINTEXTEDIT_H
