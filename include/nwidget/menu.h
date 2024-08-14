#ifndef MENU_H
#define MENU_H

#include <QMenu>

#include "widget.h"

namespace nw {

template<typename S, typename T> class ActionBuilder;
template<typename S, typename T> class MenuBuilder;

struct MenuItem
{
    std::function<void(QMenu*)> addTo;

    enum SpearatorType { Spearator };

    MenuItem(SpearatorType)   { addTo = [](QMenu* m){ m->addSeparator(); }; }
    MenuItem(QAction* action) { addTo = [action](QMenu* m){ m->addAction(action); }; }
    MenuItem(QMenu* menu)     { addTo = [menu](QMenu* m){ m->addMenu(menu); }; }

    template<typename S, typename T> MenuItem(const ActionBuilder<S, T>& action) { addTo = [action = action.operator T*()](QMenu* m){ m->addAction(action); }; }
    template<typename S, typename T> MenuItem(const MenuBuilder<S, T>& menu)     { addTo = [menu = menu.operator T*()](QMenu* m){ m->addMenu(menu); }; }

    MenuItem(ItemGenerator<MenuItem> generator)
    {
        addTo = [generator](QMenu* m){
            auto item = generator();
            while (item) {
                item->addTo(m);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class MenuBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    MenuBuilder()                                                            : WidgetBuilder<S, T>(new T) {}
    MenuBuilder(std::initializer_list<MenuItem> items)                       : WidgetBuilder<S, T>(new T) { addItems(items); }
    explicit MenuBuilder(T* target)                                          : WidgetBuilder<S, T>(target) {}
    MenuBuilder(T* target, std::initializer_list<MenuItem> items)            : WidgetBuilder<S, T>(target) { addItems(items); }
    MenuBuilder(const QString& title, std::initializer_list<MenuItem> items) : WidgetBuilder<S, T>(new T(title)) { addItems(items); }

    S& icon(const QIcon& ico)  { t->setIcon(ico); return self(); }
    S& title(const QString& s) { t->setTitle(s); return self(); }

private:
    void addItems(std::initializer_list<MenuItem> items)
    {
        auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
        {
            i->addTo(t);
        }
    }
};

N_BUILDER_IMPL(MenuBuilder, QMenu, Menu);

}

#endif // MENU_H
