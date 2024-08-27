#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QListView>

#include "abstractitemview.h"

namespace nw {

template<typename S, typename T>
class ListViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;

    S& movement(QListView::Movement m)        { t->setMovement(m);          return self(); }
    S& flow(QListView::Flow f)                { t->setFlow(f);              return self(); }
    S& wrapping(bool enable)                  { t->setWrapping(enable);     return self(); }
    S& resizeMode(QListView::ResizeMode mode) { t->setResizeMode(mode);     return self(); }
    S& layoutMode(QListView::LayoutMode mode) { t->setLayoutMode(mode);     return self(); }
    S& spacing(int space)                     { t->setSpacing(space);       return self(); }
    S& batchSize(int size)                    { t->setBatchSize(size);      return self(); }
    S& gridSize(const QSize &size)            { t->setGridSize(size);       return self(); }
    S& viewMode(QListView::ViewMode mode)     { t->setViewMode(mode);       return self(); }
    S& rowHidden(int row, bool hide)          { t->setRowHidden(row, hide); return self(); }
    S& modelColumn(int column)                { t->setModelColumn(column);  return self(); }
    S& uniformItemSizes(bool enable)          { t->setUniformItem(enable);  return self(); }
    S& wordWrap(bool on)                      { t->setWordWrap(on);         return self(); }
    S& selectionRectVisible(bool show)        { t->setSelectionRect(show);  return self(); }
    S& itemAlignment(Qt::Alignment align)     { t->setItemAlignment(align); return self(); }

    N_BUILDER_SIGNAL(onIndexsMoved, indexesMoved)
};

N_DECL_BUILDER(ListViewBuilder, QListView, ListView);

}

#endif // LISTVIEW_H
