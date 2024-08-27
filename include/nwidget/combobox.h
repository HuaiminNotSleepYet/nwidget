#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>

#include "widget.h"

namespace nw {

class ComboBoxItem : public BuilderItem<QComboBox>
{
public:
    ComboBoxItem(const QString& text, const QVariant &userData = QVariant())
        : BuilderItem([text, userData](QComboBox* box){ box->addItem(text, userData); })
    {}

    ComboBoxItem(const QIcon& icon, const QString& text, const QVariant &userData = QVariant())
        : BuilderItem([icon, text, userData](QComboBox* box){ box->addItem(icon, text, userData); })
    {}

    ComboBoxItem(ItemGenerator<ComboBoxItem> generator)
        : BuilderItem(generator)
    {}
};

template<typename S, typename T>
class ComboBoxBuilder : public WidgetBuilder<S, T>
{
    N_BUILDER

public:
    ComboBoxBuilder()                                          : WidgetBuilder<S, T>(new T) {}
    explicit
    ComboBoxBuilder(const QStringList& items)                  : WidgetBuilder<S, T>(new T) { t->addItems(items); }
    ComboBoxBuilder(std::initializer_list<ComboBoxItem> items) : WidgetBuilder<S, T>(new T) { addItems(items); }
    explicit
    ComboBoxBuilder(T* target)                                 : WidgetBuilder<S, T>(target) {}

    S& item(const QStringList& items)                  { t->addItems(items); return self(); }
    S& item(std::initializer_list<ComboBoxItem> items) { addItems(items); return self(); }

    N_BUILDER_PROPERTY(bool                       , editable             , setEditable             )
    N_BUILDER_PROPERTY(QString                    , currentText          , setCurrentText          )
    N_BUILDER_PROPERTY(int                        , currentIndex         , setCurrentIndex         )
    N_BUILDER_PROPERTY(int                        , maxVisibleItems      , setMaxVisibleItems      )
    N_BUILDER_PROPERTY(int                        , maxCount             , setMaxCount             )
    N_BUILDER_PROPERTY(QComboBox::InsertPolicy    , insertPolicy         , setInsertPolicy         )
    N_BUILDER_PROPERTY(QComboBox::SizeAdjustPolicy, sizeAdjustPolicy     , setSizeAdjustPolicy     )
    N_BUILDER_PROPERTY(int                        , minimumContentsLength, setMinimumContentsLength)
    N_BUILDER_PROPERTY(QSize                      , iconSize             , setIconSize             )
    N_BUILDER_PROPERTY(QString                    , placeholderText      , setPlaceholderText      )
    N_BUILDER_PROPERTY(bool                       , duplicatesEnabled    , setDuplicatesEnabled    )
    N_BUILDER_PROPERTY(bool                       , frame                , setFrame                )
    N_BUILDER_PROPERTY(int                        , modelColumn          , setModelColumn          )

    N_BUILDER_SIGNAL(onEditTextChanged    , editTextChanged    )
    N_BUILDER_SIGNAL(onActivated          , activated          )
    N_BUILDER_SIGNAL(onTextActivated      , textActivated      )
    N_BUILDER_SIGNAL(onHighlighted        , highlighted        )
    N_BUILDER_SIGNAL(onTextHighlighted    , textHighlighted    )
    N_BUILDER_SIGNAL(onCurrentIndexChanged, currentIndexChanged)
    N_BUILDER_SIGNAL(onCurrentTextChanged , currentTextChanged )
};

N_DECL_BUILDER(ComboBoxBuilder, QComboBox, ComboBox);



template <typename T>
class ComboBoxIdT : public WidgetIdT<T>
{
public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool                       , editable             , N_GETTER(isEditable           ), N_SETTER(setEditable             ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                        , count                , N_GETTER(count                ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QString                    , currentText          , N_GETTER(currentText          ), N_SETTER(setCurrentText          ), N_NOTIFY(currentTextChanged))
    N_ID_PROPERTY(int                        , currentIndex         , N_GETTER(currentIndex         ), N_SETTER(setCurrentIndex         ), N_NOTIFY(currentIndexChanged))
    N_ID_PROPERTY(QVariant                   , currentData          , N_GETTER(currentData          ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(int                        , maxVisibleItems      , N_GETTER(maxVisibleItems      ), N_SETTER(setMaxVisibleItems      ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                        , maxCount             , N_GETTER(maxCount             ), N_SETTER(setMaxCount             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QComboBox::InsertPolicy    , insertPolicy         , N_GETTER(insertPolicy         ), N_SETTER(setInsertPolicy         ), N_NO_NOTIFY)
    N_ID_PROPERTY(QComboBox::SizeAdjustPolicy, sizeAdjustPolicy     , N_GETTER(sizeAdjustPolicy     ), N_SETTER(setSizeAdjustPolicy     ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                        , minimumContentsLength, N_GETTER(minimumContentsLength), N_SETTER(setMinimumContentsLength), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                      , iconSize             , N_GETTER(iconSize             ), N_SETTER(setIconSize             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString                    , placeholderText      , N_GETTER(placeholderText      ), N_SETTER(setPlaceholderText      ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                       , duplicatesEnabled    , N_GETTER(duplicatesEnabled    ), N_SETTER(setDuplicatesEnabled    ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                       , frame                , N_GETTER(hasFrame             ), N_SETTER(setFrame                ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                        , modelColumn          , N_GETTER(modelColumn          ), N_SETTER(setModelColumn          ), N_NO_NOTIFY)
};

using ComboBoxId = ComboBoxIdT<QComboBox>;

}

#endif // COMBOBOX_H
