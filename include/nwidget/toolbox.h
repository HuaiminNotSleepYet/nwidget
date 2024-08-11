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



template <typename T>
class ToolBoxRefT : public FrameRefT<T>
{
public:
    using FrameRefT<T>::FrameRefT;

    N_PROPERTY(int, currentIndex, N_GETTER(currentIndex), N_SETTER(setCurrentIndex), N_NOTIFY(currentChanged))
    N_PROPERTY(int, count       , N_GETTER(count       ), N_NO_SETTER              , N_NO_NOTIFY             )
};

using ToolBoxRef = ToolBoxRefT<QToolBox>;

}

#endif // TOOLBOX_H
