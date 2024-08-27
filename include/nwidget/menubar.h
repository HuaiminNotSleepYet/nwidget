#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

#include "menu.h"

namespace nw {

class MenuBarItem : public BuilderItem<QMenuBar>
{
public:
    MenuBarItem(QMenu* menu) : BuilderItem([menu](QMenuBar* bar){ bar->addMenu(menu); }) {}

    template<typename S, typename T> MenuBarItem(const MenuBuilder<S, T>& menu) : MenuBarItem((T*)menu) {}

    MenuBarItem(ItemGenerator<MenuBarItem> generator)
        : BuilderItem(generator)
    {}
};

template<typename S, typename T>
class MenuBarBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    MenuBarBuilder()                                                    : WidgetBuilder<S, T>(new T) {}
    MenuBarBuilder(std::initializer_list<MenuBarItem> menus)            : WidgetBuilder<S, T>(new T) { addItems(menus); }
    explicit
    MenuBarBuilder(T* target)                                           : WidgetBuilder<S, T>(target) {}
    MenuBarBuilder(T* target, std::initializer_list<MenuBarItem> menus) : WidgetBuilder<S, T>(target) { addItems(menus); }

    N_BUILDER_PROPERTY(bool, defaultUp    , setDefaultUp    )
    N_BUILDER_PROPERTY(bool, nativeMenuBar, setNativeMenuBar)

    S& items(std::initializer_list<MenuBarItem> items) { addItems(items); return self(); }
};

N_DECL_BUILDER(MenuBarBuilder, QMenuBar, MenuBar);



template <typename T>
class MenuBarIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool, defaultUp    , N_GETTER(isDefaultUp    ), N_SETTER(setDefaultUp    ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, nativeMenuBar, N_GETTER(isNativeMenuBar), N_SETTER(setNativeMenuBar), N_NO_NOTIFY)
};

using MenuBarId = MenuBarIdT<QMenuBar>;

}

#endif // MENUBAR_H
