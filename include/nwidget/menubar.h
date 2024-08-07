#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

#include "menu.h"

namespace nw {

template<typename S, typename T>
class MenuBarBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    MenuBarBuilder()                                             : WidgetBuilder<S, T>(new T) {}
    MenuBarBuilder(std::initializer_list<Menu> menus)            : WidgetBuilder<S, T>(new T) { addMenus(menus); }
    explicit MenuBarBuilder(T* target)                           : WidgetBuilder<S, T>(target) {}
    MenuBarBuilder(T* target, std::initializer_list<Menu> menus) : WidgetBuilder<S, T>(target) { addMenus(menus); }

private:
    void addMenus(std::initializer_list<Menu> menus)
    {
        auto menu = menus.begin();
        auto end = menus.end();
        while (menu != menus.end())
        {
            t->addMenu(*menu);
            ++menu;
        }
    }
};

N_BUILDER_IMPL(MenuBarBuilder, QMenuBar, MenuBar);

}

#endif // MENUBAR_H
