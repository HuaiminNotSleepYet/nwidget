#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QToolBox>

#include "frame.h"

namespace nw {

struct ToolBoxItem
{
    std::function<void(QToolBox* box)> addTo;

    ToolBoxItem(const QString& text, QWidget* item)                    { addTo = [item, text](QToolBox* box){ box->addItem(item, text); }; }
    ToolBoxItem(const QIcon& icon, const QString& text, QWidget* item) { addTo = [item, icon, text](QToolBox* box){ box->addItem(item, icon, text); }; }

    ToolBoxItem(ItemGenerator<ToolBoxItem> generator)
    {
        addTo = [generator](QToolBox* box){
            auto item = generator();
            while (item) {
                item->addTo(box);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class ToolBoxBuilder : public FrameBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(FrameBuilder, S, T)

public:
    ToolBoxBuilder()                                                    : FrameBuilder<S, T>(new T) {}
    ToolBoxBuilder(std::initializer_list<ToolBoxItem> items)            : FrameBuilder<S, T>(new T) { applyItems(items); }
    ToolBoxBuilder(T* target)                                           : FrameBuilder<S, T>(target) {}
    ToolBoxBuilder(T* target, std::initializer_list<ToolBoxItem> items) : FrameBuilder<S, T>(target) { applyItems(items); }

private:
    void applyItems(std::initializer_list<ToolBoxItem> items)
    {
        auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
        {
            i->addTo(t);
        }
    }
};

N_BUILDER_IMPL(ToolBoxBuilder, QToolBox, ToolBox);

}

#endif // TOOLBOX_H
