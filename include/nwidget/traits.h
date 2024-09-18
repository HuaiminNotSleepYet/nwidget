#ifndef NWIDGET_TRAITS_H
#define NWIDGET_TRAITS_H

#include <tuple>

namespace nwidget::traits {

template<typename T>
struct mem_fn;

template<typename C, typename R, typename ...T>
struct mem_fn<R(C::*)(T...)>
{
    using result = R;
    using object = C;

    constexpr static std::size_t argc = sizeof...(T);

    template<std::size_t i>
    using arg = std::tuple_element_t<i, std::tuple<T...>>;
};

template<typename C, typename R, typename ...T>
struct mem_fn<R(C::*)(T...) const>
{
    using result = R;
    using object = C;

    constexpr static std::size_t argc = sizeof...(T);

    template<std::size_t i>
    using arg = std::tuple_element_t<i, std::tuple<T...>>;
};

template<typename C, typename R>                                                     constexpr static auto overload0(R(C::* p)())               { return p; }
template<typename C, typename R, typename A0>                                        constexpr static auto overload1(R(C::* p)(A0))             { return p; }
template<typename C, typename R, typename A0, typename A1>                           constexpr static auto overload2(R(C::* p)(A0, A1))         { return p; }
template<typename C, typename R, typename A0, typename A1, typename A2>              constexpr static auto overload3(R(C::* p)(A0, A1, A2))     { return p; }
template<typename C, typename R, typename A0, typename A1, typename A2, typename A3> constexpr static auto overload4(R(C::* p)(A0, A1, A2, A3)) { return p; }

}

#endif // NWIDGET_TRAITS_H
