#ifndef DATETIMEEDIT_H
#define DATETIMEEDIT_H

#include <QDateTimeEdit>

#include "abstractspinbox.h"

namespace nw {

template<typename S, typename T>
class DateTimeEditBuilder : public AbstractSpinBoxBuilder<S, T>
{
    N_BUILDER

public:
    DateTimeEditBuilder()                             : AbstractSpinBoxBuilder<S, T>(new T) {}
    explicit DateTimeEditBuilder(const QDateTime& dt) : AbstractSpinBoxBuilder<S, T>(new T(dt)) {}
    explicit DateTimeEditBuilder(QDate date)          : AbstractSpinBoxBuilder<S, T>(new T(date)) {}
    explicit DateTimeEditBuilder(QTime time)          : AbstractSpinBoxBuilder<S, T>(new T(time)) {}

    explicit DateTimeEditBuilder(T* target)             : AbstractSpinBoxBuilder<S, T>(target) {}
    DateTimeEditBuilder(T* target, const QDateTime& dt) : AbstractSpinBoxBuilder<S, T>(target) { t->setDateTime(dt); }
    DateTimeEditBuilder(T* target, QDate date)          : AbstractSpinBoxBuilder<S, T>(target) { t->setDate(date); }
    DateTimeEditBuilder(T* target, QTime time)          : AbstractSpinBoxBuilder<S, T>(target) { t->setTime(time); }

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

    S& calendar(QCalendar calendar)                              { t->setCalendar(calendar)      ; return self(); }
    S& dateTimeRange(const QDateTime& min, const QDateTime& max) { t->setDateTimeRange(min, max) ; return self(); }
    S& dateRange(QDate min, QDate max)                           { t->setDateRange(min, max)     ; return self(); }
    S& timeRange(QTime min, QTime max)                           { t->setTimeRange(min, max)     ; return self(); }
    S& calendarWidget(QCalendarWidget* widget)                   { t->setCalendarWidget(widget)  ; return self(); }
    S& selectedSection(QDateTimeEdit::Section section)           { t->setSelectedSection(section); return self(); }
    S& timeZone(const QTimeZone& zone)                           { t->setTimeZone(zone)          ; return self(); }

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

N_DECL_BUILDER(DateTimeEditBuilder, QDateTimeEdit, DateTimeEdit);
N_DECL_BUILDER(TimeEditBuilder    , QTimeEdit    , TimeEdit    );
N_DECL_BUILDER(DateEditBuilder    , QDateEdit    , DateEdit    );



template <typename T>
class DateTimeEditIdT : public AbstractSpinBoxIdT<T>
{
public:
    using AbstractSpinBoxIdT<T>::AbstractSpinBoxIdT;

    N_ID_PROPERTY(QDateTime              , dateTime           , N_GETTER(dateTime           ), N_SETTER(setDateTime           ), N_NOTIFY(dateTimeChanged))
    N_ID_PROPERTY(QDate                  , date               , N_GETTER(date               ), N_SETTER(setDate               ), N_NOTIFY(dateChanged))
    N_ID_PROPERTY(QTime                  , time               , N_GETTER(time               ), N_SETTER(setTime               ), N_NOTIFY(timeChanged))
    N_ID_PROPERTY(QDateTime              , maximumDateTime    , N_GETTER(maximumDateTime    ), N_SETTER(setMaximumDateTime    ), N_NO_NOTIFY)
    N_ID_PROPERTY(QDateTime              , minimumDateTime    , N_GETTER(minimumDateTime    ), N_SETTER(setMinimumDateTime    ), N_NO_NOTIFY)
    N_ID_PROPERTY(QDate                  , maximumDate        , N_GETTER(maximumDate        ), N_SETTER(setMaximumDate        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QDate                  , minimumDate        , N_GETTER(minimumDate        ), N_SETTER(setMinimumDate        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QTime                  , maximumTime        , N_GETTER(maximumTime        ), N_SETTER(setMaximumTime        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QTime                  , minimumTime        , N_GETTER(minimumTime        ), N_SETTER(setMinimumTime        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QDateTimeEdit::Section , currentSection     , N_GETTER(currentSection     ), N_SETTER(setCurrentSection     ), N_NO_NOTIFY)
    N_ID_PROPERTY(QDateTimeEdit::Sections, displayedSections  , N_GETTER(displayedSections  ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_ID_PROPERTY(QString                , displayFormat      , N_GETTER(displayFormat      ), N_SETTER(setDisplayFormat      ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                   , calendarPopup      , N_GETTER(calendarPopup      ), N_SETTER(setCalendarPopup      ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                    , currentSectionIndex, N_GETTER(currentSectionIndex), N_SETTER(setCurrentSectionIndex), N_NO_NOTIFY)
    N_ID_PROPERTY(int                    , sectionCount       , N_GETTER(sectionCount       ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::TimeSpec           , timeSpec           , N_GETTER(timeSpec           ), N_SETTER(setTimeSpec           ), N_NO_NOTIFY)
};

template <typename T>
class TimeEditIdT : public DateTimeEditIdT<T>
{
public:
    using DateTimeEditIdT<T>::DateTimeEditIdT;

    N_ID_PROPERTY(QTime, time, N_GETTER(time), N_SETTER(setTime), N_NOTIFY(userTimeChanged))
};


template <typename T>
class DateEditIdT : public DateTimeEditIdT<T>
{
public:
    using DateTimeEditIdT<T>::DateTimeEditIdT;

    N_ID_PROPERTY(QDate, date, N_GETTER(date), N_SETTER(setDate), N_NOTIFY(userDateChanged))
};

using DateTimeEditId = DateTimeEditIdT<QDateTimeEdit>;
using TimeEditId = TimeEditIdT<QTimeEdit>;
using DateEditId = DateEditIdT<QDateEdit>;

}

#endif // DATETIMEEDIT_H
