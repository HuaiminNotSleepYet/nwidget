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
    DateTimeEditBuilder()                   : AbstractSpinBoxBuilder<S, T>(new T) {}
    explicit DateTimeEditBuilder(T* target) : AbstractSpinBoxBuilder<S, T>(target) {}

    inline S& calendar(QCalendar calendar)                              { t->setCalendar(calendar);         return self(); }

    inline S& minimumDateTime(const QDateTime& dt)                      { t->setMinimumDateTime(dt);        return self(); }
    inline S& maximumDateTime(const QDateTime& dt)                      { t->setMaximumDateTime(dt);        return self(); }
    inline S& dateTimeRange(const QDateTime& min, const QDateTime& max) { t->setDateTimeRange(min, max);    return self(); }

    inline S& minimumDate(QDate min)                                    { t->setMinimumDate(min);           return self(); }
    inline S& maximumDate(QDate max)                                    { t->setMaximumDate(max);           return self(); }
    inline S& dateRange(QDate min, QDate max)                           { t->setDateRange(min, max);        return self(); }

    inline S& minimumTime(QTime min)                                    { t->setMinimumTime(min);           return self(); }
    inline S& maximumTime(QTime max)                                    { t->setMaximumTime(max);           return self(); }
    inline S& timeRange(QTime min, QTime max)                           { t->setTimeRange(min, max);        return self(); }

    inline S& currentSection(QDateTimeEdit::Section section)            { t->setCurrentSection(section);    return self(); }
    inline S& currentSectionIndex(int index)                            { t->setCurrentSectionIndex(index); return self(); }

    inline S& calendarWidget(QCalendarWidget* widget)                   { t->setCalendarWidget(widget);     return self(); }
    inline S& selectedSection(QDateTimeEdit::Section section)           { t->setSelectedSection(section);   return self(); }
    inline S& displayFormat(const QString& format)                      { t->setDisplayFormat(format);      return self(); }
    inline S& calendarPopup(bool enable)                                { t->setCalendarPopup(enable);      return self(); }

#if QT_DEPRECATED_SINCE(6, 10)
    QT_DEPRECATED_VERSION_X_6_10("Use timeZone() instead")
    inline S& timeSpec(Qt::TimeSpec spec)                               { t->setTimeSpec(spec);             return self(); }
#endif

    inline S& timeZone(const QTimeZone& zone)                           { t->setTimeZone(zone);             return self(); }

    inline S& dateTime(const QDateTime& dateTime)                       { t->setDateTime(dateTime);         return self(); }
    inline S& date(QDate date)                                          { t->setDate(date);                 return self(); }
    inline S& time(QTime time)                                          { t->setTime(time);                 return self(); }

    N_SIGNAL(onDateTimeChanged, QDateTimeEdit::dateTimeChanged)
    N_SIGNAL(onTimeChanged    , QDateTimeEdit::timeChanged    )
    N_SIGNAL(onDateChanged    , QDateTimeEdit::dateChanged    )
};

N_BUILDER_IMPL(DateTimeEditBuilder, QDateTimeEdit, DateTimeEdit);

}

#endif // DATETIMEEDIT_H
