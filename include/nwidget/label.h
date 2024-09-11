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

    N_ID_PROPERTY(QString                 , text             , N_GETTER(text                ), N_SETTER(setText                ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::TextFormat          , textFormat       , N_GETTER(textFormat          ), N_SETTER(setTextFormat          ), N_NO_NOTIFY)
    N_ID_PROPERTY(QPixmap                 , pixmap           , N_GETTER(pixmap              ), N_SETTER(setPixmap              ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                    , scaledContents   , N_GETTER(hasScaledContents   ), N_SETTER(setScaledContents      ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Alignment           , alignment        , N_GETTER(alignment           ), N_SETTER(setAlignment           ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                    , wordWrap         , N_GETTER(wordWrap            ), N_SETTER(setWordWrap            ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                     , margin           , N_GETTER(margin              ), N_SETTER(setMargin              ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                     , indent           , N_GETTER(indent              ), N_SETTER(setIndent              ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                    , openExternalLinks, N_GETTER(openExternalLinks   ), N_SETTER(setOpenExternalLinks   ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::TextInteractionFlags, InteractionFlags , N_GETTER(textInteractionFlags), N_SETTER(setTextInteractionFlags), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                    , hasSelectedText  , N_GETTER(hasSelectedText     ), N_NO_SETTER                      , N_NO_NOTIFY)
    N_ID_PROPERTY(QString                 , selectedText     , N_GETTER(selectedText        ), N_NO_SETTER                      , N_NO_NOTIFY)
};

N_DECLARE_ID(Label, LabelIdT, QLabel)

}

#endif // NWIDGET_LABEL_H
