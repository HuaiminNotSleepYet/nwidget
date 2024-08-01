#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QListView>

#include "abstractitemview.h"

namespace nw {

template<typename S, typename T>
class ListViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractItemViewBuilder, S, T)

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;

    inline S& movement(QListView::Movement m)        { t->setMovement(m);          return self(); }
    inline S& flow(QListView::Flow f)                { t->setFlow(f);              return self(); }
    inline S& wrapping(bool enable)                  { t->setWrapping(enable);     return self(); }
    inline S& resizeMode(QListView::ResizeMode mode) { t->setResizeMode(mode);     return self(); }
    inline S& layoutMode(QListView::LayoutMode mode) { t->setLayoutMode(mode);     return self(); }
    inline S& spacing(int space)                     { t->setSpacing(space);       return self(); }
    inline S& batchSize(int size)                    { t->setBatchSize(size);      return self(); }
    inline S& gridSize(const QSize &size)            { t->setGridSize(size);       return self(); }
    inline S& viewMode(QListView::ViewMode mode)     { t->setViewMode(mode);       return self(); }
    inline S& rowHidden(int row, bool hide)          { t->setRowHidden(row, hide); return self(); }
    inline S& modelColumn(int column)                { t->setModelColumn(column);  return self(); }
    inline S& uniformItemSizes(bool enable)          { t->setUniformItem(enable);  return self(); }
    inline S& wordWrap(bool on)                      { t->setWordWrap(on);         return self(); }
    inline S& selectionRectVisible(bool show)        { t->setSelectionRect(show);  return self(); }
    inline S& itemAlignment(Qt::Alignment align)     { t->setItemAlignment(align); return self(); }

    N_SIGNAL(onIndexsMoved, QListView::indexesMoved)
};

N_BUILDER_IMPL(ListViewBuilder, QListView, ListView);

}

#endif // LISTVIEW_H
