#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>

#include "widget.h"

namespace nw {

struct TabWidgetItem
{
    std::function<void(QTabWidget*)> addTo;

    TabWidgetItem(const QString& label, QWidget* page)                    { addTo = [label, page](QTabWidget* tab){ tab->addTab(page, label); }; }
    TabWidgetItem(const QIcon& icon, const QString& label, QWidget* page) { addTo = [icon, label, page](QTabWidget* tab){ tab->addTab(page, icon, label); }; }

    TabWidgetItem(ItemGenerator<TabWidgetItem> generator)
    {
        addTo = [generator](QTabWidget* tab){
            auto item = generator();
            while (item) {
                item->addTo(tab);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class TabWidgetBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    TabWidgetBuilder()                                                      : WidgetBuilder<S, T>(new T) {}
    TabWidgetBuilder(std::initializer_list<TabWidgetItem> pages)            : WidgetBuilder<S, T>(new T) { applyPages(pages); }
    explicit TabWidgetBuilder(T* target)                                    : WidgetBuilder<S, T>(target) {}
    TabWidgetBuilder(T* target, std::initializer_list<TabWidgetItem> pages) : WidgetBuilder<S, T>(target) { applyPages(pages); }

private:
    void applyPages(std::initializer_list<TabWidgetItem> pages)
    {
        auto end = pages.end();
        for (auto i = pages.begin(); i != end; ++i)
            i->addTo(t);
    }
};

N_BUILDER_IMPL(TabWidgetBuilder, QTabWidget, TabWidget);



template <typename T>
class TabWidgetRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

    N_PROPERTY(QTabWidget::TabPosition, tabPosition      , N_GETTER(tabPosition      ), N_SETTER(setTabPosition      ), N_NO_NOTIFY)
    N_PROPERTY(QTabWidget::TabShape   , tabShape         , N_GETTER(tabShape         ), N_SETTER(setTabShape         ), N_NO_NOTIFY)
    N_PROPERTY(int                    , currentIndex     , N_GETTER(currentIndex     ), N_SETTER(setCurrentIndex     ), N_NOTIFY(currentChanged))
    N_PROPERTY(int                    , count            , N_GETTER(count            ), N_NO_SETTER                   , N_NO_NOTIFY)
    N_PROPERTY(QSize                  , iconSize         , N_GETTER(iconSize         ), N_SETTER(setIconSize         ), N_NO_NOTIFY)
    N_PROPERTY(Qt::TextElideMode      , elideMode        , N_GETTER(elideMode        ), N_SETTER(setElideMode        ), N_NO_NOTIFY)
    N_PROPERTY(bool                   , usesScrollButtons, N_GETTER(usesScrollButtons), N_SETTER(setUsesScrollButtons), N_NO_NOTIFY)
    N_PROPERTY(bool                   , documentMode     , N_GETTER(documentMode     ), N_SETTER(setDocumentMode     ), N_NO_NOTIFY)
    N_PROPERTY(bool                   , tabsClosable     , N_GETTER(tabsClosable     ), N_SETTER(setTabsClosable     ), N_NO_NOTIFY)
    N_PROPERTY(bool                   , movable          , N_GETTER(isMovable        ), N_SETTER(setMovable          ), N_NO_NOTIFY)
    N_PROPERTY(bool                   , tabBarAutoHide   , N_GETTER(tabBarAutoHide   ), N_SETTER(setTabBarAutoHide   ), N_NO_NOTIFY)
};

using TabWidgetRef = TabWidgetRefT<QTabWidget>;

}

#endif // TABWIDGET_H
