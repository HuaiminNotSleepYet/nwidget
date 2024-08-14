#ifndef BOXLAYOUT_H
#define BOXLAYOUT_H

#include <QBoxLayout>

#include "layout.h"

namespace nw {

struct BoxLayoutItem
{
    std::function<void(QBoxLayout*)> addTo;

    enum SpacingType { Spacing };
    enum StretchType { Stretch };
    enum StrutType   { Strut   };

    BoxLayoutItem(QWidget* widget, int stretch = 0, Qt::Alignment align = Qt::Alignment())
    { addTo = [widget, stretch, align](QBoxLayout* l){l->addWidget(widget, stretch, align); }; }

    BoxLayoutItem(QLayout* layout, int stretch = 0)
    { addTo = [layout, stretch](QBoxLayout* l){l->addLayout(layout, stretch); }; }

    BoxLayoutItem(QLayoutItem* item)
    { addTo = [item](QBoxLayout* l){l->addItem(item); }; }

    template<typename S, typename T>
    BoxLayoutItem(const WidgetBuilder<S, T>& widget, int stretch = 0, Qt::Alignment align = Qt::Alignment())
        : BoxLayoutItem(widget.operator T*(), stretch, align) {}

    template<typename S, typename T>
    BoxLayoutItem(const LayoutBuilder<S, T>& layout, int stretch = 0)
        : BoxLayoutItem(layout.operator T*(), stretch) {}

    template<typename S, typename T>
    BoxLayoutItem(const LayoutItemBuilder<S, T>& item)
        : BoxLayoutItem(item.operator T*()) {}

    BoxLayoutItem(SpacingType, int size)        { addTo = [size   ](QBoxLayout* l) { l->addSpacing(size);    }; }
    BoxLayoutItem(StretchType, int stretch = 0) { addTo = [stretch](QBoxLayout* l) { l->addStretch(stretch); }; }
    BoxLayoutItem(StrutType  , int size)        { addTo = [size   ](QBoxLayout* l) { l->addStrut(size);      }; }

    BoxLayoutItem(ItemGenerator<BoxLayoutItem> generator)
    {
        addTo = [generator](QBoxLayout* l){
            auto item = generator();
            while (item) {
                item->addTo(l);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class BoxLayoutBuilder : public LayoutBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(LayoutBuilder, S, T)

public:
    explicit BoxLayoutBuilder(QBoxLayout::Direction direction)   : LayoutBuilder<S, T>(new T(direction)) {}
    BoxLayoutBuilder(QBoxLayout::Direction direction,
                     std::initializer_list<BoxLayoutItem> items) : LayoutBuilder<S, T>(new T(direction)) { addItems(items); }

    explicit BoxLayoutBuilder(T* target)                         : LayoutBuilder<S, T>(target) {}
    BoxLayoutBuilder(T* target, QBoxLayout::Direction direction) : LayoutBuilder<S, T>(target) { t->setDirection(direction); }
    BoxLayoutBuilder(T* target, QBoxLayout::Direction direction,
                     std::initializer_list<BoxLayoutItem> items) : LayoutBuilder<S, T>(target) { t->setDirection(direction); addItems(items); }

protected:
    void addItems(std::initializer_list<BoxLayoutItem> items)
    {
        auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(LayoutItemBuilder<S, T>::t);
    }
};

N_BUILDER_IMPL(BoxLayoutBuilder, QBoxLayout , BoxLayout);

class HBoxLayout : public BoxLayoutBuilder<HBoxLayout, QHBoxLayout> {
public:
    using Layout = QHBoxLayout;

    HBoxLayout()                                                           : BoxLayoutBuilder<HBoxLayout, Layout>(new Layout) {}
    HBoxLayout(std::initializer_list<BoxLayoutItem> items)                 : BoxLayoutBuilder<HBoxLayout, Layout>(new Layout) { addItems(items); }
    explicit HBoxLayout(Layout* target)                                    : BoxLayoutBuilder<HBoxLayout, Layout>(target) {}
    HBoxLayout(Layout* target, std::initializer_list<BoxLayoutItem> items) : BoxLayoutBuilder<HBoxLayout, Layout>(target) { addItems(items); }
};

class VBoxLayout : public BoxLayoutBuilder<VBoxLayout, QVBoxLayout> {
public:
    using Layout = QVBoxLayout;

    VBoxLayout()                                                           : BoxLayoutBuilder<VBoxLayout, Layout>(new Layout) {}
    VBoxLayout(std::initializer_list<BoxLayoutItem> items)                 : BoxLayoutBuilder<VBoxLayout, Layout>(new Layout) { addItems(items); }
    explicit VBoxLayout(Layout* target)                                    : BoxLayoutBuilder<VBoxLayout, Layout>(target) {}
    VBoxLayout(Layout* target, std::initializer_list<BoxLayoutItem> items) : BoxLayoutBuilder<VBoxLayout, Layout>(target) { addItems(items); }
};

}

#endif // BOXLAYOUT_H
