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

    S& tabEnabled(int index, bool enabled)                          { t->setTabEnabled(index, enabled)   ; return self(); }
    S& tabVisible(int index, bool visible)                          { t->setTabVisible(index, visible)   ; return self(); }
    S& tabText(int index, const QString &text)                      { t->setTabText(index, text)         ; return self(); }
    S& tabIcon(int index, const QIcon & icon)                       { t->setTabIcon(index, icon)         ; return self(); }
#if QT_CONFIG(tooltip)
    S& tabToolTip(int index, const QString & tip)                   { t->setTabToolTip(index, tip)       ; return self(); }
#endif
#if QT_CONFIG(whatsthis)
    S& tabWhatsThis(int index, const QString &text)                 { t->setTabWhatsThis(index, text)    ; return self(); }
#endif
    S& tabPosition(QTabWidget::TabPosition position)                { t->setTabPosition(position)        ; return self(); }
    S& tabsClosable(bool closeable)                                 { t->setTabsClosable(closeable)      ; return self(); }
    S& movable(bool movable)                                        { t->setMovable(movable)             ; return self(); }
    S& tabShape(QTabWidget::TabShape s)                             { t->setTabShape(s)                  ; return self(); }
    S& cornerWidget(QWidget * w, Qt::Corner c = Qt::TopRightCorner) { t->setCornerWidget(w, c)           ; return self(); }
    S& elideMode(Qt::TextElideMode mode)                            { t->setElideMode(mode)              ; return self(); }
    S& iconSize(const QSize &size)                                  { t->setIconSize(size)               ; return self(); }
    S& usesScrollButtons(bool useButtons)                           { t->setUsesScrollButtons(useButtons); return self(); }
    S& documentMode(bool set)                                       { t->setDocumentMode(set)            ; return self(); }
    S& tabBarAutoHide(bool enabled)                                 { t->setTabBarAutoHide(enabled)      ; return self(); }
    S& currentIndex(int index)                                      { t->setCurrentIndex(index)          ; return self(); }
    S& currentWidget(QWidget *widget)                               { t->setCurrentWidget(widget)        ; return self(); }

    N_SIGNAL(onCurrentChanged     , QTabWidget::currentChanged     )
    N_SIGNAL(onTabCloseRequested  , QTabWidget::tabCloseRequested  )
    N_SIGNAL(onTabBarClicked      , QTabWidget::tabBarClicked      )
    N_SIGNAL(onTabBarDoubleClicked, QTabWidget::tabBarDoubleClicked)

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
