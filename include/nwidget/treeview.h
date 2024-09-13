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

    N_ID_PROPERTY(int , autoExpandDelay     , N_GETTER(autoExpandDelay     ), N_SETTER(setAutoExpandDelay     ), N_NO_NOTIFY)
    N_ID_PROPERTY(int , indentation         , N_GETTER(indentation         ), N_SETTER(setIndentation         ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, rootIsDecorated     , N_GETTER(rootIsDecorated     ), N_SETTER(setRootIsDecorated     ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, uniformRowHeights   , N_GETTER(uniformRowHeights   ), N_SETTER(setUniformRowHeights   ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, itemsExpandable     , N_GETTER(itemsExpandable     ), N_SETTER(setItemsExpandable     ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, sortingEnabled      , N_GETTER(isSortingEnabled    ), N_SETTER(setSortingEnabled      ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, animated            , N_GETTER(isAnimated          ), N_SETTER(setAnimated            ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, allColumnsShowFocus , N_GETTER(allColumnsShowFocus ), N_SETTER(setAllColumnsShowFocus ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, wordWrap            , N_GETTER(wordWrap            ), N_SETTER(setWordWrap            ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, headerHidden        , N_GETTER(isHeaderHidden      ), N_SETTER(setHeaderHidden        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool, expandsOnDoubleClick, N_GETTER(expandsOnDoubleClick), N_SETTER(setExpandsOnDoubleClick), N_NO_NOTIFY)
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

    S& header(QHeaderView* header)                                       { t->setHeader(header)                       ; return self(); }
    S& columnWidth(int column, int width)                                { t->setColumnWidth(column, width)           ; return self(); }
    S& columnHidden(int column, bool hide)                               { t->setColumnHidden(column, hide)           ; return self(); }
    S& headerHidden(bool hide)                                           { t->setHeaderHidden(hide)                   ; return self(); }
    S& rowHidden(int row, const QModelIndex& parent, bool hide)          { t->setRowHidden(row, parent, hide)         ; return self(); }
    S& firstColumnSpanned(int row, const QModelIndex& parent, bool span) { t->setFirstColumnSpanned(row, parent, span); return self(); }
    S& expanded(const QModelIndex& index, bool expand)                   { t->setExpanded(index, expand)              ; return self(); }
    S& treePosition(int logicalIndex)                                    { t->setTreePosition(logicalIndex)           ; return self(); }

    N_BUILDER_SIGNAL(onExpanded , expanded )
    N_BUILDER_SIGNAL(onCollapsed, collapsed)

};

N_DECLARE_BUILDER(TreeView, TreeViewBuilder, QTreeView);

}

#endif // NWIDGET_TREEVIEW_H
