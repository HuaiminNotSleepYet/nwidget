#ifndef NWIDGET_ABSTRACTITEMVIEW_H
#define NWIDGET_ABSTRACTITEMVIEW_H

#include <QAbstractItemView>

#include "abstractscrollarea.h"

namespace nwidget {

template<typename T>
class AbstractItemViewIdT : public AbstractScrollAreaIdT<T>
{
    using DragDropMode = QAbstractItemView::DragDropMode;
    using EditTriggers = QAbstractItemView::EditTriggers;
    using ScrollMode = QAbstractItemView::ScrollMode;
    using SelectionMode = QAbstractItemView::SelectionMode;
    using SelectionBehavior = QAbstractItemView::SelectionBehavior;

public:
    using AbstractScrollAreaIdT<T>::AbstractScrollAreaIdT;

    N_ID_PROPERTY(bool             , autoScroll           , N_GETTER(hasAutoScroll        ), N_SETTER(setAutoScroll           ), N_NO_NOTIFY)
    N_ID_PROPERTY(int              , autoScrollMargin     , N_GETTER(autoScrollMargin     ), N_SETTER(setAutoScrollMargin     ), N_NO_NOTIFY)
    N_ID_PROPERTY(EditTriggers     , editTriggers         , N_GETTER(editTriggers         ), N_SETTER(setEditTriggers         ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , tabKeyNavigation     , N_GETTER(tabKeyNavigation     ), N_SETTER(setTabKeyNavigation     ), N_NO_NOTIFY)
#if QT_CONFIG(draganddrop)
    N_ID_PROPERTY(bool             , showDropIndicator    , N_GETTER(showDropIndicator    ), N_SETTER(setDropIndicatorShown   ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , dragEnabled          , N_GETTER(dragEnabled          ), N_SETTER(setDragEnabled          ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool             , dragDropOverwriteMode, N_GETTER(dragDropOverwriteMode), N_SETTER(setDragDropOverwriteMode), N_NO_NOTIFY)
    N_ID_PROPERTY(DragDropMode     , dragDropMode         , N_GETTER(dragDropMode         ), N_SETTER(setDragDropMode         ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::DropAction   , defaultDropAction    , N_GETTER(defaultDropAction    ), N_SETTER(setDefaultDropAction    ), N_NO_NOTIFY)
#endif
    N_ID_PROPERTY(bool             , alternatingRowColors , N_GETTER(alternatingRowColors ), N_SETTER(setAlternatingRowColors ), N_NO_NOTIFY)
    N_ID_PROPERTY(SelectionMode    , selectionMode        , N_GETTER(selectionMode        ), N_SETTER(setSelectionMode        ), N_NO_NOTIFY)
    N_ID_PROPERTY(SelectionBehavior, selectionBehavior    , N_GETTER(selectionBehavior    ), N_SETTER(setSelectionBehavior    ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize            , iconSize             , N_GETTER(iconSize             ), N_SETTER(setIconSize             ), N_NOTIFY(iconSizeChanged))
    N_ID_PROPERTY(Qt::TextElideMode, textElideMode        , N_GETTER(textElideMode        ), N_SETTER(setTextElideMode        ), N_NO_NOTIFY)
    N_ID_PROPERTY(ScrollMode       , verticalScrollMode   , N_GETTER(verticalScrollMode   ), N_SETTER(setVerticalScrollMode   ), N_NO_NOTIFY)
    N_ID_PROPERTY(ScrollMode       , horizontalScrollMode , N_GETTER(horizontalScrollMode ), N_SETTER(setHorizontalScrollMode ), N_NO_NOTIFY)
};

using AbstractItemViewId = AbstractItemViewIdT<QAbstractItemView>;



template<typename S, typename T>
class AbstractItemViewBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_BUILDER

    using DragDropMode = QAbstractItemView::DragDropMode;
    using EditTriggers = QAbstractItemView::EditTriggers;
    using ScrollMode = QAbstractItemView::ScrollMode;
    using SelectionMode = QAbstractItemView::SelectionMode;
    using SelectionBehavior = QAbstractItemView::SelectionBehavior;

public:
    AbstractItemViewBuilder()                          : AbstractScrollAreaBuilder<S, T>(new T) {}
    explicit
    AbstractItemViewBuilder(QAbstractItemModel* model) : AbstractScrollAreaBuilder<S, T>(new T) { t->setModel(model); }
    explicit
    AbstractItemViewBuilder(T* target)                 : AbstractScrollAreaBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(bool             , autoScroll           , setAutoScroll           )
    N_BUILDER_PROPERTY(int              , autoScrollMargin     , setAutoScrollMargin     )
    N_BUILDER_PROPERTY(EditTriggers     , editTriggers         , setEditTriggers         )
    N_BUILDER_PROPERTY(bool             , tabKeyNavigation     , setTabKeyNavigation     )
#if QT_CONFIG(draganddrop)
    N_BUILDER_PROPERTY(bool             , showDropIndicator    , setDropIndicatorShown   )
    N_BUILDER_PROPERTY(bool             , dragEnabled          , setDragEnabled          )
    N_BUILDER_PROPERTY(bool             , dragDropOverwriteMode, setDragDropOverwriteMode)
    N_BUILDER_PROPERTY(DragDropMode     , dragDropMode         , setDragDropMode         )
    N_BUILDER_PROPERTY(Qt::DropAction   , defaultDropAction    , setDefaultDropAction    )
#endif
    N_BUILDER_PROPERTY(bool             , alternatingRowColors , setAlternatingRowColors )
    N_BUILDER_PROPERTY(SelectionMode    , selectionMode        , setSelectionMode        )
    N_BUILDER_PROPERTY(SelectionBehavior, selectionBehavior    , setSelectionBehavior    )
    N_BUILDER_PROPERTY(QSize            , iconSize             , setIconSize             )
    N_BUILDER_PROPERTY(Qt::TextElideMode, textElideMode        , setTextElideMode        )
    N_BUILDER_PROPERTY(ScrollMode       , verticalScrollMode   , setVerticalScrollMode   )
    N_BUILDER_PROPERTY(ScrollMode       , horizontalScrollMode , setHorizontalScrollMode )

    S& model(QAbstractItemModel* model)                                   { t->setModel(model)                           ; return self(); }
    S& selectionModel(QItemSelectionModel* selectionModel)                { t->setSelectionModel(selectionModel)         ; return self(); }
    S& rootIndex(const QModelIndex& index)                                { t->setRootIndex(index)                       ; return self(); }
    S& itemDelegate(QAbstractItemDelegate* delegate)                      { t->setItemDelegate(delegate)                 ; return self(); }
#if QT_CONFIG(draganddrop)
    S& dropIndicatorShown(bool enable)                                    { t->setDropIndicatorShown(enable)             ; return self(); }
#endif
    S& indexWidget(const QModelIndex& index, QWidget* widget)             { t->setIndexWidget(index, widget)             ; return self(); }
    S& itemDelegateForRow(int row, QAbstractItemDelegate* delegate)       { t->setItemDelegateForRow(row, delegate)      ; return self(); }
    S& itemDelegateForColumn(int column, QAbstractItemDelegate* delegate) { t->setItemDelegateForColumn(column, delegate); return self(); }
    S& currentIndex(const QModelIndex& index)                             { t->setCurrentIndex(index)                    ; return self(); }

    N_BUILDER_SIGNAL(onPressed        , pressed        )
    N_BUILDER_SIGNAL(onClicked        , clicked        )
    N_BUILDER_SIGNAL(onDoubleClicked  , doubleClicked  )
    N_BUILDER_SIGNAL(onActivated      , activated      )
    N_BUILDER_SIGNAL(onEntered        , entered        )
    N_BUILDER_SIGNAL(onViewportEntered, viewportEntered)
    N_BUILDER_SIGNAL(onIconSizeChanged, iconSizeChanged)
};

N_DECL_BUILDER(AbstractItemViewBuilder, QAbstractItemView, AbstractItemView);

}

#endif // NWIDGET_ABSTRACTITEMVIEW_H
