#ifndef NWIDGET_COMBOBOX_H
#define NWIDGET_COMBOBOX_H

#include <QComboBox>

#include "widget.h"

namespace nwidget {

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

    S& items(const QStringList& items)                  { t->addItems(items); return self(); }
    S& items(std::initializer_list<ComboBoxItem> items) { addItems(items); return self(); }

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

N_DECLARE_BUILDER(ComboBox, ComboBoxBuilder, QComboBox)



template <typename T>
class ComboBoxIdT : public WidgetIdT<T>
{
    using InsertPolicy     = QComboBox::InsertPolicy;
    using SizeAdjustPolicy = QComboBox::SizeAdjustPolicy;

public:
    using WidgetIdT<T>::WidgetIdT;

    N_ID_PROPERTY(bool            , editable             , N_READ isEditable            N_WRITE setEditable             )
    N_ID_PROPERTY(int             , count                , N_READ count                                                 )
    N_ID_PROPERTY(QString         , currentText          , N_READ currentText           N_WRITE setCurrentText          N_NOTIFY currentTextChanged)
    N_ID_PROPERTY(int             , currentIndex         , N_READ currentIndex          N_WRITE setCurrentIndex         N_NOTIFY currentIndexChanged)
    N_ID_PROPERTY(QVariant        , currentData          , N_READ currentData                                           )
    N_ID_PROPERTY(int             , maxVisibleItems      , N_READ maxVisibleItems       N_WRITE setMaxVisibleItems      )
    N_ID_PROPERTY(int             , maxCount             , N_READ maxCount              N_WRITE setMaxCount             )
    N_ID_PROPERTY(InsertPolicy    , insertPolicy         , N_READ insertPolicy          N_WRITE setInsertPolicy         )
    N_ID_PROPERTY(SizeAdjustPolicy, sizeAdjustPolicy     , N_READ sizeAdjustPolicy      N_WRITE setSizeAdjustPolicy     )
    N_ID_PROPERTY(int             , minimumContentsLength, N_READ minimumContentsLength N_WRITE setMinimumContentsLength)
    N_ID_PROPERTY(QSize           , iconSize             , N_READ iconSize              N_WRITE setIconSize             )
    N_ID_PROPERTY(QString         , placeholderText      , N_READ placeholderText       N_WRITE setPlaceholderText      )
    N_ID_PROPERTY(bool            , duplicatesEnabled    , N_READ duplicatesEnabled     N_WRITE setDuplicatesEnabled    )
    N_ID_PROPERTY(bool            , frame                , N_READ hasFrame              N_WRITE setFrame                )
    N_ID_PROPERTY(int             , modelColumn          , N_READ modelColumn           N_WRITE setModelColumn          )
};

N_DECLARE_ID(ComboBox, ComboBoxIdT, QComboBox)

}

#endif // NWIDGET_COMBOBOX_H
