#ifndef NWIDGET_DATETIMEEDIT_H
#define NWIDGET_DATETIMEEDIT_H

#include <QDateTimeEdit>

#include "abstractspinbox.h"

namespace nwidget {

template<typename S, typename T>
class DateTimeEditBuilder : public AbstractSpinBoxBuilder<S, T>
{
    N_BUILDER

public:
    DateTimeEditBuilder()                             : AbstractSpinBoxBuilder<S, T>(new T) {}
    explicit DateTimeEditBuilder(const QDateTime& dt) : AbstractSpinBoxBuilder<S, T>(new T(dt)) {}
    explicit DateTimeEditBuilder(QDate date)          : AbstractSpinBoxBuilder<S, T>(new T(date)) {}
    explicit DateTimeEditBuilder(QTime time)          : AbstractSpinBoxBuilder<S, T>(new T(time)) {}
    explicit
    DateTimeEditBuilder(T* target)                    : AbstractSpinBoxBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(QDateTime              , dateTime           , setDateTime           )
    N_BUILDER_PROPERTY(QDate                  , date               , setDate               )
    N_BUILDER_PROPERTY(QTime                  , time               , setTime               )
    N_BUILDER_PROPERTY(QDateTime              , maximumDateTime    , setMaximumDateTime    )
    N_BUILDER_PROPERTY(QDateTime              , minimumDateTime    , setMinimumDateTime    )
    N_BUILDER_PROPERTY(QDate                  , maximumDate        , setMaximumDate        )
    N_BUILDER_PROPERTY(QDate                  , minimumDate        , setMinimumDate        )
    N_BUILDER_PROPERTY(QTime                  , maximumTime        , setMaximumTime        )
    N_BUILDER_PROPERTY(QTime                  , minimumTime        , setMinimumTime        )
    N_BUILDER_PROPERTY(QDateTimeEdit::Section , currentSection     , setCurrentSection     )
    N_BUILDER_PROPERTY(QString                , displayFormat      , setDisplayFormat      )
    N_BUILDER_PROPERTY(bool                   , calendarPopup      , setCalendarPopup      )
    N_BUILDER_PROPERTY(int                    , currentSectionIndex, setCurrentSectionIndex)
    N_BUILDER_PROPERTY(Qt::TimeSpec           , timeSpec           , setTimeSpec           )

    N_BUILDER_SETTER1(calendar       , setCalendar       )
    N_BUILDER_SETTER2(dateTimeRange  , setDateTimeRange  )
    N_BUILDER_SETTER2(dateRange      , setDateRange      )
    N_BUILDER_SETTER2(timeRange      , setTimeRange      )
    N_BUILDER_SETTER1(calendarWidget , setCalendarWidget )
    N_BUILDER_SETTER1(selectedSection, setSelectedSection)

    N_BUILDER_SIGNAL(onDateTimeChanged, dateTimeChanged)
    N_BUILDER_SIGNAL(onTimeChanged    , timeChanged    )
    N_BUILDER_SIGNAL(onDateChanged    , dateChanged    )
};

template<typename S, typename T>
class TimeEditBuilder : public DateTimeEditBuilder<S, T>
{
    N_BUILDER

public:
    TimeEditBuilder()                      : DateTimeEditBuilder<S, T>(new T) {}
    explicit TimeEditBuilder(QTime time)   : DateTimeEditBuilder<S, T>(new T(time)) {}
    explicit TimeEditBuilder(T* target)    : DateTimeEditBuilder<S, T>(target) {}
    TimeEditBuilder(T* target, QTime time) : DateTimeEditBuilder<S, T>(target, time) {}
};

template<typename S, typename T>
class DateEditBuilder : public DateTimeEditBuilder<S, T>
{
    N_BUILDER

public:
    DateEditBuilder()                      : DateTimeEditBuilder<S, T>(new T) {}
    explicit DateEditBuilder(QDate date)   : DateTimeEditBuilder<S, T>(new T(date)) {}
    explicit DateEditBuilder(T* target)    : DateTimeEditBuilder<S, T>(target) {}
    DateEditBuilder(T* target, QDate date) : DateTimeEditBuilder<S, T>(target, date) {}
};

N_DECLARE_BUILDER(DateTimeEdit, DateTimeEditBuilder, QDateTimeEdit)
N_DECLARE_BUILDER(TimeEdit    , TimeEditBuilder    , QTimeEdit    )
N_DECLARE_BUILDER(DateEdit    , DateEditBuilder    , QDateEdit    )



template <typename T>
class DateTimeEditIdT : public AbstractSpinBoxIdT<T>
{
public:
    using AbstractSpinBoxIdT<T>::AbstractSpinBoxIdT;

    N_ID_PROPERTY(QDateTime              , dateTime           , N_READ dateTime            N_WRITE setDateTime           N_NOTIFY dateTimeChanged)
    N_ID_PROPERTY(QDate                  , date               , N_READ date                N_WRITE setDate               N_NOTIFY dateChanged)
    N_ID_PROPERTY(QTime                  , time               , N_READ time                N_WRITE setTime               N_NOTIFY timeChanged)
    N_ID_PROPERTY(QDateTime              , maximumDateTime    , N_READ maximumDateTime     N_WRITE setMaximumDateTime    )
    N_ID_PROPERTY(QDateTime              , minimumDateTime    , N_READ minimumDateTime     N_WRITE setMinimumDateTime    )
    N_ID_PROPERTY(QDate                  , maximumDate        , N_READ maximumDate         N_WRITE setMaximumDate        )
    N_ID_PROPERTY(QDate                  , minimumDate        , N_READ minimumDate         N_WRITE setMinimumDate        )
    N_ID_PROPERTY(QTime                  , maximumTime        , N_READ maximumTime         N_WRITE setMaximumTime        )
    N_ID_PROPERTY(QTime                  , minimumTime        , N_READ minimumTime         N_WRITE setMinimumTime        )
    N_ID_PROPERTY(QDateTimeEdit::Section , currentSection     , N_READ currentSection      N_WRITE setCurrentSection     )
    N_ID_PROPERTY(QDateTimeEdit::Sections, displayedSections  , N_READ displayedSections                                 )
    N_ID_PROPERTY(QString                , displayFormat      , N_READ displayFormat       N_WRITE setDisplayFormat      )
    N_ID_PROPERTY(bool                   , calendarPopup      , N_READ calendarPopup       N_WRITE setCalendarPopup      )
    N_ID_PROPERTY(int                    , currentSectionIndex, N_READ currentSectionIndex N_WRITE setCurrentSectionIndex)
    N_ID_PROPERTY(int                    , sectionCount       , N_READ sectionCount                                      )
    N_ID_PROPERTY(Qt::TimeSpec           , timeSpec           , N_READ timeSpec            N_WRITE setTimeSpec           )
};

template <typename T>
class TimeEditIdT : public DateTimeEditIdT<T>
{
public:
    using DateTimeEditIdT<T>::DateTimeEditIdT;

    N_ID_PROPERTY(QTime, time, N_READ time N_WRITE setTime N_NOTIFY userTimeChanged)
};


template <typename T>
class DateEditIdT : public DateTimeEditIdT<T>
{
public:
    using DateTimeEditIdT<T>::DateTimeEditIdT;

    N_ID_PROPERTY(QDate, date, N_READ date N_WRITE setDate N_NOTIFY userDateChanged)
};

N_DECLARE_ID(DateTimeEdit, DateTimeEditIdT, QDateTimeEdit)
N_DECLARE_ID(TimeEdit, TimeEditIdT, QTimeEdit)
N_DECLARE_ID(DateEdit, DateEditIdT, QDateEdit)

}

#endif // NWIDGET_DATETIMEEDIT_H
