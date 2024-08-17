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

    void jiejie() { std::vector<int> a = {1, 2}; }

public:
    ComboBoxBuilder()                                                     : WidgetBuilder<S, T>(new T) {}
    explicit ComboBoxBuilder(const QStringList& items)                    : WidgetBuilder<S, T>(new T) { t->addItems(items); }
    ComboBoxBuilder(std::initializer_list<ComboBoxItem> items)            : WidgetBuilder<S, T>(new T) { addItems(items); }

    explicit ComboBoxBuilder(T* target)                                   : WidgetBuilder<S, T>(target) {}
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



template <typename T>
class ComboBoxRefT : public WidgetRefT<T>
{
public:
    using WidgetRefT<T>::WidgetRefT;

    N_PROPERTY(bool                       , editable             , N_GETTER(isEditable           ), N_SETTER(setEditable             ), N_NO_NOTIFY)
    N_PROPERTY(int                        , count                , N_GETTER(count                ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QString                    , currentText          , N_GETTER(currentText          ), N_SETTER(setCurrentText          ), N_NOTIFY(currentTextChanged))
    N_PROPERTY(int                        , currentIndex         , N_GETTER(currentIndex         ), N_SETTER(setCurrentIndex         ), N_NOTIFY(currentIndexChanged))
    N_PROPERTY(QVariant                   , currentData          , N_GETTER(currentData          ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(int                        , maxVisibleItems      , N_GETTER(maxVisibleItems      ), N_SETTER(setMaxVisibleItems      ), N_NO_NOTIFY)
    N_PROPERTY(int                        , maxCount             , N_GETTER(maxCount             ), N_SETTER(setMaxCount             ), N_NO_NOTIFY)
    N_PROPERTY(QComboBox::InsertPolicy    , insertPolicy         , N_GETTER(insertPolicy         ), N_SETTER(setInsertPolicy         ), N_NO_NOTIFY)
    N_PROPERTY(QComboBox::SizeAdjustPolicy, sizeAdjustPolicy     , N_GETTER(sizeAdjustPolicy     ), N_SETTER(setSizeAdjustPolicy     ), N_NO_NOTIFY)
    N_PROPERTY(int                        , minimumContentsLength, N_GETTER(minimumContentsLength), N_SETTER(setMinimumContentsLength), N_NO_NOTIFY)
    N_PROPERTY(QSize                      , iconSize             , N_GETTER(iconSize             ), N_SETTER(setIconSize             ), N_NO_NOTIFY)
    N_PROPERTY(QString                    , placeholderText      , N_GETTER(placeholderText      ), N_SETTER(setPlaceholderText      ), N_NO_NOTIFY)
    N_PROPERTY(bool                       , duplicatesEnabled    , N_GETTER(duplicatesEnabled    ), N_SETTER(setDuplicatesEnabled    ), N_NO_NOTIFY)
    N_PROPERTY(bool                       , frame                , N_GETTER(hasFrame             ), N_SETTER(setFrame                ), N_NO_NOTIFY)
    N_PROPERTY(int                        , modelColumn          , N_GETTER(modelColumn          ), N_SETTER(setModelColumn          ), N_NO_NOTIFY)
};

using ComboBoxRef = ComboBoxRefT<QComboBox>;

}

#endif // COMBOBOX_H
