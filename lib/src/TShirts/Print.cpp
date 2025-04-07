// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <TShirts/Print.h>

namespace TShirt {

namespace {
constexpr auto kSmall  = "S";
constexpr auto kMedium = "M";
constexpr auto kLarge  = "L";
} // namespace

std::string toString(const Label label)
{
    if (label == Label::Small)
    {
        return kSmall;
    }
    if (label == Label::Medium)
    {
        return kMedium;
    }
    return kLarge;
}

} // namespace TShirt
