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

    N_ID_PROPERTY(bool   , tearOffEnabled       , N_GETTER(isTearOffEnabled     ), N_SETTER(setTearOffEnabled       ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString, title                , N_GETTER(title                ), N_SETTER(setTitle                ), N_NO_NOTIFY)
    N_ID_PROPERTY(QIcon  , icon                 , N_GETTER(icon                 ), N_SETTER(setIcon                 ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool   , separatorsCollapsible, N_GETTER(separatorsCollapsible), N_SETTER(setSeparatorsCollapsible), N_NO_NOTIFY)
    N_ID_PROPERTY(bool   , toolTipsVisible      , N_GETTER(toolTipsVisible      ), N_SETTER(setToolTipsVisible      ), N_NO_NOTIFY)
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

    S& items(std::initializer_list<MenuItem> items) { addItems(items); return self(); }

    S& icon(const QIcon& ico)  { t->setIcon(ico); return self(); }
    S& title(const QString& s) { t->setTitle(s); return self(); }
};

N_DECLARE_BUILDER(Menu, MenuBuilder, QMenu)

}

#endif // NWIDGET_MENU_H
