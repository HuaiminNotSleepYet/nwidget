#ifndef DATETIMEEDIT_H
#define DATETIMEEDIT_H

#include <QDateTimeEdit>

#include "abstractspinbox.h"

namespace nw {

template<typename S, typename T>
class DateTimeEditBuilder : public AbstractSpinBoxBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(AbstractSpinBoxBuilder, S, T)

public:
    DateTimeEditBuilder()                             : AbstractSpinBoxBuilder<S, T>(new T) {}
    explicit DateTimeEditBuilder(const QDateTime& dt) : AbstractSpinBoxBuilder<S, T>(new T(dt)) {}
    explicit DateTimeEditBuilder(QDate date)          : AbstractSpinBoxBuilder<S, T>(new T(date)) {}
    explicit DateTimeEditBuilder(QTime time)          : AbstractSpinBoxBuilder<S, T>(new T(time)) {}

    explicit DateTimeEditBuilder(T* target)             : AbstractSpinBoxBuilder<S, T>(target) {}
    DateTimeEditBuilder(T* target, const QDateTime& dt) : AbstractSpinBoxBuilder<S, T>(target) { t->setDateTime(dt); }
    DateTimeEditBuilder(T* target, QDate date)          : AbstractSpinBoxBuilder<S, T>(target) { t->setDate(date); }
    DateTimeEditBuilder(T* target, QTime time)          : AbstractSpinBoxBuilder<S, T>(target) { t->setTime(time); }

    S& calendar(QCalendar calendar)                              { t->setCalendar(calendar);         return self(); }

    S& minimumDateTime(const QDateTime& dt)                      { t->setMinimumDateTime(dt);        return self(); }
    S& maximumDateTime(const QDateTime& dt)                      { t->setMaximumDateTime(dt);        return self(); }
    S& dateTimeRange(const QDateTime& min, const QDateTime& max) { t->setDateTimeRange(min, max);    return self(); }

    S& minimumDate(QDate min)                                    { t->setMinimumDate(min);           return self(); }
    S& maximumDate(QDate max)                                    { t->setMaximumDate(max);           return self(); }
    S& dateRange(QDate min, QDate max)                           { t->setDateRange(min, max);        return self(); }

    S& minimumTime(QTime min)                                    { t->setMinimumTime(min);           return self(); }
    S& maximumTime(QTime max)                                    { t->setMaximumTime(max);           return self(); }
    S& timeRange(QTime min, QTime max)                           { t->setTimeRange(min, max);        return self(); }

    S& currentSection(QDateTimeEdit::Section section)            { t->setCurrentSection(section);    return self(); }
    S& currentSectionIndex(int index)                            { t->setCurrentSectionIndex(index); return self(); }

    S& calendarWidget(QCalendarWidget* widget)                   { t->setCalendarWidget(widget);     return self(); }
    S& selectedSection(QDateTimeEdit::Section section)           { t->setSelectedSection(section);   return self(); }
    S& displayFormat(const QString& format)                      { t->setDisplayFormat(format);      return self(); }
    S& calendarPopup(bool enable)                                { t->setCalendarPopup(enable);      return self(); }

#if QT_DEPRECATED_SINCE(6, 10)
    QT_DEPRECATED_VERSION_X_6_10("Use timeZone() instead")
    S& timeSpec(Qt::TimeSpec spec)                               { t->setTimeSpec(spec);             return self(); }
#endif

    S& timeZone(const QTimeZone& zone)                           { t->setTimeZone(zone);             return self(); }

    S& dateTime(const QDateTime& dateTime)                       { t->setDateTime(dateTime);         return self(); }
    S& date(QDate date)                                          { t->setDate(date);                 return self(); }
    S& time(QTime time)                                          { t->setTime(time);                 return self(); }

    N_SIGNAL(onDateTimeChanged, QDateTimeEdit::dateTimeChanged)
    N_SIGNAL(onTimeChanged    , QDateTimeEdit::timeChanged    )
    N_SIGNAL(onDateChanged    , QDateTimeEdit::dateChanged    )
};

template<typename S, typename T>
class TimeEditBuilder : public DateTimeEditBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(DateTimeEditBuilder, S, T)

public:
    TimeEditBuilder()                      : DateTimeEditBuilder<S, T>(new T) {}
    explicit TimeEditBuilder(QTime time)   : DateTimeEditBuilder<S, T>(new T(time)) {}
    explicit TimeEditBuilder(T* target)    : DateTimeEditBuilder<S, T>(target) {}
    TimeEditBuilder(T* target, QTime time) : DateTimeEditBuilder<S, T>(target, time) {}
};

template<typename S, typename T>
class DateEditBuilder : public DateTimeEditBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(DateTimeEditBuilder, S, T)

public:
    DateEditBuilder()                      : DateTimeEditBuilder<S, T>(new T) {}
    explicit DateEditBuilder(QDate date)   : DateTimeEditBuilder<S, T>(new T(date)) {}
    explicit DateEditBuilder(T* target)    : DateTimeEditBuilder<S, T>(target) {}
    DateEditBuilder(T* target, QDate date) : DateTimeEditBuilder<S, T>(target, date) {}
};

N_BUILDER_IMPL(DateTimeEditBuilder, QDateTimeEdit, DateTimeEdit);
N_BUILDER_IMPL(TimeEditBuilder    , QTimeEdit    , TimeEdit    );
N_BUILDER_IMPL(DateEditBuilder    , QDateEdit    , DateEdit    );

}

#endif // DATETIMEEDIT_H
