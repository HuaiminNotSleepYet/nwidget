#ifndef MENU_H
#define MENU_H

#include <QMenu>

#include "widget.h"

namespace nw {

template<typename S, typename T> class ActionBuilder;
template<typename S, typename T> class MenuBuilder;

class MenuItem : public BuilderItem<QMenu>
{
public:
    enum SpearatorType { Spearator };

    MenuItem(SpearatorType)   : BuilderItem([      ](QMenu* m){ m->addSeparator();    }) {}
    MenuItem(QAction* action) : BuilderItem([action](QMenu* m){ m->addAction(action); }) {}
    MenuItem(QMenu* menu)     : BuilderItem([menu  ](QMenu* m){ m->addMenu(menu);     }) {}

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
    explicit MenuBuilder(T* target)                                                     : WidgetBuilder<S, T>(target) {}
    MenuBuilder(T* target, std::initializer_list<MenuItem> items)                       : WidgetBuilder<S, T>(target) { addItems(items); }
    MenuBuilder(T* target, const QString& title, std::initializer_list<MenuItem> items) : WidgetBuilder<S, T>(target) { t->setTitle(title); addItems(items); }

    S& item(std::initializer_list<MenuItem> items) { addItems(items); return self(); }

    S& icon(const QIcon& ico)  { t->setIcon(ico); return self(); }
    S& title(const QString& s) { t->setTitle(s); return self(); }
};

N_DECL_BUILDER(MenuBuilder, QMenu, Menu);

}

#endif // MENU_H
