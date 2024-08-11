#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

#include "frame.h"

namespace nw {

template<typename S, typename T>
class LabelBuilder : public FrameBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(FrameBuilder, S, T)

public:
    LabelBuilder()                    : FrameBuilder<S, T>(new T) {}
    explicit LabelBuilder(T* target)  : FrameBuilder<S, T>(target) {}
    LabelBuilder(const QString& text) : FrameBuilder<S, T>(new T(text)) {}

    S& alignment(Qt::Alignment align) { t->setAlignment(align); return self(); }
};

N_BUILDER_IMPL(LabelBuilder, QLabel, Label);

template<typename T>
class LabelRefT : FrameRefT<T>
{
public:
    using FrameRefT<T>::FrameRefT;

    N_PROPERTY(QString                 , text             , N_GETTER(text                ), N_SETTER(setText                ), N_NO_NOTIFY)
    N_PROPERTY(Qt::TextFormat          , textFormat       , N_GETTER(textFormat          ), N_SETTER(setTextFormat          ), N_NO_NOTIFY)
    N_PROPERTY(QPixmap                 , pixmap           , N_GETTER(pixmap              ), N_SETTER(setPixmap              ), N_NO_NOTIFY)
    N_PROPERTY(bool                    , scaledContents   , N_GETTER(hasScaledContents   ), N_SETTER(setScaledContents      ), N_NO_NOTIFY)
    N_PROPERTY(Qt::Alignment           , alignment        , N_GETTER(alignment           ), N_SETTER(setAlignment           ), N_NO_NOTIFY)
    N_PROPERTY(bool                    , wordWrap         , N_GETTER(wordWrap            ), N_SETTER(setWordWrap            ), N_NO_NOTIFY)
    N_PROPERTY(int                     , margin           , N_GETTER(margin              ), N_SETTER(setMargin              ), N_NO_NOTIFY)
    N_PROPERTY(int                     , indent           , N_GETTER(indent              ), N_SETTER(setIndent              ), N_NO_NOTIFY)
    N_PROPERTY(bool                    , openExternalLinks, N_GETTER(openExternalLinks   ), N_SETTER(setOpenExternalLinks   ), N_NO_NOTIFY)
    N_PROPERTY(Qt::TextInteractionFlags, InteractionFlags , N_GETTER(textInteractionFlags), N_SETTER(setTextInteractionFlags), N_NO_NOTIFY)
    N_PROPERTY(bool                    , hasSelectedText  , N_GETTER(hasSelectedText     ), N_NO_SETTER                      , N_NO_NOTIFY)
    N_PROPERTY(QString                 , selectedText     , N_GETTER(selectedText        ), N_NO_SETTER                      , N_NO_NOTIFY)
};

using LabelRef = LabelRefT<QLabel>;

}

#endif // LABEL_H
