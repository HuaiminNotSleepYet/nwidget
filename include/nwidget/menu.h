#ifndef NWIDGET_MENU_H
#define NWIDGET_MENU_H

#include <QMenu>

#include "widget.h"

namespace nwidget {

template<typename T> class ActionIdT;
template<typename S, typename T> class ActionBuilder;
template<typename S, typename T> class MenuBuilder;

template<typename T>
class MenuIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool   , tearOffEnabled       , N_READ isTearOffEnabled      N_WRITE setTearOffEnabled       )
    N_ID_PROPERTY(QString, title                , N_READ title                 N_WRITE setTitle                )
    N_ID_PROPERTY(QIcon  , icon                 , N_READ icon                  N_WRITE setIcon                 )
    N_ID_PROPERTY(bool   , separatorsCollapsible, N_READ separatorsCollapsible N_WRITE setSeparatorsCollapsible)
    N_ID_PROPERTY(bool   , toolTipsVisible      , N_READ toolTipsVisible       N_WRITE setToolTipsVisible      )
};

N_DECLARE_ID(Menu, MenuIdT, QMenu)



class MenuItem : public BuilderItem<QMenu>
{
public:
    enum SpearatorType { Spearator };

    MenuItem(SpearatorType)   : BuilderItem([      ](QMenu* m){ m->addSeparator();    }) {}
    MenuItem(QAction* action) : BuilderItem([action](QMenu* m){ m->addAction(action); }) {}
    MenuItem(QMenu* menu)     : BuilderItem([menu  ](QMenu* m){ m->addMenu(menu);     }) {}

    template<typename T> MenuItem(const ActionIdT<T>& action) : MenuItem((T*)action) {}
    template<typename T> MenuItem(const MenuIdT  <T>& menu  ) : MenuItem((T*)menu  ) {}

    template<typename S, typename T> MenuItem(const ActionBuilder<S, T>& action) : MenuItem((T*)action) {}
    template<typename S, typename T> MenuItem(const MenuBuilder  <S, T>& menu  ) : MenuItem((T*)menu  ) {}

    MenuItem(ItemGenerator<MenuItem> generator)
        : BuilderItem(generator)
    {}
};

template<typename S, typename T>
class MenuBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    MenuBuilder()                                                                       : WidgetBuilder<S, T>(new T) {}
    MenuBuilder(std::initializer_list<MenuItem> items)                                  : WidgetBuilder<S, T>(new T) { addItems(items); }
    MenuBuilder(const QString& title, std::initializer_list<MenuItem> items)            : WidgetBuilder<S, T>(new T(title)) { addItems(items); }
    explicit
    MenuBuilder(T* target)                                                              : WidgetBuilder<S, T>(target) {}
    MenuBuilder(T* target, std::initializer_list<MenuItem> items)                       : WidgetBuilder<S, T>(target) { addItems(items); }
    MenuBuilder(T* target, const QString& title, std::initializer_list<MenuItem> items) : WidgetBuilder<S, T>(target) { t->setTitle(title); addItems(items); }

    N_BUILDER_SETTER S& items(std::initializer_list<MenuItem> items) { addItems(items); return self(); }
    N_BUILDER_SETTER1(icon , setIcon )
    N_BUILDER_SETTER1(title, setTitle)
};

N_DECLARE_BUILDER(Menu, MenuBuilder, QMenu)

}

#endif // NWIDGET_MENU_H
