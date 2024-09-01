#ifndef NWIDGET_TREEVIEW_H
#define NWIDGET_TREEVIEW_H

#include <QTreeView>

#include "abstractitemview.h"

namespace nwidget {

template<typename S, typename T>
class TreeViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;
};

N_DECL_BUILDER(TreeViewBuilder, QTreeView, TreeView);

}

#endif // NWIDGET_TREEVIEW_H
