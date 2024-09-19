#ifndef NWIDGET_TABWIDGET_H
#define NWIDGET_TABWIDGET_H

#include <QTabWidget>

#include "widget.h"

namespace nwidget {

class TabWidgetItem : public BuilderItem<QTabWidget>
{
public:
    TabWidgetItem(const QString& label, QWidget* page)                    : BuilderItem([label, page](QTabWidget* tab){ tab->addTab(page, label); }) {}
    TabWidgetItem(const QIcon& icon, const QString& label, QWidget* page) : BuilderItem([icon, label, page](QTabWidget* tab){ tab->addTab(page, icon, label); }) {}

    TabWidgetItem(ItemGenerator<TabWidgetItem> generator)
        : BuilderItem(generator)
    {}
};

template<typename S, typename T>
class TabWidgetBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    TabWidgetBuilder()                                                      : WidgetBuilder<S, T>(new T) {}
    TabWidgetBuilder(std::initializer_list<TabWidgetItem> pages)            : WidgetBuilder<S, T>(new T) { addItems(pages); }
    explicit
    TabWidgetBuilder(T* target)                                             : WidgetBuilder<S, T>(target) {}
    TabWidgetBuilder(T* target, std::initializer_list<TabWidgetItem> pages) : WidgetBuilder<S, T>(target) { addItems(pages); }


    N_BUILDER_PROPERTY(QTabWidget::TabPosition, tabPosition      , setTabPosition      )
    N_BUILDER_PROPERTY(QTabWidget::TabShape   , tabShape         , setTabShape         )
    N_BUILDER_PROPERTY(int                    , currentIndex     , setCurrentIndex     )
    N_BUILDER_PROPERTY(QSize                  , iconSize         , setIconSize         )
    N_BUILDER_PROPERTY(Qt::TextElideMode      , elideMode        , setElideMode        )
    N_BUILDER_PROPERTY(bool                   , usesScrollButtons, setUsesScrollButtons)
    N_BUILDER_PROPERTY(bool                   , documentMode     , setDocumentMode     )
    N_BUILDER_PROPERTY(bool                   , tabsClosable     , setTabsClosable     )
    N_BUILDER_PROPERTY(bool                   , movable          , setMovable          )
    N_BUILDER_PROPERTY(bool                   , tabBarAutoHide   , setTabBarAutoHide   )


    N_BUILDER_SETTER S& items(std::initializer_list<TabWidgetItem> pages) { addItems(pages); return self(); }

    N_BUILDER_SETTER2(tabEnabled   , setTabEnabled   )
    N_BUILDER_SETTER2(tabVisible   , setTabVisible   )
    N_BUILDER_SETTER2(tabText      , setTabText      )
    N_BUILDER_SETTER2(tabIcon      , setTabIcon      )
    N_BUILDER_SETTER1(currentWidget, setCurrentWidget)

    N_BUILDER_SETTER S& cornerWidget(QWidget * w, Qt::Corner c = Qt::TopRightCorner)  { t->setCornerWidget(w, c); return self(); }

#if QT_CONFIG(tooltip)
    N_BUILDER_SETTER2(tabToolTip   , setTabToolTip  )
#endif
#if QT_CONFIG(whatsthis)
    N_BUILDER_SETTER2(tabWhatsThis , setTabWhatsThis)
#endif


    N_BUILDER_SIGNAL(onCurrentChanged     , currentChanged     )
    N_BUILDER_SIGNAL(onTabCloseRequested  , tabCloseRequested  )
    N_BUILDER_SIGNAL(onTabBarClicked      , tabBarClicked      )
    N_BUILDER_SIGNAL(onTabBarDoubleClicked, tabBarDoubleClicked)
};

N_DECLARE_BUILDER_N(TabWidget, TabWidgetBuilder, QTabWidget);



template <typename T>
class TabWidgetIdT : public WidgetIdT<T>
{
    using TabPosition = QTabWidget::TabPosition;
    using TabShape = QTabWidget::TabShape;

public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(TabPosition      , tabPosition      , N_READ tabPosition       N_WRITE setTabPosition      )
    N_ID_PROPERTY(TabShape         , tabShape         , N_READ tabShape          N_WRITE setTabShape         )
    N_ID_PROPERTY(int              , currentIndex     , N_READ currentIndex      N_WRITE setCurrentIndex     N_NOTIFY currentChanged)
    N_ID_PROPERTY(int              , count            , N_READ count                                         )
    N_ID_PROPERTY(QSize            , iconSize         , N_READ iconSize          N_WRITE setIconSize         )
    N_ID_PROPERTY(Qt::TextElideMode, elideMode        , N_READ elideMode         N_WRITE setElideMode        )
    N_ID_PROPERTY(bool             , usesScrollButtons, N_READ usesScrollButtons N_WRITE setUsesScrollButtons)
    N_ID_PROPERTY(bool             , documentMode     , N_READ documentMode      N_WRITE setDocumentMode     )
    N_ID_PROPERTY(bool             , tabsClosable     , N_READ tabsClosable      N_WRITE setTabsClosable     )
    N_ID_PROPERTY(bool             , movable          , N_READ isMovable         N_WRITE setMovable          )
    N_ID_PROPERTY(bool             , tabBarAutoHide   , N_READ tabBarAutoHide    N_WRITE setTabBarAutoHide   )
};

N_DECLARE_ID_N(TabWidget, TabWidgetIdT, QTabWidget)

}

#endif // NWIDGET_TABWIDGET_H
