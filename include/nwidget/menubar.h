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

    S& items(std::initializer_list<MenuBarItem> items) { addItems(items); return self(); }
};

N_DECLARE_BUILDER(MenuBar, MenuBarBuilder, QMenuBar)



template <typename T>
class MenuBarIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool, defaultUp    , N_GETTER(isDefaultUp    ), N_SETTER(setDefaultUp    ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, nativeMenuBar, N_GETTER(isNativeMenuBar), N_SETTER(setNativeMenuBar), N_NO_NOTIFY)
};

N_DECLARE_ID(MenuBar, MenuBarIdT, QMenuBar)

}

#endif // NWIDGET_MENUBAR_H
