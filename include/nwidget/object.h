#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

#include "builder.h"

#if QT_VERSION <= QT_VERSION_CHECK(6, 6, 0)
#define N_SIGNAL_RECEIVER_TYPE(F) const typename QtPrivate::FunctionPointer<F>::ContextType*
#else
#define N_SIGNAL_RECEIVER_TYPE(F) const typename QtPrivate::ContextTypeForFunctor<F>::ContextType*
#endif

#define N_SIGNAL(NAME, SIG)                                                 \
template <typename Func>                                                    \
inline S& NAME(Func&& slot, Qt::ConnectionType type = Qt::AutoConnection)   \
{ QObject::connect(t, &SIG, t, slot); return self(); }                      \
template <typename Func>                                                    \
inline S& NAME(N_SIGNAL_RECEIVER_TYPE(Func) context, Func&& slot,           \
               Qt::ConnectionType type = Qt::AutoConnection)                \
{ QObject::connect(t, &SIG, context, slot); return self(); }

namespace nw {

template<typename S, typename T>
class ObjectBuilder : public Builder<S, T>
{
    N_USING_BUILDER_MEMBER(Builder, S, T)

public:
    using Builder<S, T>::Builder;

    inline S& connect(const char* signal, const QObject* receiver, const char* member,
                      Qt::ConnectionType = Qt::AutoConnection)
    { QObject::connect(t, signal, receiver, member); return self(); }

    inline S& connect(const QMetaMethod& signal, const QObject* receiver, const QMetaMethod& method,
                      Qt::ConnectionType type = Qt::AutoConnection)
    { QObject::connect(t, signal, receiver, method); return self(); }

    template <typename Func1, typename Func2>
    inline S& connect(Func1 signal, N_SIGNAL_RECEIVER_TYPE(Func2) context, Func2&& slot,
                      Qt::ConnectionType type = Qt::AutoConnection)
    { QObject::connect(t, signal, context, slot); return self(); }

    inline S& objectName(const QString& name)                       { t->setObjectName(name);     return self(); }
    inline S& objectName(QAnyStringView name)                       { t->setObjectName(name);     return self(); }

    inline S& property(const char* name, const QVariant& value)     { t->setProerty(name, value); return self(); }
    inline S& property(const char* name, QVariant&& value)          { t->setProerty(name, value); return self(); }

    N_SIGNAL(onDestroyed        , QObject::destroyed        )
    N_SIGNAL(onObjectNameChanged, QObject::objectNameChanged)
};

}

#endif // OBJECT_H
