#ifndef NWIDGET_FORMLAYOUT_H
#define NWIDGET_FORMLAYOUT_H

#include <QFormLayout>

#include "layout.h"

namespace nwidget {

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
    N_BUILDER_SETTER S& items(std::initializer_list<FormLayoutItem> items) { addItems(items); return self(); }

    N_BUILDER_PROPERTY(QFormLayout::FieldGrowthPolicy, fieldGrowthPolicy, setFieldGrowthPolicy)
    N_BUILDER_PROPERTY(QFormLayout::RowWrapPolicy    , rowWrapPolicy    , setRowWrapPolicy    )
    N_BUILDER_PROPERTY(Qt::Alignment                 , labelAlignment   , setLabelAlignment   )
    N_BUILDER_PROPERTY(Qt::Alignment                 , formAlignment    , setFormAlignment    )
    N_BUILDER_PROPERTY(int                           , horizontalSpacing, setHorizontalSpacing)
    N_BUILDER_PROPERTY(int                           , verticalSpacing  , setVerticalSpacing  )
};

N_DECLARE_BUILDER_N(FormLayout, FormLayoutBuilder, QFormLayout)



template<typename T>
class FormLayoutIdT : public LayoutIdT<T>
{
    using FieldGrowthPolicy = QFormLayout::FieldGrowthPolicy;
    using RowWrapPolicy     = QFormLayout::RowWrapPolicy;
public:
    using LayoutIdT<T>::LayoutIdT;

    N_ID_PROPERTY(FieldGrowthPolicy, fieldGrowthPolicy, N_READ fieldGrowthPolicy N_WRITE setFieldGrowthPolicy)
    N_ID_PROPERTY(RowWrapPolicy    , rowWrapPolicy    , N_READ rowWrapPolicy     N_WRITE setRowWrapPolicy    )
    N_ID_PROPERTY(Qt::Alignment    , labelAlignment   , N_READ labelAlignment    N_WRITE setLabelAlignment   )
    N_ID_PROPERTY(Qt::Alignment    , formAlignment    , N_READ formAlignment     N_WRITE setFormAlignment    )
    N_ID_PROPERTY(int              , horizontalSpacing, N_READ horizontalSpacing N_WRITE setHorizontalSpacing)
    N_ID_PROPERTY(int              , verticalSpacing  , N_READ verticalSpacing   N_WRITE setVerticalSpacing  )
};

N_DECLARE_ID_N(FormLayout, FormLayoutIdT, QFormLayout)

}

#endif // NWIDGET_FORMLAYOUT_H
