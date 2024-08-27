#ifndef TABBAR_H
#define TABBAR_H

#include <QTabBar>

#include "widget.h"

namespace nw {

class TabBarItem : public BuilderItem<QTabBar>
{
public:
    TabBarItem(const QString& text)                    : BuilderItem([text      ](QTabBar* bar){ bar->addTab(text);       }) {}
    TabBarItem(const QIcon& icon, const QString& text) : BuilderItem([icon, text](QTabBar* bar){ bar->addTab(icon, text); }) {}

    TabBarItem(ItemGenerator<TabBarItem> generator)
        : BuilderItem(generator)
    {}
};

template<typename S, typename T>
class TabBarBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    TabBarBuilder()                                                   : WidgetBuilder<S, T>(new T) {}
    TabBarBuilder(std::initializer_list<TabBarItem> items)            : WidgetBuilder<S, T>(new T) { addItems(items); }
    explicit
    TabBarBuilder(T* target)                                          : WidgetBuilder<S, T>(target) {}
    TabBarBuilder(T* target, std::initializer_list<TabBarItem> items) : WidgetBuilder<S, T>(target) { addItems(items); }


    S& item(std::initializer_list<TabBarItem> items)               { addItems(items)                     ; return self(); }

    S& shape(QTabBar::Shape shape)                                 { t->setShape(shape)                  ; return self(); }
    S& tabEnabled(int index, bool enabled)                         { t->setTabEnabled(index, enabled)    ; return self(); }
    S& tabVisible(int index, bool visible)                         { t->setTabVisible(index, visible)    ; return self(); }
    S& tabTextColor(int index, const QColor &color)                { t->setTabTextColor(index, color)    ; return self(); }
    S& ElideMode(Qt::TextElideMode mode)                           { t->setElideMode(mode)               ; return self(); }
#if QT_CONFIG(tooltip)
    S& tabToolTip(int index, const QString &tip)                   { t->setTabToolTip(index, tip)        ; return self(); }
#endif
#if QT_CONFIG(whatsthis)
    S& tabWhatsThis(int index, const QString &text)                { t->setTabWhatsThis(index, text)     ; return self(); }
#endif
    S& tabData(int index, const QVariant &data)                    { t->setTabData(index, data)          ; return self(); }
    S& drawBase(bool drawTheBase)                                  { t->setDrawBase(drawTheBase)         ; return self(); }
    S& iconSize(const QSize &size)                                 { t->setIconSize(size)                ; return self(); }
    S& usesScrollButtons(bool useButtons)                          { t->setUsesScrollButtons(useButtons) ; return self(); }
    S& tabsClosable(bool closable)                                 { t->setTabsClosable(closable)        ; return self(); }
    S& tabButton(int index, QTabBar::ButtonPosition p, QWidget* w) { t->setTabButton(index, p, w)        ; return self(); }
    S& selectionBehaviorOnRemove(QTabBar::SelectionBehavior b)     { t->setSelectionBehaviorOnRemove(b)  ; return self(); }
    S& expanding(bool enabled)                                     { t->setExpanding(enabled)            ; return self(); }
    S& movable(bool movable)                                       { t->setMovable(movable)              ; return self(); }
    S& documentMode(bool set)                                      { t->setDocumentMode(set)             ; return self(); }
    S& autoHide(bool hide)                                         { t->setAutoHide(hide)                ; return self(); }
    S& changeCurrentOnDrag(bool change)                            { t->setChangeCurrentOnDrag(change)   ; return self(); }
#if QT_CONFIG(accessibility)
    S& accessibleTabName(int index, const QString &name)           { t->setAccessibleTabName(index, name); return self(); }
#endif
    S& currentIndex(int index)                                     { t->setCurrentIndex(index)           ; return self(); }

    N_BUILDER_SIGNAL(onCurrentChanged     , currentChanged     )
    N_BUILDER_SIGNAL(onTabCloseRequested  , tabCloseRequested  )
    N_BUILDER_SIGNAL(onTabMoved           , tabMoved           )
    N_BUILDER_SIGNAL(onTabBarClicked      , tabBarClicked      )
    N_BUILDER_SIGNAL(onTabBarDoubleClicked, tabBarDoubleClicked)
};

N_DECL_BUILDER(TabBarBuilder, QTabBar, TabBar);

}

#endif // TABBAR_H
