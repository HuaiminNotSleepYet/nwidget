#ifndef NWIDGET_TABLEVIEW_H
#define NWIDGET_TABLEVIEW_H

#include <QTableView>

#include "abstractitemview.h"

namespace nwidget {

template<typename S, typename T>
class TableViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

public:
    using AbstractItemViewBuilder<S, T>::AbstractItemViewBuilder;
};

N_DECL_BUILDER(TableViewBuilder, QTableView, TableView);

}

#endif // NWIDGET_TABLEVIEW_H
