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

    N_BUILDER_PROPERTY(QStringList, searchPaths      , setSearchPaths      )
    N_BUILDER_PROPERTY(bool       , openExternalLinks, setOpenExternalLinks)
    N_BUILDER_PROPERTY(bool       , openLinks        , setOpenLinks        )

    N_SIGNAL(onBackwardAvailable, QTextBrowser::backwardAvailable)
    N_SIGNAL(onForwardAvailable , QTextBrowser::forwardAvailable )
    N_SIGNAL(onHistoryChanged   , QTextBrowser::historyChanged   )
    N_SIGNAL(onSourceChanged    , QTextBrowser::sourceChanged    )
    N_SIGNAL(onHighlighted      , QTextBrowser::highlighted      )
    N_SIGNAL(onAnchorClicked    , QTextBrowser::anchorClicked    )
};

N_BUILDER_IMPL(TextBrowserBuilder, QTextBrowser, TextBrowser);



template <typename T>
class TextBrowserIdT : public TextEditIdT<T>
{
public:
    using TextEditIdT<T>::TextEditIdT;

    N_PROPERTY(QUrl                       , source           , N_GETTER(source           ), N_NO_SETTER                   , N_NO_NOTIFY)
    N_PROPERTY(QTextDocument::ResourceType, sourceType       , N_GETTER(sourceType       ), N_NO_SETTER                   , N_NO_NOTIFY)
    N_PROPERTY(QStringList                , searchPaths      , N_GETTER(searchPaths      ), N_SETTER(setSearchPaths      ), N_NO_NOTIFY)
    N_PROPERTY(bool                       , openExternalLinks, N_GETTER(openExternalLinks), N_SETTER(setOpenExternalLinks), N_NO_NOTIFY)
    N_PROPERTY(bool                       , openLinks        , N_GETTER(openLinks        ), N_SETTER(setOpenLinks        ), N_NO_NOTIFY)
};

using TextBrowserId = TextBrowserIdT<QTextBrowser>;

}

#endif // TEXTBROWSER_H
