#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>

#include "widget.h"

namespace nw {

struct ComboBoxItem
{
    std::function<void(QComboBox*)> addTo;

    ComboBoxItem(const QString& text, const QVariant &userData = QVariant())
    { addTo = [text, userData](QComboBox* box){ box->addItem(text, userData); }; }

    ComboBoxItem(const QIcon& icon, const QString& text, const QVariant &userData = QVariant())
    { addTo = [icon, text, userData](QComboBox* box){ box->addItem(icon, text, userData); }; }

    ComboBoxItem(ItemGenerator<ComboBoxItem> generator)
    {
        addTo = [generator](QComboBox* box){
            auto item = generator();
            while (item) {
                item->addTo(box);
                item = generator();
            }
        };
    }
};

template<typename S, typename T>
class ComboBoxBuilder : public WidgetBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(WidgetBuilder, S, T)

public:
    ComboBoxBuilder()                                                     : WidgetBuilder<S, T>(new T) {};
    ComboBoxBuilder(const QStringList& items)                             : WidgetBuilder<S, T>(new T) { t->addItems(items); }
    ComboBoxBuilder(std::initializer_list<ComboBoxItem> items)            : WidgetBuilder<S, T>(new T) { addItems(items); }
    explicit ComboBoxBuilder(T* target)                                   : WidgetBuilder<S, T>(target) {};
    ComboBoxBuilder(T* target, const QStringList& items)                  : WidgetBuilder<S, T>(target) { t->addItems(items); }
    ComboBoxBuilder(T* target, std::initializer_list<ComboBoxItem> items) : WidgetBuilder<S, T>(target) { addItems(items); }

    N_SIGNAL(onEditTextChanged    , QComboBox::editTextChanged    )
    N_SIGNAL(onActivated          , QComboBox::activated          )
    N_SIGNAL(onTextActivated      , QComboBox::textActivated      )
    N_SIGNAL(onHighlighted        , QComboBox::highlighted        )
    N_SIGNAL(onTextHighlighted    , QComboBox::textHighlighted    )
    N_SIGNAL(onCurrentIndexChanged, QComboBox::currentIndexChanged)
    N_SIGNAL(onCurrentTextChanged , QComboBox::currentTextChanged )

private:
    void addItems(std::initializer_list<ComboBoxItem> items)
    {
        const auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(t);
    }
};

N_BUILDER_IMPL(ComboBoxBuilder, QComboBox, ComboBox);

}

#endif // COMBOBOX_H
