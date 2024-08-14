#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

#include "menu.h"

namespace nw {

struct MenuBarItem
{
    std::function<void(QMenuBar*)> addTo;

    MenuBarItem(QMenu* menu) { addTo = [menu](QMenuBar* bar){ bar->addMenu(menu); }; }

    template<typename S, typename T> MenuBarItem(const MenuBuilder<S, T>& menu) : MenuBarItem((QMenu*)menu) {}

    MenuBarItem(ItemGenerator<MenuBarItem> generator)
    {
        addTo = [generator](QMenuBar* bar){
            auto item = generator();
            while (item) {
                item->addTo(bar);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class MenuBarBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    MenuBarBuilder()                                                    : WidgetBuilder<S, T>(new T) {}
    MenuBarBuilder(std::initializer_list<MenuBarItem> menus)            : WidgetBuilder<S, T>(new T) { addMenus(menus); }
    explicit MenuBarBuilder(T* target)                                  : WidgetBuilder<S, T>(target) {}
    MenuBarBuilder(T* target, std::initializer_list<MenuBarItem> menus) : WidgetBuilder<S, T>(target) { addMenus(menus); }

private:
    void addMenus(std::initializer_list<MenuBarItem> menus)
    {
        auto menu = menus.begin();
        auto end = menus.end();
        while (menu != menus.end())
        {
            menu->addTo(t);
            ++menu;
        }
    }
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
