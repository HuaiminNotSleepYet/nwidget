#ifndef BUILDER_H
#define BUILDER_H

#include <functional>
#include <optional>

#define N_USING_BUILDER_MEMBER(BASE, SELF, TARGET)  \
protected:                                          \
    using BASE<SELF, TARGET>::t;                    \
    using BASE<SELF, TARGET>::self;

#define N_BUILDER_IMPL(BUILDER, TARGET, NAME)       \
class NAME : public BUILDER<NAME, TARGET>           \
{                                                   \
public:                                             \
    using BUILDER::BUILDER;                         \
}

namespace nw {

template<typename Self, typename Target>
class Builder
{
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

public:
    explicit Builder(Target* target) : t(target) { Q_ASSERT(target); }

    operator Target*() const { return t; }

protected:
    Target* t;

    constexpr Self& self() { return static_cast<Self&>(*this); }
};

template<typename Item>
using ItemGenerator = std::function<std::optional<Item>()>;

template<typename Iterator,
         typename Generator,
         typename Arg = typename std::decay<decltype(*std::declval<Iterator>())>::type,
         typename Item = typename std::invoke_result<Generator, Arg>::type>
ItemGenerator<Item> ForEach(Iterator begin, Iterator end, Generator generator)
{
    return [begin, end, generator]() mutable -> std::optional<Item> {
        if (begin == end)
            return std::nullopt;
        auto item = generator(*begin);
        ++begin;
        return item;
    };
}

template<typename Container, typename Generator>
auto ForEach(const Container& c, Generator g) { return ForEach(c.begin(), c.end(), g); }

template<typename E, typename Generator>
auto ForEach(std::initializer_list<E> l, Generator g) { return ForEach(l.begin(), l.end(), g); }

}

#endif // BUILDER_H
