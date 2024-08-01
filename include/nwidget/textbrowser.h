#ifndef TEXTBROWSER_H
#define TEXTBROWSER_H

#include <QTextBrowser>

#include "textedit.h"

namespace nw {

template<typename S, typename T>
class TextBrowserBuilder : public TextEditBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(TextEditBuilder, S, T)

public:
    TextBrowserBuilder()                   : TextEditBuilder<S, T>(new T) {}
    explicit TextBrowserBuilder(T* target) : TextEditBuilder<S, T>(target) {}

    N_SIGNAL(onBackwardAvailable, QTextBrowser::backwardAvailable)
    N_SIGNAL(onForwardAvailable , QTextBrowser::forwardAvailable )
    N_SIGNAL(onHistoryChanged   , QTextBrowser::historyChanged   )
    N_SIGNAL(onSourceChanged    , QTextBrowser::sourceChanged    )
    N_SIGNAL(onHighlighted      , QTextBrowser::highlighted      )
    N_SIGNAL(onAnchorClicked    , QTextBrowser::anchorClicked    )
};

N_BUILDER_IMPL(TextBrowserBuilder, QTextBrowser, TextBrowser);

}

#endif // TEXTBROWSER_H
