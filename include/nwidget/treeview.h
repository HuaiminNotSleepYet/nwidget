#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QTreeView>

#include "abstractitemview.h"

namespace nw {

template<typename S, typename T>
class TreeViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractItemViewBuilder, S, T)

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;
};

N_BUILDER_IMPL(TreeViewBuilder, QTreeView, TreeView);

}

#endif // TREEVIEW_H
