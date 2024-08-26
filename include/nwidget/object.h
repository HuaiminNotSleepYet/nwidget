#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

#include "builder.h"

#if QT_VERSION <= QT_VERSION_CHECK(6, 6, 0)
#define N_SIGNAL_RECEIVER_TYPE(F) const typename QtPrivate::FunctionPointer<F>::Object*
#else
#define N_SIGNAL_RECEIVER_TYPE(F) const typename QtPrivate::ContextTypeForFunctor<F>::ContextType*
#endif

#define N_SIGNAL(NAME, SIG)                                     \
template <typename Func>                                        \
S& NAME(Func&& slot,                                            \
        Qt::ConnectionType type = Qt::AutoConnection)           \
{ QObject::connect(t, &SIG, t, slot); return self(); }          \
                                                                \
template <typename Func>                                        \
S& NAME(const QObject* receiver, Func method,                   \
        Qt::ConnectionType type = Qt::AutoConnection)           \
{ QObject::connect(t, &SIG, receiver, method); return self(); } \
                                                                \
template <typename Func>                                        \
S& NAME(N_SIGNAL_RECEIVER_TYPE(Func) context, Func&& slot,      \
        Qt::ConnectionType type = Qt::AutoConnection)           \
{ QObject::connect(t, &SIG, context, slot); return self(); }

#define N_BUILDER_PROPERTY(TYPE, NAME, SETTER)              \
S& NAME(const TYPE& arg) { t->SETTER(arg); return self(); } \
                                                            \
template<typename Info>                                     \
S& NAME(nw::Property<Info> prop)                            \
{ return NAME(nw::makeBindingExpr<nw::NoAction>(prop)); }   \
                                                            \
template<typename ...TN>                                    \
S& NAME(const nw::BindingExpr<TN...>& expr)                 \
{                                                           \
    using Object = typename std::decay<decltype(*t)>::type; \
    using Type = TYPE;                                      \
                                                            \
    N_SETTER(SETTER)                                        \
                                                            \
    struct Info                                             \
    {                                                       \
        using Object = Object;                              \
        using Type   = Type;                                \
        using Getter = NoGetter;                            \
        using Setter = Setter;                              \
        using Notify = NoNotify;                            \
                                                            \
        static QString name()                               \
        { return QStringLiteral(#NAME); }                   \
                                                            \
        static QString bindingName()                        \
        { return QStringLiteral("nw_binding_on_"#NAME); }   \
    };                                                      \
                                                            \
    expr.bindTo(nw::Property<Info>(t));                     \
                                                            \
    return self();                                          \
}

namespace nw {

template<typename S, typename T>
class ObjectBuilder : public Builder<S, T>
{
    N_USING_BUILDER_MEMBER(Builder, S, T)

public:
    using Builder<S, T>::Builder;

    S& connect(const char* signal, const QObject* receiver, const char* member,
               Qt::ConnectionType = Qt::AutoConnection)
    { QObject::connect(t, signal, receiver, member); return self(); }

    S& connect(const QMetaMethod& signal, const QObject* receiver, const QMetaMethod& method,
               Qt::ConnectionType type = Qt::AutoConnection)
    { QObject::connect(t, signal, receiver, method); return self(); }

    template <typename Func1, typename Func2>
    S& connect(Func1 signal, N_SIGNAL_RECEIVER_TYPE(Func2) context, Func2&& slot,
               Qt::ConnectionType type = Qt::AutoConnection)
    { QObject::connect(t, signal, context, slot); return self(); }

    S& objectName(const QString& name)                       { t->setObjectName(name);     return self(); }
    S& objectName(QAnyStringView name)                       { t->setObjectName(name);     return self(); }

    S& property(const char* name, const QVariant& value)     { t->setProperty(name, value); return self(); }
    S& property(const char* name, QVariant&& value)          { t->setProperty(name, value); return self(); }

    N_SIGNAL(onDestroyed        , QObject::destroyed        )
    N_SIGNAL(onObjectNameChanged, QObject::objectNameChanged)
};



struct NoGetter {};
struct NoSetter {};
struct NoNotify {};

template<typename PropertyInfo> class Property;



class Binding : public QObject
{
    Q_OBJECT

    template<typename Action, typename ...Args> friend class BindingExpr;

    Binding(QObject* parent = nullptr) : QObject(parent) {}

signals:
    void update();
};



struct NoAction { template<typename T> auto operator()(const T& value) { return value; } };

template<typename T> struct ActionConstructor { template<typename ...Args> T operator()(const Args&... args){ return T(args...); }; };

template<typename To> struct ActionCast            { template<typename From> auto operator()(const From& from){ return (To)from; };  };
template<typename To> struct ActionStaticCast      { template<typename From> auto operator()(const From& from){ return static_cast<To>(from); };  };
template<typename To> struct ActionReinterpretCast { template<typename From> auto operator()(const From& from){ return reinterpret_cast<To>(from); };  };

struct ActionCond { template<typename A, typename B, typename C> auto operator()(const A& a, const B& b, const C& c) { return a ? b : c; } };

struct ActionCall { template<typename Func, typename ...Args> auto operator()(Func func, const Args&... args) { return func(args...); } };

struct ActionInvoke
{
    template<typename Func, class Object, typename ...Args>
    auto operator()(Func func, const Object& obj, const Args&... args)
    {
        if constexpr (std::is_pointer<Object>::value) {
            Q_ASSERT(obj);
            return func(obj, args...);
        } else {
            return func(&obj, args...);
        }
    }
};

#define N_ACTION_BE(NAME, OPERATOR) \
struct Action##NAME { template<typename L, typename R> auto operator()(const L& l, const R& r) { return l OPERATOR r; } };

#define N_ACTION_UE(NAME, OPERATOR) \
struct Action##NAME { template<typename T> auto operator()(const T& t) { return OPERATOR t; } };

N_ACTION_BE(Add, +)
N_ACTION_BE(Sub, -)
N_ACTION_BE(Mul, *)
N_ACTION_BE(Div, /)

N_ACTION_BE(EQ, ==)
N_ACTION_BE(NE, !=)
N_ACTION_BE(LT, < )
N_ACTION_BE(LE, <=)
N_ACTION_BE(GT, > )
N_ACTION_BE(GE, >=)

N_ACTION_BE(AND, &&)
N_ACTION_BE(OR , ||)

N_ACTION_BE(BitAnd   , & )
N_ACTION_BE(BitOR    , | )
N_ACTION_BE(BitXOR   , ^ )
N_ACTION_BE(BitLShift, <<)
N_ACTION_BE(BitRShift, >>)

N_ACTION_UE(Plus  , +)
N_ACTION_UE(Minus , -)
N_ACTION_UE(Not   , !)

N_ACTION_UE(BitNot, ~)
N_ACTION_UE(AddressOf, &)
N_ACTION_UE(ContentOf, *)



template<typename Action, typename ...Args> class BindingExpr;

template<typename Action, typename ...Args>
auto makeBindingExpr(const Args&... args) { return BindingExpr<Action, Args...>(args...); }

template<typename Action, typename ...Args>
class BindingExpr
{
    template<typename A, typename ...TN> friend class BindingExpr;
    template<typename PropertyInfo> friend class Property;

public:
    BindingExpr(const Args&... args) : args(args...) {}

    template<typename Func, typename ...Args_>
    auto invoke(Func func, const Args_&... args) const
    {
        static_assert(std::is_member_function_pointer<Func>::value, "The arg func must be a member function.");
        return makeBindingExpr<ActionInvoke>(std::mem_fn(func), *this, args...);
    }

    // How do I expand a tuple into variadic template function's arguments? https://stackoverflow.com/questions/687490
    //   - The std::apply won't work if the_function is templated.
    auto operator()() const
    { return std::apply(Action{}, std::apply([](auto&&... args){ return calc(args...); }, args)); }

    template<typename Info>
    Binding* bindTo(Property<Info> prop) const
    {
        typename Info::Object* object = prop.object;

        Binding* bind = static_cast<QObject*>(object)->findChild<Binding*>(Info::bindingName(), Qt::FindDirectChildrenOnly);
        if (bind)
            bind->deleteLater();

        if constexpr (!isObservable<Args...>())
            bind = nullptr;
        else {
            bind = new Binding(object);
            bind->setObjectName(Info::bindingName());
            bindTo(prop, bind);
            QObject::connect(bind  , &Binding::update   , bind, [object, expr = *this](){
                Info::Setter::set(object, expr());
            });
        }

        Info::Setter::set(object, (*this)());
        return bind;
    }

private:
    std::tuple<Args...> args;

    template<typename    T> static auto calc(const T& value)                { return std::make_tuple(value);      }
    template<typename    T> static auto calc(Property<T> prop)              { return std::make_tuple(prop.get()); }
    template<typename ...T> static auto calc(const BindingExpr<T...>& expr) { return std::make_tuple(expr());     }

    template<typename Arg0, typename ...ArgN>
    static auto calc(const Arg0& arg0, const ArgN&... argn)
    { return std::tuple_cat(calc(arg0), calc(argn...)); }


    template<typename T> struct is_observable { static constexpr bool value = false; };

    template<typename T0, typename ...TN>
    static constexpr bool isObservable() {
        if constexpr (is_observable<T0>::value)
            return true;
        if constexpr (sizeof...(TN) > 0)
            return isObservable<TN...>();
        return false;
    }

    template<typename T> struct is_observable<Property<T>>
    { static constexpr bool value = !std::is_same<typename T::Notify, NoNotify>::value; };

    template<typename A, typename ...TN> struct is_observable<BindingExpr<A, TN...>>
    { static constexpr bool value = isObservable<TN...>(); };


    template<typename Info, typename    T> static void bindTo(Property<Info>, Binding*, const T&) {}
    template<typename Info, typename ...T> static void bindTo(Property<Info> prop, Binding* bind, const BindingExpr<T...>& expr) { return expr.bindTo(prop, bind); }
    template<typename InfoA, typename InfoB>
    static void bindTo(Property<InfoA> to, Binding* bind, Property<InfoB> from)
    {
        if constexpr (!std::is_same<typename InfoB::Notify, NoNotify>::value) {
            if constexpr (!std::is_same<Property<InfoA>, Property<InfoB>>::value) {
                QObject::connect(from.object, &QObject::destroyed    , bind, &Binding::deleteLater, Qt::UniqueConnection);
                QObject::connect(from.object, InfoB::Notify::signal(), bind, &Binding::update     , Qt::UniqueConnection);
            } else if (from.object != to.object) {
                QObject::connect(from.object, &QObject::destroyed    , bind, &Binding::deleteLater, Qt::UniqueConnection);
                QObject::connect(from.object, InfoB::Notify::signal(), bind, &Binding::update     , Qt::UniqueConnection);
            }
        }
    }

    template<typename Info, typename Arg0, typename ...ArgN>
    static void bindTo(Property<Info> prop, Binding* bind, Arg0 arg0, ArgN... argn)
    {
        bindTo(prop, bind, arg0);
        bindTo(prop, bind, argn...);
    }

    template<typename Info>
    void bindTo(Property<Info> prop, Binding* bind) const
    { std::apply([prop, bind](auto&&... args){ bindTo(prop, bind, args...); }, args); }
};



template<typename PropertyInfo>
class Property
{
// PropertyInfo should have the following members:
//   struct Info
//   {
//       using Object = ...
//       using Type   = ...
//       using Getter = ...
//       using Setter = ...
//       using Notify = ...
//
//       static QString name()        "propertyName"
//       static QString bindingName() "nw_binding_on_propertyName"
//   };

    template<typename T0, typename ...TN> friend class BindingExpr;

public:
    using Info = PropertyInfo;
    using Object = typename Info::Object;
    using Type   = typename Info::Type;
    using Getter = typename Info::Getter;
    using Setter = typename Info::Setter;
    using Notify = typename Info::Notify;

    explicit Property(Object* object) : object(object) {}

    typename Info::Type get() const { return Getter::get(object); }

    void set(const Type& value)
    {
        Binding* bind = static_cast<QObject*>(object)->findChild<Binding*>(Info::bindingName(), Qt::FindDirectChildrenOnly);
        if (bind)
            bind->deleteLater();
        return Setter::set(object, value);
    }

    operator Type() const { return get(); }

    void operator=(const Type& value) { set(value); }

    auto operator++()    { Type val = get(); set(++val);   return val; }
    auto operator++(int) { Type val = get(); set(++get()); return val; }
    auto operator--()    { Type val = get(); set(--val);   return val; }
    auto operator--(int) { Type val = get(); set(--get()); return val; }

    template<typename T> void operator+= (const T& r) { set(get() +  r); }
    template<typename T> void operator-= (const T& r) { set(get() -  r); }
    template<typename T> void operator*= (const T& r) { set(get() *  r); }
    template<typename T> void operator/= (const T& r) { set(get() /  r); }
    template<typename T> void operator%= (const T& r) { set(get() %  r); }
    template<typename T> void operator^= (const T& r) { set(get() ^  r); }
    template<typename T> void operator&= (const T& r) { set(get() &  r); }
    template<typename T> void operator|= (const T& r) { set(get() |  r); }
    template<typename T> void operator<<=(const T& r) { set(get() << r); }
    template<typename T> void operator>>=(const T& r) { set(get() >> r); }

    Binding* operator=(Property<Info> prop) { return makeBindingExpr<NoAction>(prop).bindTo(*this); }

    template<typename T>
    Binding* operator=(Property<T>    prop) { return makeBindingExpr<NoAction>(prop).bindTo(*this); }

    template<typename Action, typename ...Args>
    Binding* operator=(const BindingExpr<Action, Args...>& expr) { return expr.bindTo(*this); }

    template<typename Func, typename ...Args>
    auto invoke(Func func, const Args&... args) const
    {
        static_assert(std::is_member_function_pointer<Func>::value, "The arg func must be a member function.");
        return makeBindingExpr<ActionInvoke>(std::mem_fn(func), *this, args...);
    }

public:
    Object* object;
};



template<typename T, typename ...Args>
auto constructor(const Args&... args) { return makeBindingExpr<ActionConstructor<T>>(args...); }

template<typename F, typename ...Args>
auto call(F f, const Args&... args) { return makeBindingExpr<ActionCall>(f, args...); }

template<typename A, typename B, typename C>
auto cond(const A& a, const B& b, const C& c) { return makeBindingExpr<ActionCond>(a, b, c); }

template<typename To, typename From> auto cast(const From& from)              { return makeBindingExpr<ActionCast<To>>(from); }
template<typename To, typename From> auto static_cast_(const From& from)      { return makeBindingExpr<ActionStaticCast<To>>(from); }
template<typename To, typename From> auto reinterpret_cast_(const From& from) { return makeBindingExpr<ActionReinterpretCast<To>>(from); }

template<typename ...Args> auto asprintf(const char* cformat, const Args&... args) { return call(QString::asprintf, cformat, args...); }

#define N_BINDING_EXPR_BE(NAME, ACTION)                                                                                                             \
template<typename L, typename R> auto NAME(Property<L> l, const R   & r) { return makeBindingExpr<ACTION>(l, r); }                                  \
template<typename L, typename R> auto NAME(const L   & l, Property<R> r) { return makeBindingExpr<ACTION>(l, r); }                                  \
template<typename L, typename R> auto NAME(Property<L> l, Property<R> r) { return makeBindingExpr<ACTION>(l, r); }                                  \
                                                                                                                                                    \
template<typename ...L, typename    R> auto NAME(const BindingExpr<L...>& l, const R                & r) { return makeBindingExpr<ACTION>(l, r); }  \
template<typename    L, typename ...R> auto NAME(const L                & l, const BindingExpr<R...>& r) { return makeBindingExpr<ACTION>(l, r); }  \
template<typename ...L, typename ...R> auto NAME(const BindingExpr<L...>& l, const BindingExpr<R...>& r) { return makeBindingExpr<ACTION>(l, r); }  \
                                                                                                                                                    \
template<typename    L, typename ...R> auto NAME(Property<L>              l, const BindingExpr<R...>& r) { return makeBindingExpr<ACTION>(l, r); }  \
template<typename ...L, typename    R> auto NAME(const BindingExpr<L...>& l, Property<R>              r) { return makeBindingExpr<ACTION>(l, r); }

#define N_BINDING_EXPR_UE(NAME, ACTION)                                                                      \
template<typename    T> auto NAME(Property<T>              value) { return makeBindingExpr<ACTION>(value); } \
template<typename ...T> auto NAME(const BindingExpr<T...>& value) { return makeBindingExpr<ACTION>(value); }

N_BINDING_EXPR_BE(operator+, ActionAdd)
N_BINDING_EXPR_BE(operator-, ActionSub)
N_BINDING_EXPR_BE(operator*, ActionMul)
N_BINDING_EXPR_BE(operator/, ActionDiv)

N_BINDING_EXPR_BE(operator==, ActionEQ)
N_BINDING_EXPR_BE(operator!=, ActionNE)
N_BINDING_EXPR_BE(operator< , ActionLT)
N_BINDING_EXPR_BE(operator<=, ActionLE)
N_BINDING_EXPR_BE(operator> , ActionGT)
N_BINDING_EXPR_BE(operator>=, ActionGE)

N_BINDING_EXPR_BE(operator&&, ActionAND)
N_BINDING_EXPR_BE(operator||, ActionOR )

N_BINDING_EXPR_BE(operator& , ActionBitAnd   )
N_BINDING_EXPR_BE(operator| , ActionBitOR    )
N_BINDING_EXPR_BE(operator^ , ActionBitXOR   )
N_BINDING_EXPR_BE(operator<<, ActionBitLShift)
N_BINDING_EXPR_BE(operator>>, ActionBitRShift)

N_BINDING_EXPR_UE(operator+, ActionPlus     )
N_BINDING_EXPR_UE(operator-, ActionMinus    )
N_BINDING_EXPR_UE(operator!, ActionNot      )
N_BINDING_EXPR_UE(operator~, ActionBitNot   )
N_BINDING_EXPR_UE(operator&, ActionAddressOf)
N_BINDING_EXPR_UE(operator*, ActionContentOf)



#define N_GETTER(FUNC) struct Getter { static auto get(const Object* object) { return object->FUNC(); } };
#define N_SETTER(FUNC) struct Setter { static void set(Object* object, const Type& value) { object->FUNC(value); } };
#define N_NOTIFY(SIG)  struct Notify { static constexpr auto signal() { return &Object::SIG; } };

#define N_NO_SETTER using Setter = nw::NoSetter;
#define N_NO_GETTER using Getter = nw::NoGetter;
#define N_NO_NOTIFY using Notify = nw::NoNotify;

#define N_PROPERTY(TYPE, NAME, GETTER, SETTER, NOTIFY)              \
auto NAME() const                                                   \
{                                                                   \
    using Object = typename std::decay<decltype(*this->t)>::type;   \
    using Type = TYPE;                                              \
                                                                    \
    GETTER                                                          \
    SETTER                                                          \
    NOTIFY                                                          \
                                                                    \
    struct Info                                                     \
    {                                                               \
        using Notify = Notify;                                      \
        using Object = Object;                                      \
        using Type   = TYPE;                                        \
        using Getter = Getter;                                      \
        using Setter = Setter;                                      \
                                                                    \
        static QString name()                                       \
        { return QStringLiteral(#NAME); }                           \
                                                                    \
        static QString bindingName()                                \
        { return QStringLiteral("nw_binding_on_"#NAME); }           \
    };                                                              \
                                                                    \
    Q_ASSERT(nw::ObjectIdT<Object>::t);                             \
    return nw::Property<Info>(nw::ObjectIdT<Object>::t);            \
}

template<typename T>
class ObjectIdT
{
public:
    ObjectIdT(T* target) : t(target) { Q_ASSERT(target); }

    T* get() const { return t; }

    operator T*() const { return t; }

    T* operator->() const  { return t; }

    T& operator*() const { return *t; }

    N_PROPERTY(QString, objectName, N_GETTER(objectName), N_SETTER(setObjectName), N_NOTIFY(objectNameChanged))

protected:
    T* t;
};

using ObjectId = ObjectIdT<QObject>;

}

#endif // OBJECT_H
