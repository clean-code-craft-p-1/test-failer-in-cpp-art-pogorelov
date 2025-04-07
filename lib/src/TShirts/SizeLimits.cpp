// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <TShirts/SizeLimits.h>

#include <stdexcept>

namespace TShirt {

SizeLimits::SizeLimits(const std::uint8_t min,
                       const std::uint8_t max,
                       const std::uint8_t small,
                       const std::uint8_t medium,
                       const std::uint8_t large)
    : min_{min}
    , max_{max}
    , small_{small}
    , medium_{medium}
    , large_(large)
{
    if (min_ >= max_)
    {
        throw std::invalid_argument("min < max required");
    }

    if (small_ >= medium_ || small_ >= large_ || medium_ >= large_)
    {
        throw std::invalid_argument("small < medium < large required");
    }

    if (small_ < min_ || large_ > max_)
    {
        throw std::invalid_argument("min <= small and large <= max required");
    }
}

std::uint8_t SizeLimits::min() const
{
    return min_;
}

std::uint8_t SizeLimits::max() const
{
    return max_;
}

std::uint8_t SizeLimits::small() const
{
    return small_;
}

std::uint8_t SizeLimits::medium() const
{
    return medium_;
}

std::uint8_t SizeLimits::large() const
{
    return large_;
}

} // namespace TShirt
