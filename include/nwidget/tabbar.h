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

    N_ID_PROPERTY(Shape            , shape                    , N_READ shape                     N_WRITE setShape                    )
    N_ID_PROPERTY(int              , currentIndex             , N_READ currentIndex              N_WRITE setCurrentIndex             N_NOTIFY currentChanged)
    N_ID_PROPERTY(int              , count                    , N_READ count                                                         )
    N_ID_PROPERTY(bool             , drawBase                 , N_READ drawBase                  N_WRITE setDrawBase                 )
    N_ID_PROPERTY(QSize            , iconSize                 , N_READ iconSize                  N_WRITE setIconSize                 )
    N_ID_PROPERTY(Qt::TextElideMode, elideMode                , N_READ elideMode                 N_WRITE setElideMode                )
    N_ID_PROPERTY(bool             , usesScrollButtons        , N_READ usesScrollButtons         N_WRITE setUsesScrollButtons        )
    N_ID_PROPERTY(bool             , tabsClosable             , N_READ tabsClosable              N_WRITE setTabsClosable             )
    N_ID_PROPERTY(SelectionBehavior, selectionBehaviorOnRemove, N_READ selectionBehaviorOnRemove N_WRITE setSelectionBehaviorOnRemove)
    N_ID_PROPERTY(bool             , expanding                , N_READ expanding                 N_WRITE setExpanding                )
    N_ID_PROPERTY(bool             , movable                  , N_READ isMovable                 N_WRITE setMovable                  )
    N_ID_PROPERTY(bool             , documentMode             , N_READ documentMode              N_WRITE setDocumentMode             )
    N_ID_PROPERTY(bool             , autoHide                 , N_READ autoHide                  N_WRITE setAutoHide                 )
    N_ID_PROPERTY(bool             , changeCurrentOnDrag      , N_READ changeCurrentOnDrag       N_WRITE setChangeCurrentOnDrag      )
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

    N_BUILDER_SETTER S& items(std::initializer_list<TabBarItem> items) { addItems(items); return self(); }

    N_BUILDER_SETTER2(tabEnabled       , setTabEnabled       )
    N_BUILDER_SETTER2(tabVisible       , setTabVisible       )
    N_BUILDER_SETTER2(tabTextColor     , setTabTextColor     )
    N_BUILDER_SETTER1(ElideMode        , setElideMode        )
    N_BUILDER_SETTER2(tabData          , setTabData          )
    N_BUILDER_SETTER3(tabButton        , setTabButton        )
#if QT_CONFIG(tooltip)
    N_BUILDER_SETTER2(tabToolTip       , setTabToolTip       )
#endif
#if QT_CONFIG(whatsthis)
    N_BUILDER_SETTER2(tabWhatsThis     , setTabWhatsThis     )
#endif
#if QT_CONFIG(accessibility)
    N_BUILDER_SETTER2(accessibleTabName, setAccessibleTabName)
#endif

    N_BUILDER_SIGNAL(onCurrentChanged     , currentChanged     )
    N_BUILDER_SIGNAL(onTabCloseRequested  , tabCloseRequested  )
    N_BUILDER_SIGNAL(onTabMoved           , tabMoved           )
    N_BUILDER_SIGNAL(onTabBarClicked      , tabBarClicked      )
    N_BUILDER_SIGNAL(onTabBarDoubleClicked, tabBarDoubleClicked)
};

N_DECLARE_BUILDER(TabBar, TabBarBuilder, QTabBar)

}

N_REGISTER_ID(nwidget::TabBar, QTabBar)
N_REGISTER_BUILDER(nwidget::TabBar, QTabBar)

#endif // NWIDGET_TABBAR_H
