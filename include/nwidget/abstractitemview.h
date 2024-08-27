#ifndef ABSTRACTITEMVIEW_H
#define ABSTRACTITEMVIEW_H

#include <QAbstractItemView>

#include "abstractscrollarea.h"

namespace nw {

template<typename S, typename T>
class AbstractItemViewBuilder : public AbstractScrollAreaBuilder<S, T>
{
    N_BUILDER

public:
    AbstractItemViewBuilder()                          : AbstractScrollAreaBuilder<S, T>(new T) {}
    explicit
    AbstractItemViewBuilder(QAbstractItemModel* model) : AbstractScrollAreaBuilder<S, T>(new T) { t->setModel(model); }
    explicit
    AbstractItemViewBuilder(T* target)                 : AbstractScrollAreaBuilder<S, T>(target) {}
};

N_DECL_BUILDER(AbstractItemViewBuilder, QAbstractItemView, AbstractItemView);

}

#endif // ABSTRACTITEMVIEW_H
