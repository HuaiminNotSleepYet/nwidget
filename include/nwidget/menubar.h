#ifndef NWIDGET_MENUBAR_H
#define NWIDGET_MENUBAR_H

#include <QMenuBar>

#include "menu.h"

namespace nwidget {

class MenuBarItem : public BuilderItem<QMenuBar>
{
public:
    MenuBarItem(QMenu* menu) : BuilderItem([menu](QMenuBar* bar){ bar->addMenu(menu); }) {}

    template<typename T> MenuBarItem(const MenuIdT<T>& menu): MenuBarItem((T*)menu) {}

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

    N_BUILDER_SETTER S& items(std::initializer_list<MenuBarItem> items) { addItems(items); return self(); }
};

N_DECLARE_BUILDER(MenuBar, MenuBarBuilder, QMenuBar)



template <typename T>
class MenuBarIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool, defaultUp    , N_READ isDefaultUp     N_WRITE setDefaultUp    )
    N_ID_PROPERTY(bool, nativeMenuBar, N_READ isNativeMenuBar N_WRITE setNativeMenuBar)
};

N_DECLARE_ID(MenuBar, MenuBarIdT, QMenuBar)

}

N_REGISTER_ID(nwidget::MenuBar, QMenuBar)
N_REGISTER_BUILDER(nwidget::MenuBar, QMenuBar)

#endif // NWIDGET_MENUBAR_H
