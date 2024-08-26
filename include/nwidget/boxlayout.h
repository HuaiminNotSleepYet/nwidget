#ifndef BOXLAYOUT_H
#define BOXLAYOUT_H

#include <QBoxLayout>

#include "layout.h"

namespace nw {

class BoxLayoutItem : public BuilderItem<QBoxLayout>
{
public:
    enum SpacingType { Spacing };
    enum StretchType { Stretch };
    enum StrutType   { Strut   };

    BoxLayoutItem(QWidget* widget, int stretch = 0, Qt::Alignment align = Qt::Alignment())
        : BuilderItem([widget, stretch, align](QBoxLayout* l){l->addWidget(widget, stretch, align); })
    {}

    BoxLayoutItem(QLayout* layout, int stretch = 0)
        : BuilderItem([layout, stretch](QBoxLayout* l){l->addLayout(layout, stretch); })
    {}

    BoxLayoutItem(QLayoutItem* item)
        : BuilderItem([item](QBoxLayout* l){l->addItem(item); })
    {}

    template<typename S, typename T>
    BoxLayoutItem(const WidgetBuilder<S, T>& widget, int stretch = 0, Qt::Alignment align = Qt::Alignment())
        : BoxLayoutItem((T*)widget, stretch, align)
    {}

    template<typename S, typename T>
    BoxLayoutItem(const LayoutBuilder<S, T>& layout, int stretch = 0)
        : BoxLayoutItem((T*)layout, stretch)
    {}

    BoxLayoutItem(SpacingType, int size)        : BuilderItem([size   ](QBoxLayout* l) { l->addSpacing(size);    }) {}
    BoxLayoutItem(StretchType, int stretch = 0) : BuilderItem([stretch](QBoxLayout* l) { l->addStretch(stretch); }) {}
    BoxLayoutItem(StrutType  , int size)        : BuilderItem([size   ](QBoxLayout* l) { l->addStrut(size);      }) {}

    BoxLayoutItem(ItemGenerator<BoxLayoutItem> generator)
        : BuilderItem(generator)
    {}
};

template<typename S, typename T>
class BoxLayoutBuilder : public LayoutBuilder<S, T>
{
    N_BUILDER

public:
    explicit BoxLayoutBuilder(QBoxLayout::Direction direction)   : LayoutBuilder<S, T>(new T(direction)) {}
    BoxLayoutBuilder(QBoxLayout::Direction direction,
                     std::initializer_list<BoxLayoutItem> items) : LayoutBuilder<S, T>(new T(direction)) { addItems(items); }

    explicit BoxLayoutBuilder(T* target)                         : LayoutBuilder<S, T>(target) {}
    BoxLayoutBuilder(T* target, QBoxLayout::Direction direction) : LayoutBuilder<S, T>(target) { t->setDirection(direction); }
    BoxLayoutBuilder(T* target, QBoxLayout::Direction direction,
                     std::initializer_list<BoxLayoutItem> items) : LayoutBuilder<S, T>(target) { t->setDirection(direction); addItems(items); }

    S& items(std::initializer_list<LayoutItem> items) = delete;
    S& items(std::initializer_list<BoxLayoutItem> items) { addItems(items); return self(); }
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

using BoxLayoutId  = LayoutIdT<QBoxLayout>;
using HBoxLayoutId = LayoutIdT<QHBoxLayout>;
using VBoxLayoutId = LayoutIdT<QVBoxLayout>;

}

#endif // BOXLAYOUT_H
