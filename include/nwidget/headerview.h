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

N_DECLARE_ID_N(HeaderView, HeaderViewIdT, QHeaderView)



template<typename S, typename T>
class HeaderViewBuilder : public AbstractItemViewBuilder<S, T>
{
    N_BUILDER

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

    N_BUILDER_SETTER2(resizeSection          , resizeSection             )
    N_BUILDER_SETTER1(resizeSections         , resizeSections            )
    N_BUILDER_SETTER1(hideSection            , hideSection               )
    N_BUILDER_SETTER1(showSection            , showSection               )
    N_BUILDER_SETTER1(sectionsMovable        , setSectionsMovable        )
    N_BUILDER_SETTER1(sectionsClickable      , setSectionsClickable      )
    N_BUILDER_SETTER1(sectionResizeMode      , setSectionResizeMode      )
    N_BUILDER_SETTER2(sectionResizeMode      , setSectionResizeMode      )
    N_BUILDER_SETTER1(resizeContentsPrecision, setResizeContentsPrecision)
    N_BUILDER_SETTER1(sortIndicatorShown     , setSortIndicatorShown     )
    N_BUILDER_SETTER2(sortIndicator          , setSortIndicator          )
    N_BUILDER_SETTER1(cascadingSectionResizes, setCascadingSectionResizes)
    N_BUILDER_SETTER1(offset                 , setOffset                 )
    N_BUILDER_SETTER1(offsetToSectionPosition, setOffsetToSectionPosition)
    N_BUILDER_SETTER0(offsetToLastSection    , setOffsetToLastSection    )

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

N_DECLARE_BUILDER_N(HeaderView, HeaderViewBuilder, QHeaderView)

}

#endif // HEADERVIEW_H
