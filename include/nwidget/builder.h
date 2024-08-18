#ifndef BUILDER_H
#define BUILDER_H

#include <functional>
#include <optional>

#define N_USING_BUILDER_MEMBER(BASE, SELF, TARGET)  \
protected:                                          \
    using BASE<SELF, TARGET>::t;                    \
    using BASE<SELF, TARGET>::self;                 \
    using BASE<SELF, TARGET>::addItems;

#define N_BUILDER_IMPL(BUILDER, TARGET, NAME)       \
class NAME : public BUILDER<NAME, TARGET>           \
{                                                   \
public:                                             \
    using BUILDER::BUILDER;                         \
}

namespace nw {

template<typename Item>
using ItemGenerator = std::function<std::optional<Item>()>;

template<typename T>
class BuilderItem
{
public:
    template<typename F> explicit BuilderItem(F f) : addTo(f) {}

    template<typename I> BuilderItem(ItemGenerator<I> g)
    {
        addTo = [g](T* l){
            auto item = g();
            while (item) {
                item->addTo(l);
                item = g();
            }
        };
    }

    std::function<void(T*)> addTo;
};

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

    template<typename E>
    void addItems(std::initializer_list<E> items)
    {
        auto end = items.end();
        for (auto i = items.begin(); i != end; ++i)
            i->addTo(t);
    }
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

#endif // BUILDER_H
