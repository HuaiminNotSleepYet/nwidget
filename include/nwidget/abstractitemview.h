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

    N_ID_PROPERTY(bool             , autoScroll           , N_READ hasAutoScroll         N_WRITE setAutoScroll           )
    N_ID_PROPERTY(int              , autoScrollMargin     , N_READ autoScrollMargin      N_WRITE setAutoScrollMargin     )
    N_ID_PROPERTY(EditTriggers     , editTriggers         , N_READ editTriggers          N_WRITE setEditTriggers         )
    N_ID_PROPERTY(bool             , tabKeyNavigation     , N_READ tabKeyNavigation      N_WRITE setTabKeyNavigation     )
#if QT_CONFIG(draganddrop)
    N_ID_PROPERTY(bool             , showDropIndicator    , N_READ showDropIndicator     N_WRITE setDropIndicatorShown   )
    N_ID_PROPERTY(bool             , dragEnabled          , N_READ dragEnabled           N_WRITE setDragEnabled          )
    N_ID_PROPERTY(bool             , dragDropOverwriteMode, N_READ dragDropOverwriteMode N_WRITE setDragDropOverwriteMode)
    N_ID_PROPERTY(DragDropMode     , dragDropMode         , N_READ dragDropMode          N_WRITE setDragDropMode         )
    N_ID_PROPERTY(Qt::DropAction   , defaultDropAction    , N_READ defaultDropAction     N_WRITE setDefaultDropAction    )
#endif
    N_ID_PROPERTY(bool             , alternatingRowColors , N_READ alternatingRowColors  N_WRITE setAlternatingRowColors )
    N_ID_PROPERTY(SelectionMode    , selectionMode        , N_READ selectionMode         N_WRITE setSelectionMode        )
    N_ID_PROPERTY(SelectionBehavior, selectionBehavior    , N_READ selectionBehavior     N_WRITE setSelectionBehavior    )
    N_ID_PROPERTY(QSize            , iconSize             , N_READ iconSize              N_WRITE setIconSize             N_NOTIFY iconSizeChanged)
    N_ID_PROPERTY(Qt::TextElideMode, textElideMode        , N_READ textElideMode         N_WRITE setTextElideMode        )
    N_ID_PROPERTY(ScrollMode       , verticalScrollMode   , N_READ verticalScrollMode    N_WRITE setVerticalScrollMode   )
    N_ID_PROPERTY(ScrollMode       , horizontalScrollMode , N_READ horizontalScrollMode  N_WRITE setHorizontalScrollMode )
};

N_DECLARE_ID(AbstractItemView, AbstractItemViewIdT, QAbstractItemView)



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
    AbstractItemViewBuilder(QAbstractItemModel* model) : AbstractScrollAreaBuilder<S, T>(new T) { target()->setModel(model); }
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

    N_BUILDER_SETTER1(selectionModel       , setSelectionModel       )
    N_BUILDER_SETTER1(rootIndex            , setRootIndex            )
    N_BUILDER_SETTER1(itemDelegate         , setItemDelegate         )
    N_BUILDER_SETTER2(indexWidget          , setIndexWidget          )
    N_BUILDER_SETTER2(itemDelegateForRow   , setItemDelegateForRow   )
    N_BUILDER_SETTER2(itemDelegateForColumn, setItemDelegateForColumn)
    N_BUILDER_SETTER1(currentIndex         , setCurrentIndex         )

    // N_BUILDER_SETTER use decltype(&T::setter) to get parameter types,
    // but QTabWidget::setModel is private, so we write it manually here.
    N_BUILDER_SETTER S& model(QAbstractItemModel* model) { target()->setModel(model); return self(); }

#if QT_CONFIG(draganddrop)
    N_BUILDER_SETTER1(dropIndicatorShown, setDropIndicatorShown)
#endif


    N_BUILDER_SIGNAL(onPressed        , pressed        )
    N_BUILDER_SIGNAL(onClicked        , clicked        )
    N_BUILDER_SIGNAL(onDoubleClicked  , doubleClicked  )
    N_BUILDER_SIGNAL(onActivated      , activated      )
    N_BUILDER_SIGNAL(onEntered        , entered        )
    N_BUILDER_SIGNAL(onViewportEntered, viewportEntered)
    N_BUILDER_SIGNAL(onIconSizeChanged, iconSizeChanged)
};

N_DECLARE_BUILDER(AbstractItemView, AbstractItemViewBuilder, QAbstractItemView)

}

N_REGISTER_ID(nwidget::AbstractItemView, QAbstractItemView)
N_REGISTER_BUILDER(nwidget::AbstractItemView, QAbstractItemView)

#endif // NWIDGET_ABSTRACTITEMVIEW_H
