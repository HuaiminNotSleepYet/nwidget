#ifndef HEADERVIEW_H
#define HEADERVIEW_H

#include <QHeaderView>

#include "abstractitemview.h"

namespace nwidget {

template<typename T>
class HeaderViewIdT : public AbstractItemViewIdT<T>
{
public:
    using AbstractItemViewIdT<T>::AbstractItemViewIdT;

    N_ID_PROPERTY(bool         , firstSectionMovable    , N_READ isFirstSectionMovable    N_WRITE setFirstSectionMovable)
    N_ID_PROPERTY(bool         , showSortIndicator      , N_READ isSortIndicatorShown     N_WRITE setSortIndicatorShown )
    N_ID_PROPERTY(bool         , highlightSections      , N_READ highlightSections        N_WRITE setHighlightSections  )
    N_ID_PROPERTY(bool         , stretchLastSection     , N_READ stretchLastSection       N_WRITE setStretchLastSection )
    N_ID_PROPERTY(bool         , cascadingSectionResizes, N_READ cascadingSectionResizes                                )
    N_ID_PROPERTY(int          , defaultSectionSize     , N_READ defaultSectionSize       N_WRITE setDefaultSectionSize )
    N_ID_PROPERTY(int          , minimumSectionSize     , N_READ minimumSectionSize       N_WRITE setMinimumSectionSize )
    N_ID_PROPERTY(int          , maximumSectionSize     , N_READ maximumSectionSize       N_WRITE setMaximumSectionSize )
    N_ID_PROPERTY(Qt::Alignment, defaultAlignment       , N_READ defaultAlignment         N_WRITE setDefaultAlignment   )
    N_ID_PROPERTY(bool         , sortIndicatorClearable , N_READ isSortIndicatorClearable N_WRITE setSortIndicatorClearable N_NOTIFY sortIndicatorClearableChanged)
};

N_DECLARE_ID(HeaderView, HeaderViewIdT, QHeaderView)



template<typename S, typename T>
class HeaderViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

    using ResizeMode = QHeaderView::ResizeMode;

public:
    explicit HeaderViewBuilder(Qt::Orientation o) : AbstractItemViewBuilder<S, T>(new T(o)) {}
    explicit HeaderViewBuilder(T* target)         : AbstractItemViewBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(bool         , firstSectionMovable    , setFirstSectionMovable   )
    N_BUILDER_PROPERTY(bool         , showSortIndicator      , setSortIndicatorShown    )
    N_BUILDER_PROPERTY(bool         , highlightSections      , setHighlightSections     )
    N_BUILDER_PROPERTY(bool         , stretchLastSection     , setStretchLastSection    )
    N_BUILDER_PROPERTY(int          , defaultSectionSize     , setDefaultSectionSize    )
    N_BUILDER_PROPERTY(int          , minimumSectionSize     , setMinimumSectionSize    )
    N_BUILDER_PROPERTY(int          , maximumSectionSize     , setMaximumSectionSize    )
    N_BUILDER_PROPERTY(Qt::Alignment, defaultAlignment       , setDefaultAlignment      )
    N_BUILDER_PROPERTY(bool         , sortIndicatorClearable , setSortIndicatorClearable)

    S& resizeSection(int logicalIndex, int size)            { t->resizeSection(logicalIndex, size)       ;  return self(); }
    S& resizeSections(QHeaderView::ResizeMode mode)         { t->resizeSections(mode)                    ;  return self(); }
    S& hideSection(int logicalIndex)                        { t->hideSection(logicalIndex)               ;  return self(); }
    S& showSection(int logicalIndex)                        { t->showSection(logicalIndex)               ;  return self(); }
    S& sectionsMovable(bool movable)                        { t->setSectionsMovable(movable)             ;  return self(); }
    S& sectionsClickable(bool clickable)                    { t->setSectionsClickable(clickable)         ;  return self(); }
    S& sectionResizeMode(ResizeMode mode)                   { t->setSectionResizeMode(mode)              ;  return self(); }
    S& sectionResizeMode(int logicalIndex, ResizeMode mode) { t->setSectionResizeMode(logicalIndex, mode);  return self(); }
    S& resizeContentsPrecision(int precision)               { t->setResizeContentsPrecision(precision)   ;  return self(); }
    S& sortIndicatorShown(bool show)                        { t->setSortIndicatorShown(show)             ;  return self(); }
    S& sortIndicator(int logicalIndex, Qt::SortOrder order) { t->setSortIndicator(logicalIndex, order)   ;  return self(); }
    S& cascadingSectionResizes(bool enable)                 { t->setCascadingSectionResizes(enable)      ;  return self(); }
    S& offset(int v)                                        { t->offset(v)                               ;  return self(); }
    S& offsetToSectionPosition(int visualIndex)             { t->offsetToSectionPosition(visualIndex)    ;  return self(); }
    S& offsetToLastSection()                                { t->offsetToLastSection()                   ;  return self(); }

    N_BUILDER_SIGNAL(onSectionMoved                 , sectionMoved                 )
    N_BUILDER_SIGNAL(onSectionResized               , sectionResized               )
    N_BUILDER_SIGNAL(onSectionPressed               , sectionPressed               )
    N_BUILDER_SIGNAL(onSectionClicked               , sectionClicked               )
    N_BUILDER_SIGNAL(onSectionEntered               , sectionEntered               )
    N_BUILDER_SIGNAL(onSectionDoubleClicked         , sectionDoubleClicked         )
    N_BUILDER_SIGNAL(onSectionCountChanged          , sectionCountChanged          )
    N_BUILDER_SIGNAL(onSectionHandleDoubleClicked   , sectionHandleDoubleClicked   )
    N_BUILDER_SIGNAL(onGeometriesChanged            , geometriesChanged            )
    N_BUILDER_SIGNAL(onSortIndicatorChanged         , sortIndicatorChanged         )
    N_BUILDER_SIGNAL(onSortIndicatorClearableChanged, sortIndicatorClearableChanged)
};

N_DECLARE_BUILDER(HeaderView, HeaderViewBuilder, QHeaderView)

}

#endif // HEADERVIEW_H
