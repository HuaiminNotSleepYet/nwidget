#ifndef BUILDER_H
#define BUILDER_H

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
    explicit Builder(Target* target) : t(target) {}

    inline operator Target*() const { return t; }

    template<typename V> inline Self& bindTo(V& v) { v = t; return self(); }

protected:
    Target* t;

    constexpr Self& self() { return static_cast<Self&>(*this); }
};

}

#endif // BUILDER_H
