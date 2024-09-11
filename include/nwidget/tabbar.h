#ifndef NWIDGET_TABBAR_H
#define NWIDGET_TABBAR_H

#include <QTabBar>

#include "widget.h"

namespace nwidget {

template<typename T>
class TabBarIdT : public WidgetIdT<T>
{
    using Shape = QTabBar::Shape;
    using ButtonPosition = QTabBar::ButtonPosition;
    using SelectionBehavior = QTabBar::SelectionBehavior;

public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(Shape            , shape                    , N_GETTER(shape                    ), N_SETTER(setShape                    ), N_NO_NOTIFY)
    N_ID_PROPERTY(int              , currentIndex             , N_GETTER(currentIndex             ), N_SETTER(setCurrentIndex             ), N_NOTIFY(currentChanged))
    N_ID_PROPERTY(int              , count                    , N_GETTER(count                    ), N_NO_SETTER                           , N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , drawBase                 , N_GETTER(drawBase                 ), N_SETTER(setDrawBase                 ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize            , iconSize                 , N_GETTER(iconSize                 ), N_SETTER(setIconSize                 ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::TextElideMode, elideMode                , N_GETTER(elideMode                ), N_SETTER(setElideMode                ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , usesScrollButtons        , N_GETTER(usesScrollButtons        ), N_SETTER(setUsesScrollButtons        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , tabsClosable             , N_GETTER(tabsClosable             ), N_SETTER(setTabsClosable             ), N_NO_NOTIFY)
    N_ID_PROPERTY(SelectionBehavior, selectionBehaviorOnRemove, N_GETTER(selectionBehaviorOnRemove), N_SETTER(setSelectionBehaviorOnRemove), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , expanding                , N_GETTER(expanding                ), N_SETTER(setExpanding                ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , movable                  , N_GETTER(isMovable                ), N_SETTER(setMovable                  ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , documentMode             , N_GETTER(documentMode             ), N_SETTER(setDocumentMode             ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , autoHide                 , N_GETTER(autoHide                 ), N_SETTER(setAutoHide                 ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , changeCurrentOnDrag      , N_GETTER(changeCurrentOnDrag      ), N_SETTER(setChangeCurrentOnDrag      ), N_NO_NOTIFY)
};

N_DECLARE_ID(TabBar, TabBarIdT, QTabBar)



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

    using Shape = QTabBar::Shape;
    using ButtonPosition = QTabBar::ButtonPosition;
    using SelectionBehavior = QTabBar::SelectionBehavior;

public:
    TabBarBuilder()                                                   : WidgetBuilder<S, T>(new T) {}
    TabBarBuilder(std::initializer_list<TabBarItem> items)            : WidgetBuilder<S, T>(new T) { addItems(items); }
    explicit
    TabBarBuilder(T* target)                                          : WidgetBuilder<S, T>(target) {}
    TabBarBuilder(T* target, std::initializer_list<TabBarItem> items) : WidgetBuilder<S, T>(target) { addItems(items); }


    N_BUILDER_PROPERTY(Shape            , shape                    , setShape                    )
    N_BUILDER_PROPERTY(int              , currentIndex             , setCurrentIndex             )
    N_BUILDER_PROPERTY(bool             , drawBase                 , setDrawBase                 )
    N_BUILDER_PROPERTY(QSize            , iconSize                 , setIconSize                 )
    N_BUILDER_PROPERTY(Qt::TextElideMode, elideMode                , setElideMode                )
    N_BUILDER_PROPERTY(bool             , usesScrollButtons        , setUsesScrollButtons        )
    N_BUILDER_PROPERTY(bool             , tabsClosable             , setTabsClosable             )
    N_BUILDER_PROPERTY(SelectionBehavior, selectionBehaviorOnRemove, setSelectionBehaviorOnRemove)
    N_BUILDER_PROPERTY(bool             , expanding                , setExpanding                )
    N_BUILDER_PROPERTY(bool             , movable                  , setMovable                  )
    N_BUILDER_PROPERTY(bool             , documentMode             , setDocumentMode             )
    N_BUILDER_PROPERTY(bool             , autoHide                 , setAutoHide                 )
    N_BUILDER_PROPERTY(bool             , changeCurrentOnDrag      , setChangeCurrentOnDrag      )

    S& items(std::initializer_list<TabBarItem> items)              { addItems(items)                     ; return self(); }

    S& tabEnabled(int index, bool enabled)                         { t->setTabEnabled(index, enabled)    ; return self(); }
    S& tabVisible(int index, bool visible)                         { t->setTabVisible(index, visible)    ; return self(); }
    S& tabTextColor(int index, const QColor &color)                { t->setTabTextColor(index, color)    ; return self(); }
    S& ElideMode(Qt::TextElideMode mode)                           { t->setElideMode(mode)               ; return self(); }
    S& tabData(int index, const QVariant &data)                    { t->setTabData(index, data)          ; return self(); }
    S& tabButton(int index, ButtonPosition p, QWidget* w)          { t->setTabButton(index, p, w)        ; return self(); }
#if QT_CONFIG(tooltip)
    S& tabToolTip(int index, const QString &tip)                   { t->setTabToolTip(index, tip)        ; return self(); }
#endif
#if QT_CONFIG(whatsthis)
    S& tabWhatsThis(int index, const QString &text)                { t->setTabWhatsThis(index, text)     ; return self(); }
#endif
#if QT_CONFIG(accessibility)
    S& accessibleTabName(int index, const QString &name)           { t->setAccessibleTabName(index, name); return self(); }
#endif

    N_BUILDER_SIGNAL(onCurrentChanged     , currentChanged     )
    N_BUILDER_SIGNAL(onTabCloseRequested  , tabCloseRequested  )
    N_BUILDER_SIGNAL(onTabMoved           , tabMoved           )
    N_BUILDER_SIGNAL(onTabBarClicked      , tabBarClicked      )
    N_BUILDER_SIGNAL(onTabBarDoubleClicked, tabBarDoubleClicked)
};

N_DECLARE_BUILDER(TabBar, TabBarBuilder, QTabBar);

}

#endif // NWIDGET_TABBAR_H
