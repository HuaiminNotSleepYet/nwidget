#ifndef NWIDGET_TEXTBROWSER_H
#define NWIDGET_TEXTBROWSER_H

#include <QTextBrowser>

#include "textedit.h"

namespace nwidget {

template<typename S, typename T>
class TextBrowserBuilder : public TextEditBuilder<S, T>
{
    N_BUILDER

public:
    TextBrowserBuilder()          : TextEditBuilder<S, T>(new T) {}
    explicit
    TextBrowserBuilder(T* target) : TextEditBuilder<S, T>(target) {}


    N_BUILDER_PROPERTY(QStringList, searchPaths      , setSearchPaths      )
    N_BUILDER_PROPERTY(bool       , openExternalLinks, setOpenExternalLinks)
    N_BUILDER_PROPERTY(bool       , openLinks        , setOpenLinks        )

    N_BUILDER_SIGNAL(onBackwardAvailable, backwardAvailable)
    N_BUILDER_SIGNAL(onForwardAvailable , forwardAvailable )
    N_BUILDER_SIGNAL(onHistoryChanged   , historyChanged   )
    N_BUILDER_SIGNAL(onSourceChanged    , sourceChanged    )
    N_BUILDER_SIGNAL(onHighlighted      , highlighted      )
    N_BUILDER_SIGNAL(onAnchorClicked    , anchorClicked    )
};

N_DECLARE_BUILDER(TextBrowser, TextBrowserBuilder, QTextBrowser);



template <typename T>
class TextBrowserIdT : public TextEditIdT<T>
{
public:
    using TextEditIdT<T>::TextEditIdT;

    N_ID_PROPERTY(QUrl                       , source           , N_GETTER(source           ), N_NO_SETTER                   , N_NO_NOTIFY)
    N_ID_PROPERTY(QTextDocument::ResourceType, sourceType       , N_GETTER(sourceType       ), N_NO_SETTER                   , N_NO_NOTIFY)
    N_ID_PROPERTY(QStringList                , searchPaths      , N_GETTER(searchPaths      ), N_SETTER(setSearchPaths      ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                       , openExternalLinks, N_GETTER(openExternalLinks), N_SETTER(setOpenExternalLinks), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                       , openLinks        , N_GETTER(openLinks        ), N_SETTER(setOpenLinks        ), N_NO_NOTIFY)
};

N_DECLARE_ID(TextBrowser, TextBrowserIdT, QTextBrowser)

}

#endif // NWIDGET_TEXTBROWSER_H
