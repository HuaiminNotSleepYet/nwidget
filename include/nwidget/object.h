#ifndef NWIDGET_OBJECT_H
#define NWIDGET_OBJECT_H

#include <QObject>

namespace nwidget {

/* ---------------------------- Property Binding ---------------------------- */

template<typename Action, typename ...Args> class BindingExpr;
template<typename PropertyInfo> class Property;

template<typename T, typename ...TN> struct is_observable;
template<typename A, typename B> struct is_same_property;



class Binding : public QObject
{
    Q_OBJECT

    template<typename Action, typename ...Args> friend class BindingExpr;

    Binding(QObject* parent = nullptr) : QObject(parent) {}

signals:
    void update();
};



struct NoAction { template<typename T> auto operator()(const T& value) { return value; } };

template<typename T> struct ActionConstructor { template<typename ...Args> T operator()(const Args&... args){ return T(args...); } };

template<typename To> struct ActionCast            { template<typename From> auto operator()(const From& from){ return (To)from;                   } };
template<typename To> struct ActionStaticCast      { template<typename From> auto operator()(const From& from){ return static_cast<To>(from);      } };
template<typename To> struct ActionReinterpretCast { template<typename From> auto operator()(const From& from){ return reinterpret_cast<To>(from); } };

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



template<typename T, typename ...TN> struct is_observable
{ static constexpr bool value = is_observable<T>::value || is_observable<TN...>::value; };

template<typename T> struct is_observable<T>
{ static constexpr bool value = false; };


template<typename Action, typename ...Args>
auto makeBindingExpr(const Args&... args) { return BindingExpr<Action, Args...>(args...); }

template<typename Action, typename ...Args>
class BindingExpr
{
    template<typename T, typename ...TN> friend class BindingExpr;

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
    void bindTo(Property<Info> prop) const
    {
        typename Info::Object* object = prop.object;

        Binding* bind = object->template findChild<Binding*>(Info::bindingName(), Qt::FindDirectChildrenOnly);
        if (bind)
            bind->deleteLater();

        if constexpr (!is_observable<Args...>::value)
            bind = nullptr;
        else {
            bind = new Binding(object);
            bind->setObjectName(Info::bindingName());
            bindTo(prop, bind);
            QObject::connect(bind, &Binding::update, bind, [object, expr = *this]() {
                Info::Setter::set(object, expr());
            });
        }

        Info::Setter::set(object, (*this)());
    }

private:
    std::tuple<Args...> args;

    template<typename    T> static auto calc(const T& value)                { return std::make_tuple(value);      }
    template<typename    T> static auto calc(Property<T> prop)              { return std::make_tuple(prop.get()); }
    template<typename ...T> static auto calc(const BindingExpr<T...>& expr) { return std::make_tuple(expr());     }

    template<typename Arg0, typename ...ArgN>
    static auto calc(const Arg0& arg0, const ArgN&... argn)
    { return std::tuple_cat(calc(arg0), calc(argn...)); }


    template<typename Info, typename    T> static void bindTo(Property<Info>, Binding*, const T&) {}
    template<typename Info, typename ...T> static void bindTo(Property<Info> prop, Binding* bind, const BindingExpr<T...>& expr) { return expr.bindTo(prop, bind); }
    template<typename InfoA, typename InfoB>
    static void bindTo(Property<InfoA> to, Binding* bind, Property<InfoB> from)
    {
        if constexpr (is_observable<Property<InfoB>>::value) {
            if constexpr (!is_same_property<InfoA, InfoB>::value) {
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

template<typename A, typename ...TN> struct is_observable<BindingExpr<A, TN...>>
{ static constexpr bool value = is_observable<TN...>::value; };



struct NoGetter {};
struct NoSetter {};
struct NoNotify {};

template<typename PropertyInfo>
class Property
{
// PropertyInfo should have the following members:
//   struct Info
//   {
//       using Object = ...
//       using Type   = ...
//       using Getter = NoGetter or struct { static auto get(const Object* object)                    { ... } }
//       using Setter = NoSetter or struct { static void set(      Object* object, const Type& value) { ... } }
//       using Notify = NoNotify or struct { static auto signal() { return &Object::propertyChanged;  }       }
//
//       static constexpr const char* name() { return "propertyName";  }
//       static QString bindingName() { return "nwidget_binding_on_propertyName"; }
//   };

    template<typename T0, typename ...TN> friend class BindingExpr;
    template<typename T> friend class Property;

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
        Binding* bind = object->template findChild<Binding*>(Info::bindingName(), Qt::FindDirectChildrenOnly);
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

    void operator=(Property<Info> prop) { prop.bindTo(*this); }

    template<typename T>
    void operator=(Property<T> prop) { prop.bindTo(*this); }

    template<typename T>
    void bindTo(Property<T> prop) const
    {
        if (is_same_property<T, Info>::value && prop.object == object)
            Q_ASSERT_X(false, "Property<T>.bindTo", "can't binding a property to itself.");
        else
            makeBindingExpr<NoAction>(*this).bindTo(prop);
    }

    template<typename Action, typename ...Args>
    void operator=(const BindingExpr<Action, Args...>& expr) { expr.bindTo(*this); }

    template<typename Func, typename ...Args>
    auto invoke(Func func, const Args&... args) const
    {
        static_assert(std::is_member_function_pointer<Func>::value, "The arg func must be a member function.");
        return makeBindingExpr<ActionInvoke>(std::mem_fn(func), *this, args...);
    }

private:
    Object* object;
};


template<typename InfoA, typename InfoB>
struct is_same_property
{
private:
    static constexpr bool is_same_name(const char* a, const char* b)
    { return *a == *b && (*a == '\0' || is_same_name(a + 1, b + 1)); }

public:
    static constexpr bool value =
            std::is_same<typename InfoA::Object, typename InfoB::Object>::value
         && is_same_name(InfoA::name(), InfoB::name());
};

template<typename InfoA, typename InfoB>
struct is_same_property<Property<InfoA>, Property<InfoB>>
{
public:
    static constexpr bool value = is_same_property<InfoA, InfoB>::value;
};


template<typename T> struct is_observable<Property<T>>
{ static constexpr bool value = !std::is_same<typename T::Notify, NoNotify>::value; };



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
#define N_NOTIFY(SIG)  struct Notify { static auto signal() { return &Object::SIG; } };

#define N_NO_SETTER using Setter = nwidget::NoSetter;
#define N_NO_GETTER using Getter = nwidget::NoGetter;
#define N_NO_NOTIFY using Notify = nwidget::NoNotify;

#define N_ID_PROPERTY(TYPE, NAME, GETTER, SETTER, NOTIFY)           \
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
        static constexpr const char* name() { return #NAME;  }      \
                                                                    \
        static QString bindingName()                                \
        { return QStringLiteral("nwidget_binding_on_"#NAME); }      \
    };                                                              \
                                                                    \
    Q_ASSERT(nwidget::ObjectIdT<Object>::t);                        \
    return nwidget::Property<Info>(nwidget::ObjectIdT<Object>::t);  \
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

    N_ID_PROPERTY(QString, objectName, N_GETTER(objectName), N_SETTER(setObjectName), N_NOTIFY(objectNameChanged))

protected:
    T* t;
};

using ObjectId = ObjectIdT<QObject>;



/* ----------------------------- Object Builder ----------------------------- */

#define N_BUILDER                               \
protected:                                      \
    using nwidget::ObjectBuilder<S, T>::t;      \
    using nwidget::ObjectBuilder<S, T>::self;   \
    using nwidget::ObjectBuilder<S, T>::addItems;


#if QT_VERSION <= QT_VERSION_CHECK(6, 6, 0)
#define N_RECEIVER_T(F) const typename QtPrivate::FunctionPointer<F>::Object*
#else
#define N_RECEIVER_T(F) const typename QtPrivate::ContextTypeForFunctor<F>::ContextType*
#endif


#define N_BUILDER_SIGNAL(NAME, SIG)                             \
template <typename Func>                                        \
S& NAME(Func&& slot,                                            \
        Qt::ConnectionType type = Qt::AutoConnection)           \
{ QObject::connect(t, &std::decay<decltype(*t)>::type::SIG, t, slot); return self(); }          \
                                                                \
template <typename Func>                                        \
S& NAME(const QObject* receiver, Func method,                   \
        Qt::ConnectionType type = Qt::AutoConnection)           \
{ QObject::connect(t, &std::decay<decltype(*t)>::type::SIG, receiver, method); return self(); } \
                                                                \
template <typename Func>                                        \
S& NAME(N_RECEIVER_T(Func) context, Func&& slot,                \
        Qt::ConnectionType type = Qt::AutoConnection)           \
{ QObject::connect(t, &std::decay<decltype(*t)>::type::SIG, context, slot); return self(); }


#define N_BUILDER_PROPERTY(TYPE, NAME, SETTER)                      \
S& NAME(const TYPE& arg) { t->SETTER(arg); return self(); }         \
                                                                    \
template<typename Info>                                             \
S& NAME(nwidget::Property<Info> prop)                               \
{ return NAME(nwidget::makeBindingExpr<nwidget::NoAction>(prop)); } \
                                                                    \
template<typename ...TN>                                            \
S& NAME(const nwidget::BindingExpr<TN...>& expr)                    \
{                                                                   \
    using Object = typename std::decay<decltype(*t)>::type;         \
    using Type = TYPE;                                              \
                                                                    \
    N_SETTER(SETTER)                                                \
                                                                    \
    struct Info                                                     \
    {                                                               \
        using Object = Object;                                      \
        using Type   = Type;                                        \
        using Getter = NoGetter;                                    \
        using Setter = Setter;                                      \
        using Notify = NoNotify;                                    \
                                                                    \
        static constexpr const char* name() { return #NAME;  }      \
                                                                    \
        static QString bindingName()                                \
        { return QStringLiteral("nwidget_binding_on_"#NAME); }      \
    };                                                              \
                                                                    \
    expr.bindTo(nwidget::Property<Info>(t));                        \
                                                                    \
    return self();                                                  \
}


template<typename S, typename T>
class ObjectBuilder
{
public:
    explicit ObjectBuilder(T* target) : t(target) { Q_ASSERT(target); }

    operator T*() const { return t; }

    S& connect(const char* signal, const QObject* receiver, const char* member,
               Qt::ConnectionType = Qt::AutoConnection)
    { QObject::connect(t, signal, receiver, member); return self(); }

    S& connect(const QMetaMethod& signal, const QObject* receiver, const QMetaMethod& method,
               Qt::ConnectionType type = Qt::AutoConnection)
    { QObject::connect(t, signal, receiver, method); return self(); }

    template <typename Func1, typename Func2>
    S& connect(Func1 signal, N_RECEIVER_T(Func2) receiver, Func2&& slot,
               Qt::ConnectionType type = Qt::AutoConnection)
    { QObject::connect(t, signal, receiver, slot); return self(); }

    S& objectName(const QString& name)                       { t->setObjectName(name);     return self(); }
    S& objectName(QAnyStringView name)                       { t->setObjectName(name);     return self(); }

    S& property(const char* name, const QVariant& value)     { t->setProperty(name, value); return self(); }
    S& property(const char* name, QVariant&& value)          { t->setProperty(name, value); return self(); }

    N_BUILDER_SIGNAL(onDestroyed        , destroyed        )
    N_BUILDER_SIGNAL(onObjectNameChanged, objectNameChanged)

protected:
    T* t;

    S& self() { return static_cast<S&>(*this); }

    template<typename E>
    void addItems(std::initializer_list<E> items)
    {
        auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(t);
    }
};


#define N_DECL_BUILDER(BUILDER, TARGET, NAME)   \
class NAME : public BUILDER<NAME, TARGET>       \
{                                               \
public:                                         \
    using BUILDER::BUILDER;                     \
}

N_DECL_BUILDER(ObjectBuilder, QObject, Object);



template<typename Item>
using ItemGenerator = std::function<std::optional<Item>()>;

template<typename T>
class BuilderItem
{
public:
    template<typename F> explicit BuilderItem(F f) : addTo(f) {}

    template<typename I> BuilderItem(ItemGenerator<I> g)
    {
        addTo = [g](T* t) {
            auto item = g();
            while (item) {
                item->addTo(t);
                item = g();
            }
        };
    }

    std::function<void(T*)> addTo;
};

template<typename Iterator,
         typename Generator,
         typename Arg = typename std::decay<decltype(*std::declval<Iterator>())>::type,
         typename Item = typename std::invoke_result<Generator, int, Arg>::type>
ItemGenerator<Item> ForEach(Iterator begin, Iterator end, Generator generator)
{
    return [index = (int)0, begin, end, generator]() mutable -> std::optional<Item> {
        if (begin == end)
            return std::nullopt;
        auto item = generator(index, *begin);
        ++index;
        ++begin;
        return item;
    };
}

template<typename Container, typename Generator>
auto ForEach(const Container& c, Generator g) { return ForEach(c.begin(), c.end(), g); }

template<typename E, typename Generator>
auto ForEach(std::initializer_list<E> l, Generator g) { return ForEach(l.begin(), l.end(), g); }

}

#endif // NWIDGET_OBJECT_H
