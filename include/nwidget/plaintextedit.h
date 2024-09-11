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

N_DECLARE_BUILDER(PlainTextEdit, PlainTextEditBuilder, QPlainTextEdit)



template <typename T>
class PlainTextEditIdT : public AbstractScrollAreaIdT<T>
{
public:
    using AbstractScrollAreaIdT<T>::AbstractScrollAreaIdT;

    N_ID_PROPERTY(bool                        , tabChangesFocus     , N_GETTER(tabChangesFocus     ), N_SETTER(setTabChangesFocus     ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                     , documentTitle       , N_GETTER(documentTitle       ), N_SETTER(setDocumentTitle       ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                        , undoRedoEnabled     , N_GETTER(isUndoRedoEnabled   ), N_SETTER(setUndoRedoEnabled     ), N_NO_NOTIFY)
    N_ID_PROPERTY(QPlainTextEdit::LineWrapMode, lineWrapMode        , N_GETTER(lineWrapMode        ), N_SETTER(setLineWrapMode        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QTextOption::WrapMode       , wordWrapMode        , N_GETTER(wordWrapMode        ), N_SETTER(setWordWrapMode        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                        , readOnly            , N_GETTER(isReadOnly          ), N_SETTER(setReadOnly            ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                     , plainText           , N_GETTER(toPlainText         ), N_SETTER(setPlainText           ), N_NOTIFY(textChanged))
    N_ID_PROPERTY(bool                        , overwriteMode       , N_GETTER(overwriteMode       ), N_SETTER(setOverwriteMode       ), N_NO_NOTIFY)
    N_ID_PROPERTY(qreal                       , tabStopDistance     , N_GETTER(tabStopDistance     ), N_SETTER(setTabStopDistance     ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                         , cursorWidth         , N_GETTER(cursorWidth         ), N_SETTER(setCursorWidth         ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::TextInteractionFlags    , textInteractionFlags, N_GETTER(textInteractionFlags), N_SETTER(setTextInteractionFlags), N_NO_NOTIFY)
    N_ID_PROPERTY(int                         , blockCount          , N_GETTER(blockCount          ), N_NO_SETTER                      , N_NO_NOTIFY)
    N_ID_PROPERTY(int                         , maximumBlockCount   , N_GETTER(maximumBlockCount   ), N_SETTER(setMaximumBlockCount   ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                        , backgroundVisible   , N_GETTER(backgroundVisible   ), N_SETTER(setBackgroundVisible   ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                        , centerOnScroll      , N_GETTER(centerOnScroll      ), N_SETTER(setCenterOnScroll      ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                     , placeholderText     , N_GETTER(placeholderText     ), N_SETTER(setPlaceholderText     ), N_NO_NOTIFY)
};

N_DECLARE_ID(QPlainTextEdit, PlainTextEditIdT, QPlainTextEdit)

}

#endif // NWIDGET_PLAINTEXTEDIT_H
