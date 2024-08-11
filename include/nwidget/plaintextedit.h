#ifndef PLAINTEXTEDIT_H
#define PLAINTEXTEDIT_H

#include <QPlainTextEdit>

#include "abstractscrollarea.h"

namespace nw {

template<typename S, typename T>
class PlainTextEditBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractScrollAreaBuilder, S, T)

public:
    PlainTextEditBuilder()                    : AbstractScrollAreaBuilder<S, T>(new T) {}
    explicit PlainTextEditBuilder(T* target)  : AbstractScrollAreaBuilder<S, T>(target) {}
    PlainTextEditBuilder(const QString& text) : AbstractScrollAreaBuilder<S, T>(new T(text)) {}
};

N_BUILDER_IMPL(PlainTextEditBuilder, QPlainTextEdit, PlainTextEdit);



template <typename T>
class PlainTextEditRefT : public AbstractScrollAreaRefT<T>
{
public:
    using AbstractScrollAreaRefT<T>::AbstractScrollAreaRefT;

    N_PROPERTY(bool                        , tabChangesFocus     , N_GETTER(tabChangesFocus     ), N_SETTER(setTabChangesFocus     ), N_NO_NOTIFY)
    N_PROPERTY(QString                     , documentTitle       , N_GETTER(documentTitle       ), N_SETTER(setDocumentTitle       ), N_NO_NOTIFY)
    N_PROPERTY(bool                        , undoRedoEnabled     , N_GETTER(isUndoRedoEnabled   ), N_SETTER(setUndoRedoEnabled     ), N_NO_NOTIFY)
    N_PROPERTY(QPlainTextEdit::LineWrapMode, lineWrapMode        , N_GETTER(lineWrapMode        ), N_SETTER(setLineWrapMode        ), N_NO_NOTIFY)
    N_PROPERTY(QTextOption::WrapMode       , wordWrapMode        , N_GETTER(wordWrapMode        ), N_SETTER(setWordWrapMode        ), N_NO_NOTIFY)
    N_PROPERTY(bool                        , readOnly            , N_GETTER(isReadOnly          ), N_SETTER(setReadOnly            ), N_NO_NOTIFY)
    N_PROPERTY(QString                     , plainText           , N_GETTER(toPlainText         ), N_SETTER(setPlainText           ), N_NOTIFY(textChanged))
    N_PROPERTY(bool                        , overwriteMode       , N_GETTER(overwriteMode       ), N_SETTER(setOverwriteMode       ), N_NO_NOTIFY)
    N_PROPERTY(qreal                       , tabStopDistance     , N_GETTER(tabStopDistance     ), N_SETTER(setTabStopDistance     ), N_NO_NOTIFY)
    N_PROPERTY(int                         , cursorWidth         , N_GETTER(cursorWidth         ), N_SETTER(setCursorWidth         ), N_NO_NOTIFY)
    N_PROPERTY(Qt::TextInteractionFlags    , textInteractionFlags, N_GETTER(textInteractionFlags), N_SETTER(setTextInteractionFlags), N_NO_NOTIFY)
    N_PROPERTY(int                         , blockCount          , N_GETTER(blockCount          ), N_NO_SETTER                      , N_NO_NOTIFY)
    N_PROPERTY(int                         , maximumBlockCount   , N_GETTER(maximumBlockCount   ), N_SETTER(setMaximumBlockCount   ), N_NO_NOTIFY)
    N_PROPERTY(bool                        , backgroundVisible   , N_GETTER(backgroundVisible   ), N_SETTER(setBackgroundVisible   ), N_NO_NOTIFY)
    N_PROPERTY(bool                        , centerOnScroll      , N_GETTER(centerOnScroll      ), N_SETTER(setCenterOnScroll      ), N_NO_NOTIFY)
    N_PROPERTY(QString                     , placeholderText     , N_GETTER(placeholderText     ), N_SETTER(setPlaceholderText     ), N_NO_NOTIFY)
};

using PlainTextEditRef = PlainTextEditRefT<QPlainTextEdit>;

}

#endif // PLAINTEXTEDIT_H
