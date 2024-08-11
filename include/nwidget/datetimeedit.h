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

N_BUILDER_IMPL(DateTimeEditBuilder, QDateTimeEdit, DateTimeEdit);



template <typename T>
class DateTimeEditRefT : public AbstractSpinBoxRefT<T>
{
public:
    using AbstractSpinBoxRefT<T>::AbstractSpinBoxRefT;

    N_PROPERTY(QDateTime              , dateTime           , N_GETTER(dateTime           ), N_SETTER(setDateTime           ), N_NOTIFY(dateTimeChanged))
    N_PROPERTY(QDate                  , date               , N_GETTER(date               ), N_SETTER(setDate               ), N_NOTIFY(dateChanged))
    N_PROPERTY(QTime                  , time               , N_GETTER(time               ), N_SETTER(setTime               ), N_NOTIFY(timeChanged))
    N_PROPERTY(QDateTime              , maximumDateTime    , N_GETTER(maximumDateTime    ), N_SETTER(setMaximumDateTime    ), N_NO_NOTIFY)
    N_PROPERTY(QDateTime              , minimumDateTime    , N_GETTER(minimumDateTime    ), N_SETTER(setMinimumDateTime    ), N_NO_NOTIFY)
    N_PROPERTY(QDate                  , maximumDate        , N_GETTER(maximumDate        ), N_SETTER(setMaximumDate        ), N_NO_NOTIFY)
    N_PROPERTY(QDate                  , minimumDate        , N_GETTER(minimumDate        ), N_SETTER(setMinimumDate        ), N_NO_NOTIFY)
    N_PROPERTY(QTime                  , maximumTime        , N_GETTER(maximumTime        ), N_SETTER(setMaximumTime        ), N_NO_NOTIFY)
    N_PROPERTY(QTime                  , minimumTime        , N_GETTER(minimumTime        ), N_SETTER(setMinimumTime        ), N_NO_NOTIFY)
    N_PROPERTY(QDateTimeEdit::Section , currentSection     , N_GETTER(currentSection     ), N_SETTER(setCurrentSection     ), N_NO_NOTIFY)
    N_PROPERTY(QDateTimeEdit::Sections, displayedSections  , N_GETTER(displayedSections  ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_PROPERTY(QString                , displayFormat      , N_GETTER(displayFormat      ), N_SETTER(setDisplayFormat      ), N_NO_NOTIFY)
    N_PROPERTY(bool                   , calendarPopup      , N_GETTER(calendarPopup      ), N_SETTER(setCalendarPopup      ), N_NO_NOTIFY)
    N_PROPERTY(int                    , currentSectionIndex, N_GETTER(currentSectionIndex), N_SETTER(setCurrentSectionIndex), N_NO_NOTIFY)
    N_PROPERTY(int                    , sectionCount       , N_GETTER(sectionCount       ), N_NO_SETTER                     , N_NO_NOTIFY)
    N_PROPERTY(Qt::TimeSpec           , timeSpec           , N_GETTER(timeSpec           ), N_SETTER(setTimeSpec           ), N_NO_NOTIFY)
};

using DateTimeEditRef = DateTimeEditRefT<QDateTimeEdit>;

}

#endif // DATETIMEEDIT_H
