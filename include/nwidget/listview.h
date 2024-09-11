#ifndef NWIDGET_LISTVIEW_H
#define NWIDGET_LISTVIEW_H

#include <QListView>

#include "abstractitemview.h"

namespace nwidget {

template<typename T>
class ListViewIdT : public AbstractItemViewIdT<T>
{
    using Movement = QListView::Movement;
    using Flow = QListView::Flow;
    using ResizeMode = QListView::ResizeMode;
    using LayoutMode = QListView::LayoutMode;
    using ViewMode = QListView::ViewMode;

public:
    using AbstractItemViewIdT<T>::AbstractItemViewIdT;

    N_ID_PROPERTY(Movement     , movement            , N_GETTER(movement              ), N_SETTER(setMovement            ), N_NO_NOTIFY)
    N_ID_PROPERTY(Flow         , flow                , N_GETTER(flow                  ), N_SETTER(setFlow                ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool         , isWrapping          , N_GETTER(isWrapping            ), N_SETTER(setWrapping            ), N_NO_NOTIFY)
    N_ID_PROPERTY(ResizeMode   , resizeMode          , N_GETTER(resizeMode            ), N_SETTER(setResizeMode          ), N_NO_NOTIFY)
    N_ID_PROPERTY(LayoutMode   , layoutMode          , N_GETTER(layoutMode            ), N_SETTER(setLayoutMode          ), N_NO_NOTIFY)
    N_ID_PROPERTY(int          , spacing             , N_GETTER(spacing               ), N_SETTER(setSpacing             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize        , gridSize            , N_GETTER(gridSize              ), N_SETTER(setGridSize            ), N_NO_NOTIFY)
    N_ID_PROPERTY(ViewMode     , viewMode            , N_GETTER(viewMode              ), N_SETTER(setViewMode            ), N_NO_NOTIFY)
    N_ID_PROPERTY(int          , modelColumn         , N_GETTER(modelColumn           ), N_SETTER(setModelColumn         ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool         , uniformItemSizes    , N_GETTER(uniformItemSizes      ), N_SETTER(setUniformItemSizes    ), N_NO_NOTIFY)
    N_ID_PROPERTY(int          , batchSize           , N_GETTER(batchSize             ), N_SETTER(setBatchSize           ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool         , wordWrap            , N_GETTER(wordWrap              ), N_SETTER(setWordWrap            ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool         , selectionRectVisible, N_GETTER(isSelectionRectVisible), N_SETTER(setSelectionRectVisible), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::Alignment, itemAlignment       , N_GETTER(itemAlignment         ), N_SETTER(setItemAlignment       ), N_NO_NOTIFY)
};

N_DECLARE_ID(QListView, ListViewIdT, QListView)



template<typename S, typename T>
class ListViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

    using Movement = QListView::Movement;
    using Flow = QListView::Flow;
    using ResizeMode = QListView::ResizeMode;
    using LayoutMode = QListView::LayoutMode;
    using ViewMode = QListView::ViewMode;

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;

    N_BUILDER_PROPERTY(Movement     , movement            , setMovement            )
    N_BUILDER_PROPERTY(Flow         , flow                , setFlow                )
    N_BUILDER_PROPERTY(bool         , isWrapping          , setWrapping            )
    N_BUILDER_PROPERTY(ResizeMode   , resizeMode          , setResizeMode          )
    N_BUILDER_PROPERTY(LayoutMode   , layoutMode          , setLayoutMode          )
    N_BUILDER_PROPERTY(int          , spacing             , setSpacing             )
    N_BUILDER_PROPERTY(QSize        , gridSize            , setGridSize            )
    N_BUILDER_PROPERTY(ViewMode     , viewMode            , setViewMode            )
    N_BUILDER_PROPERTY(int          , modelColumn         , setModelColumn         )
    N_BUILDER_PROPERTY(bool         , uniformItemSizes    , setUniformItemSizes    )
    N_BUILDER_PROPERTY(int          , batchSize           , setBatchSize           )
    N_BUILDER_PROPERTY(bool         , wordWrap            , setWordWrap            )
    N_BUILDER_PROPERTY(bool         , selectionRectVisible, setSelectionRectVisible)
    N_BUILDER_PROPERTY(Qt::Alignment, itemAlignment       , setItemAlignment       )

    S& wrapping(bool enable)                  { t->setWrapping(enable);     return self(); }
    S& rowHidden(int row, bool hide)          { t->setRowHidden(row, hide); return self(); }

    N_BUILDER_SIGNAL(onIndexsMoved, indexesMoved)
};

N_DECLARE_BUILDER(ListView, ListViewBuilder, QListView)

}

#endif // NWIDGET_LISTVIEW_H
