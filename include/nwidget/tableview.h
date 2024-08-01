#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>

#include "abstractitemview.h"

namespace nw {

template<typename S, typename T>
class TableViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractItemViewBuilder, S, T)

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;
};

N_BUILDER_IMPL(TableViewBuilder, QTableView, TableView);

}

#endif // TABLEVIEW_H
