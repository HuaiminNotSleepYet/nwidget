#ifndef NWIDGET_LABEL_H
#define NWIDGET_LABEL_H

#include <QLabel>

#include "frame.h"

namespace nwidget {

template<typename S, typename T>
class LabelBuilder : public FrameBuilder<S, T>
{
    N_BUILDER

public:
    LabelBuilder()                    : FrameBuilder<S, T>(new T) {}
    explicit
    LabelBuilder(const QString& text) : FrameBuilder<S, T>(new T(text)) {}
    explicit
    LabelBuilder(T* target)           : FrameBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(QString                 , text             , setText                )
    N_BUILDER_PROPERTY(Qt::TextFormat          , textFormat       , setTextFormat          )
    N_BUILDER_PROPERTY(QPixmap                 , pixmap           , setPixmap              )
    N_BUILDER_PROPERTY(bool                    , scaledContents   , setScaledContents      )
    N_BUILDER_PROPERTY(Qt::Alignment           , alignment        , setAlignment           )
    N_BUILDER_PROPERTY(bool                    , wordWrap         , setWordWrap            )
    N_BUILDER_PROPERTY(int                     , margin           , setMargin              )
    N_BUILDER_PROPERTY(int                     , indent           , setIndent              )
    N_BUILDER_PROPERTY(bool                    , openExternalLinks, setOpenExternalLinks   )
    N_BUILDER_PROPERTY(Qt::TextInteractionFlags, InteractionFlags , setTextInteractionFlags)
};

N_DECLARE_BUILDER(Label, LabelBuilder, QLabel)

template<typename T>
class LabelIdT : public FrameIdT<T>
{
public:
    using FrameIdT<T>::FrameIdT;

    N_ID_PROPERTY(QString                 , text             , N_READ text                 N_WRITE setText                )
    N_ID_PROPERTY(Qt::TextFormat          , textFormat       , N_READ textFormat           N_WRITE setTextFormat          )
    N_ID_PROPERTY(QPixmap                 , pixmap           , N_READ pixmap               N_WRITE setPixmap              )
    N_ID_PROPERTY(bool                    , scaledContents   , N_READ hasScaledContents    N_WRITE setScaledContents      )
    N_ID_PROPERTY(Qt::Alignment           , alignment        , N_READ alignment            N_WRITE setAlignment           )
    N_ID_PROPERTY(bool                    , wordWrap         , N_READ wordWrap             N_WRITE setWordWrap            )
    N_ID_PROPERTY(int                     , margin           , N_READ margin               N_WRITE setMargin              )
    N_ID_PROPERTY(int                     , indent           , N_READ indent               N_WRITE setIndent              )
    N_ID_PROPERTY(bool                    , openExternalLinks, N_READ openExternalLinks    N_WRITE setOpenExternalLinks   )
    N_ID_PROPERTY(Qt::TextInteractionFlags, InteractionFlags , N_READ textInteractionFlags N_WRITE setTextInteractionFlags)
    N_ID_PROPERTY(bool                    , hasSelectedText  , N_READ hasSelectedText      )
    N_ID_PROPERTY(QString                 , selectedText     , N_READ selectedText         )
};

N_DECLARE_ID(Label, LabelIdT, QLabel)

}

#endif // NWIDGET_LABEL_H
