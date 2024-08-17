#ifndef UNITS_H
#define UNITS_H

#include <functional>
#include <stdint.h>

namespace units {

class length_unit
{
public:
    constexpr length_unit(double ratio_to_meter) : ratio_(ratio_to_meter) {}

    constexpr double ratio_to_meter() const { return ratio_; }

private:
    double ratio_;
};

constexpr bool operator==(length_unit l, length_unit r) { return l.ratio_to_meter() == r.ratio_to_meter(); }
constexpr bool operator!=(length_unit l, length_unit r) { return !(l == r); }

constexpr length_unit mm {0.001   };
constexpr length_unit cm {0.01    };
constexpr length_unit m  {1.0     };
constexpr length_unit km {1000    };
constexpr length_unit in {0.0254  };
constexpr length_unit ft {0.3048  };
constexpr length_unit yd {0.9144  };
constexpr length_unit mi {1609.344};
constexpr length_unit nmi{1852    };

class length
{
public:
    constexpr length(double value, length_unit unit) : val_(value), unit_(unit) {}

    constexpr double value() const { return val_; }

    constexpr length_unit unit() const { return unit_; }

    constexpr length convert_to(length_unit unit) const { return {val_ * unit_.ratio_to_meter() / unit.ratio_to_meter() , unit}; }

private:
    double val_;
    length_unit unit_;
};

constexpr length operator+(length l, length r) { return {l.convert_to(r.unit()).value() + r.value(), r.unit()}; };
constexpr length operator-(length l, length r) { return {l.convert_to(r.unit()).value() - r.value(), r.unit()}; };
constexpr double operator/(length l, length r) { return l.convert_to(r.unit()).value() / r.value(); };

constexpr int8_t cmp(length l, length r)
{
    if (l.unit() == r.unit() && l.value() == r.value())
        return 0;
    return (l.convert_to(r.unit()).value() > r.value()) ? 1 : -1;
}

constexpr bool operator==(length l, length r) { return cmp(l, r) == 0; }
constexpr bool operator!=(length l, length r) { return cmp(l, r) != 0; }
constexpr bool operator> (length l, length r) { return cmp(l, r) >  0; }
constexpr bool operator>=(length l, length r) { return cmp(l, r) >= 0; }
constexpr bool operator< (length l, length r) { return cmp(l, r) <  0; }
constexpr bool operator<=(length l, length r) { return cmp(l, r) <= 0; }

}



template<>
struct std::hash<units::length_unit>
{
    std::size_t operator()(units::length_unit unit) { return std::hash<double>()(unit.ratio_to_meter()); }
};


#endif // UNITS_H
