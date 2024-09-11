#ifndef NWIDGET_TOOLBOX_H
#define NWIDGET_TOOLBOX_H

#include <QToolBox>

#include "frame.h"

namespace nwidget {

class ToolBoxItem : public BuilderItem<QToolBox>
{
public:
    ToolBoxItem(const QString& text, QWidget* item)                    : BuilderItem([item, text](QToolBox* box){ box->addItem(item, text); }) {}
    ToolBoxItem(const QIcon& icon, const QString& text, QWidget* item) : BuilderItem([item, icon, text](QToolBox* box){ box->addItem(item, icon, text); }) {}

    ToolBoxItem(ItemGenerator<ToolBoxItem> generator)
        : BuilderItem(generator)
    {}
};

template<typename S, typename T>
class ToolBoxBuilder : public FrameBuilder<S, T>
{
    N_BUILDER

public:
    ToolBoxBuilder()                                         : FrameBuilder<S, T>(new T) {}
    ToolBoxBuilder(std::initializer_list<ToolBoxItem> items) : FrameBuilder<S, T>(new T) { addItems(items); }
    explicit
    ToolBoxBuilder(T* target)                                           : FrameBuilder<S, T>(target) {}
    ToolBoxBuilder(T* target, std::initializer_list<ToolBoxItem> items) : FrameBuilder<S, T>(target) { addItems(items); }


    N_BUILDER_PROPERTY(int, currentIndex, setCurrentIndex)
};

N_DECLARE_BUILDER(ToolBox, ToolBoxBuilder, QToolBox);



template <typename T>
class ToolBoxIdT : public FrameIdT<T>
{
public:
    using FrameIdT<T>::FrameIdT;

    N_ID_PROPERTY(int, currentIndex, N_GETTER(currentIndex), N_SETTER(setCurrentIndex), N_NOTIFY(currentChanged))
    N_ID_PROPERTY(int, count       , N_GETTER(count       ), N_NO_SETTER              , N_NO_NOTIFY             )
};

N_DECLARE_ID(ToolBox, ToolBoxIdT, QToolBox)

}

#endif // NWIDGET_TOOLBOX_H
