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

    N_ID_PROPERTY(Movement     , movement            , N_READ movement               N_WRITE setMovement            )
    N_ID_PROPERTY(Flow         , flow                , N_READ flow                   N_WRITE setFlow                )
    N_ID_PROPERTY(bool         , isWrapping          , N_READ isWrapping             N_WRITE setWrapping            )
    N_ID_PROPERTY(ResizeMode   , resizeMode          , N_READ resizeMode             N_WRITE setResizeMode          )
    N_ID_PROPERTY(LayoutMode   , layoutMode          , N_READ layoutMode             N_WRITE setLayoutMode          )
    N_ID_PROPERTY(int          , spacing             , N_READ spacing                N_WRITE setSpacing             )
    N_ID_PROPERTY(QSize        , gridSize            , N_READ gridSize               N_WRITE setGridSize            )
    N_ID_PROPERTY(ViewMode     , viewMode            , N_READ viewMode               N_WRITE setViewMode            )
    N_ID_PROPERTY(int          , modelColumn         , N_READ modelColumn            N_WRITE setModelColumn         )
    N_ID_PROPERTY(bool         , uniformItemSizes    , N_READ uniformItemSizes       N_WRITE setUniformItemSizes    )
    N_ID_PROPERTY(int          , batchSize           , N_READ batchSize              N_WRITE setBatchSize           )
    N_ID_PROPERTY(bool         , wordWrap            , N_READ wordWrap               N_WRITE setWordWrap            )
    N_ID_PROPERTY(bool         , selectionRectVisible, N_READ isSelectionRectVisible N_WRITE setSelectionRectVisible)
    N_ID_PROPERTY(Qt::Alignment, itemAlignment       , N_READ itemAlignment          N_WRITE setItemAlignment       )
};

N_DECLARE_ID(ListView, ListViewIdT, QListView)



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
