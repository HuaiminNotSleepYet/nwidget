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
};

template<typename S, typename T>
class BoxLayoutBuilder : public LayoutBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(LayoutBuilder, S, T)

public:
    BoxLayoutBuilder()                                                      : LayoutBuilder<S, T>(new T) {}
    BoxLayoutBuilder(std::initializer_list<BoxLayoutItem> items)            : LayoutBuilder<S, T>(new T) { addItems(items); }
    explicit BoxLayoutBuilder(T* target)                                    : LayoutBuilder<S, T>(target) {}
    BoxLayoutBuilder(T* target, std::initializer_list<BoxLayoutItem> items) : LayoutBuilder<S, T>(target) { addItems(items); }

private:
    void addItems(std::initializer_list<BoxLayoutItem> items)
    {
        auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(LayoutItemBuilder<S, T>::t);
    }
};

N_BUILDER_IMPL(BoxLayoutBuilder, QBoxLayout , BoxLayout );
N_BUILDER_IMPL(BoxLayoutBuilder, QHBoxLayout, HBoxLayout);
N_BUILDER_IMPL(BoxLayoutBuilder, QVBoxLayout, VBoxLayout);

}

#endif // BOXLAYOUT_H
