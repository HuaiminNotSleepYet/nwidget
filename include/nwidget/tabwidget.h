#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>

#include "widget.h"

namespace nw {

struct TabWidgetItem
{
    std::function<void(QTabWidget*)> addTo;

    TabWidgetItem(const QString& label, QWidget* page)                    { addTo = [label, page](QTabWidget* tab){ tab->addTab(page, label); }; }
    TabWidgetItem(const QIcon& icon, const QString& label, QWidget* page) { addTo = [icon, label, page](QTabWidget* tab){ tab->addTab(page, icon, label); }; }
};

template<typename S, typename T>
class TabWidgetBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    TabWidgetBuilder()                                                      : WidgetBuilder<S, T>(new T) {}
    TabWidgetBuilder(std::initializer_list<TabWidgetItem> pages)            : WidgetBuilder<S, T>(new T) { applyPages(pages); }
    explicit TabWidgetBuilder(T* target)                                    : WidgetBuilder<S, T>(target) {}
    TabWidgetBuilder(T* target, std::initializer_list<TabWidgetItem> pages) : WidgetBuilder<S, T>(target) { applyPages(pages); }

private:
    inline void applyPages(std::initializer_list<TabWidgetItem> pages)
    {
        auto end = pages.end();
        for (auto i = pages.begin(); i != end; ++i)
            i->addTo(t);
    }
};

N_BUILDER_IMPL(TabWidgetBuilder, QTabWidget, TabWidget);

}

#endif // TABWIDGET_H
