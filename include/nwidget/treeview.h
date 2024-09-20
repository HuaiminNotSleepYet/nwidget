#ifndef NWIDGET_TREEVIEW_H
#define NWIDGET_TREEVIEW_H

#include <QTreeView>

#include "abstractitemview.h"

namespace nwidget {

template<typename T>
class TreeViewIdT : public AbstractItemViewIdT<T>
{
public:
    using AbstractItemViewIdT<T>::AbstractItemViewIdT;

    N_ID_PROPERTY(int , autoExpandDelay     , N_READ autoExpandDelay      N_WRITE setAutoExpandDelay     )
    N_ID_PROPERTY(int , indentation         , N_READ indentation          N_WRITE setIndentation         )
    N_ID_PROPERTY(bool, rootIsDecorated     , N_READ rootIsDecorated      N_WRITE setRootIsDecorated     )
    N_ID_PROPERTY(bool, uniformRowHeights   , N_READ uniformRowHeights    N_WRITE setUniformRowHeights   )
    N_ID_PROPERTY(bool, itemsExpandable     , N_READ itemsExpandable      N_WRITE setItemsExpandable     )
    N_ID_PROPERTY(bool, sortingEnabled      , N_READ isSortingEnabled     N_WRITE setSortingEnabled      )
    N_ID_PROPERTY(bool, animated            , N_READ isAnimated           N_WRITE setAnimated            )
    N_ID_PROPERTY(bool, allColumnsShowFocus , N_READ allColumnsShowFocus  N_WRITE setAllColumnsShowFocus )
    N_ID_PROPERTY(bool, wordWrap            , N_READ wordWrap             N_WRITE setWordWrap            )
    N_ID_PROPERTY(bool, headerHidden        , N_READ isHeaderHidden       N_WRITE setHeaderHidden        )
    N_ID_PROPERTY(bool, expandsOnDoubleClick, N_READ expandsOnDoubleClick N_WRITE setExpandsOnDoubleClick)
};

N_DECLARE_ID(TreeView, TreeViewIdT, QTreeView)



template<typename S, typename T>
class TreeViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;

    N_BUILDER_PROPERTY(int , autoExpandDelay     , setAutoExpandDelay     )
    N_BUILDER_PROPERTY(int , indentation         , setIndentation         )
    N_BUILDER_PROPERTY(bool, rootIsDecorated     , setRootIsDecorated     )
    N_BUILDER_PROPERTY(bool, uniformRowHeights   , setUniformRowHeights   )
    N_BUILDER_PROPERTY(bool, itemsExpandable     , setItemsExpandable     )
    N_BUILDER_PROPERTY(bool, sortingEnabled      , setSortingEnabled      )
    N_BUILDER_PROPERTY(bool, animated            , setAnimated            )
    N_BUILDER_PROPERTY(bool, allColumnsShowFocus , setAllColumnsShowFocus )
    N_BUILDER_PROPERTY(bool, wordWrap            , setWordWrap            )
    N_BUILDER_PROPERTY(bool, expandsOnDoubleClick, setExpandsOnDoubleClick)

    N_BUILDER_SETTER1(header            , setHeader            )
    N_BUILDER_SETTER2(columnWidth       , setColumnWidth       )
    N_BUILDER_SETTER2(columnHidden      , setColumnHidden      )
    N_BUILDER_SETTER1(headerHidden      , setHeaderHidden      )
    N_BUILDER_SETTER3(rowHidden         , setRowHidden         )
    N_BUILDER_SETTER3(firstColumnSpanned, setFirstColumnSpanned)
    N_BUILDER_SETTER2(expanded          , setExpanded          )
    N_BUILDER_SETTER1(treePosition      , setTreePosition      )

    N_BUILDER_SIGNAL(onExpanded , expanded )
    N_BUILDER_SIGNAL(onCollapsed, collapsed)

};

N_DECLARE_BUILDER(TreeView, TreeViewBuilder, QTreeView)

}

N_REGISTER_ID(nwidget::TreeView, QTreeView)
N_REGISTER_BUILDER(nwidget::TreeView, QTreeView)

#endif // NWIDGET_TREEVIEW_H
