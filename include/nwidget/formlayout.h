#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H

#include <QFormLayout>

#include "layout.h"

namespace nw {

struct FormLayoutItem
{
    std::function<void(QFormLayout* layout)> addTo;

    FormLayoutItem(const QString& label, QWidget* field) { addTo = [label, field](QFormLayout* layout){ layout->addRow(label, field); }; }
    FormLayoutItem(const QString& label, QLayout* field) { addTo = [label, field](QFormLayout* layout){ layout->addRow(label, field); }; }
    FormLayoutItem(QWidget* label, QWidget* field)       { addTo = [label, field](QFormLayout* layout){ layout->addRow(label, field); }; }
    FormLayoutItem(QWidget* label, QLayout* field)       { addTo = [label, field](QFormLayout* layout){ layout->addRow(label, field); }; }

    FormLayoutItem(QWidget* widget)   { addTo = [widget](QFormLayout* layout){ layout->addRow(widget); }; }
    FormLayoutItem(QLayout* layout)   { addTo = [layout](QFormLayout* l){ l->addRow(layout); }; }
    FormLayoutItem(QLayoutItem* item) { addTo = [item](QFormLayout* layout){ layout->addItem(item); }; }

    template<typename S, typename T> FormLayoutItem(const WidgetBuilder<S, T>& widget)   : FormLayoutItem(widget.operator T*()) {}
    template<typename S, typename T> FormLayoutItem(const LayoutBuilder<S, T>& layout)   : FormLayoutItem(layout.operator T*()) {}
    template<typename S, typename T> FormLayoutItem(const LayoutItemBuilder<S, T>& item) : FormLayoutItem(item.operator T*()) {}

    FormLayoutItem(ItemGenerator<FormLayoutItem> generator)
    {
        addTo = [generator](QFormLayout* l){
            auto item = generator();
            while (item) {
                item->addTo(l);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class FormLayoutBuilder : public LayoutBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(LayoutBuilder, S, T)

public:
    FormLayoutBuilder()                                                       : LayoutBuilder<S, T>(new T) {}
    FormLayoutBuilder(std::initializer_list<FormLayoutItem> items)            : LayoutBuilder<S, T>(new T) { applyItems(items); }
    explicit FormLayoutBuilder(T* target)                                     : LayoutBuilder<S, T>(target) {}
    FormLayoutBuilder(T* target, std::initializer_list<FormLayoutItem> items) : LayoutBuilder<S, T>(target) { applyItems(items); }

private:
    void applyItems(std::initializer_list<FormLayoutItem> items)
    {
        const auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(t);
    }
};

N_BUILDER_IMPL(FormLayoutBuilder, QFormLayout, FormLayout);



template<typename T>
class FormLayoutRefT : public LayoutRefT<T>
{
public:
    using LayoutRefT<T>::LayoutRefT;

    N_PROPERTY(QFormLayout::FieldGrowthPolicy, fieldGrowthPolicy, N_GETTER(fieldGrowthPolicy), N_SETTER(setFieldGrowthPolicy), N_NO_NOTIFY)
    N_PROPERTY(QFormLayout::RowWrapPolicy    , rowWrapPolicy    , N_GETTER(rowWrapPolicy    ), N_SETTER(setRowWrapPolicy    ), N_NO_NOTIFY)
    N_PROPERTY(Qt::Alignment                 , labelAlignment   , N_GETTER(labelAlignment   ), N_SETTER(setLabelAlignment   ), N_NO_NOTIFY)
    N_PROPERTY(Qt::Alignment                 , formAlignment    , N_GETTER(formAlignment    ), N_SETTER(setFormAlignment    ), N_NO_NOTIFY)
    N_PROPERTY(int                           , horizontalSpacing, N_GETTER(horizontalSpacing), N_SETTER(setHorizontalSpacing), N_NO_NOTIFY)
    N_PROPERTY(int                           , verticalSpacing  , N_GETTER(verticalSpacing  ), N_SETTER(setVerticalSpacing  ), N_NO_NOTIFY)
};

using FormLayoutRef = FormLayoutRefT<QFormLayout>;
}

#endif // FORMLAYOUT_H
