#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H

#include <QFormLayout>

#include "layout.h"

namespace nw {

class FormLayoutItem : public BuilderItem<QFormLayout>
{
public:
    FormLayoutItem(const QString& label, QWidget* field) : BuilderItem([label, field](QFormLayout* layout){ layout->addRow(label, field); }) {}
    FormLayoutItem(const QString& label, QLayout* field) : BuilderItem([label, field](QFormLayout* layout){ layout->addRow(label, field); }) {}
    FormLayoutItem(QWidget* label, QWidget* field)       : BuilderItem([label, field](QFormLayout* layout){ layout->addRow(label, field); }) {}
    FormLayoutItem(QWidget* label, QLayout* field)       : BuilderItem([label, field](QFormLayout* layout){ layout->addRow(label, field); }) {}

    FormLayoutItem(QWidget* widget)   : BuilderItem([widget](QFormLayout* l){ l->addRow(widget); }) {}
    FormLayoutItem(QLayout* layout)   : BuilderItem([layout](QFormLayout* l){ l->addRow(layout); }) {}
    FormLayoutItem(QLayoutItem* item) : BuilderItem([item  ](QFormLayout* l){ l->addItem(item) ; }) {}

    template<typename T> FormLayoutItem(const WidgetIdT<T>& widget) : FormLayoutItem((T*)widget) {}
    template<typename T> FormLayoutItem(const LayoutIdT<T>& layout) : FormLayoutItem((T*)layout) {}

    template<typename S, typename T> FormLayoutItem(const WidgetBuilder<S, T>& widget) : FormLayoutItem((T*)widget) {}
    template<typename S, typename T> FormLayoutItem(const LayoutBuilder<S, T>& layout) : FormLayoutItem((T*)layout) {}

    FormLayoutItem(ItemGenerator<FormLayoutItem> generator) : BuilderItem(generator) {}
};

template<typename S, typename T>
class FormLayoutBuilder : public LayoutBuilder<S, T>
{
    N_BUILDER

public:
    FormLayoutBuilder()                                                       : LayoutBuilder<S, T>(new T) {}
    FormLayoutBuilder(std::initializer_list<FormLayoutItem> items)            : LayoutBuilder<S, T>(new T) { addItems(items); }
    explicit
    FormLayoutBuilder(T* target)                                              : LayoutBuilder<S, T>(target) {}
    FormLayoutBuilder(T* target, std::initializer_list<FormLayoutItem> items) : LayoutBuilder<S, T>(target) { addItems(items); }

    S& items(std::initializer_list<LayoutItem> items) = delete;
    S& items(std::initializer_list<FormLayoutItem> items) { addItems(items); return self(); }

    N_BUILDER_PROPERTY(QFormLayout::FieldGrowthPolicy, fieldGrowthPolicy, setFieldGrowthPolicy)
    N_BUILDER_PROPERTY(QFormLayout::RowWrapPolicy    , rowWrapPolicy    , setRowWrapPolicy    )
    N_BUILDER_PROPERTY(Qt::Alignment                 , labelAlignment   , setLabelAlignment   )
    N_BUILDER_PROPERTY(Qt::Alignment                 , formAlignment    , setFormAlignment    )
    N_BUILDER_PROPERTY(int                           , horizontalSpacing, setHorizontalSpacing)
    N_BUILDER_PROPERTY(int                           , verticalSpacing  , setVerticalSpacing  )
};

N_DECL_BUILDER(FormLayoutBuilder, QFormLayout, FormLayout);



template<typename T>
class FormLayoutIdT : public LayoutIdT<T>
{
public:
    using LayoutIdT<T>::LayoutIdT;

    N_ID_PROPERTY(QFormLayout::FieldGrowthPolicy, fieldGrowthPolicy, N_GETTER(fieldGrowthPolicy), N_SETTER(setFieldGrowthPolicy), N_NO_NOTIFY)
    N_ID_PROPERTY(QFormLayout::RowWrapPolicy    , rowWrapPolicy    , N_GETTER(rowWrapPolicy    ), N_SETTER(setRowWrapPolicy    ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Alignment                 , labelAlignment   , N_GETTER(labelAlignment   ), N_SETTER(setLabelAlignment   ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Alignment                 , formAlignment    , N_GETTER(formAlignment    ), N_SETTER(setFormAlignment    ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                           , horizontalSpacing, N_GETTER(horizontalSpacing), N_SETTER(setHorizontalSpacing), N_NO_NOTIFY)
    N_ID_PROPERTY(int                           , verticalSpacing  , N_GETTER(verticalSpacing  ), N_SETTER(setVerticalSpacing  ), N_NO_NOTIFY)
};

using FormLayoutId = FormLayoutIdT<QFormLayout>;

}

#endif // FORMLAYOUT_H
