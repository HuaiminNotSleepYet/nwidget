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
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    MenuBarBuilder()                                                    : WidgetBuilder<S, T>(new T) {}
    MenuBarBuilder(std::initializer_list<MenuBarItem> menus)            : WidgetBuilder<S, T>(new T) { addItems(menus); }
    explicit MenuBarBuilder(T* target)                                  : WidgetBuilder<S, T>(target) {}
    MenuBarBuilder(T* target, std::initializer_list<MenuBarItem> menus) : WidgetBuilder<S, T>(target) { addItems(menus); }

    S& item(std::initializer_list<MenuBarItem> items) { addItems(items); return self(); }
};

N_BUILDER_IMPL(MenuBarBuilder, QMenuBar, MenuBar);



template <typename T>
class MenuBarRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

    N_PROPERTY(bool, defaultUp    , N_GETTER(isDefaultUp    ), N_SETTER(setDefaultUp    ), N_NO_NOTIFY)
    N_PROPERTY(bool, nativeMenuBar, N_GETTER(isNativeMenuBar), N_SETTER(setNativeMenuBar), N_NO_NOTIFY)
};

using MenuBarRef = MenuBarRefT<QMenuBar>;

}

#endif // MENUBAR_H
