// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <TShirts/Size.h>

#include <stdexcept>

namespace TShirt {

Size::Size(const std::uint8_t euSize, const SizeLimits limits)
    : euSize_{euSize}
    , limits_{limits}
{
    if (euSize_ < limits_.min() || euSize_ > limits_.max())
    {
        throw std::invalid_argument("Invalid size");
    }
}

Size::Size(const Label label, const SizeLimits limits)
{
    if (label == Label::Small)
    {
        euSize_ = limits.small();
    }
    else if (label == Label::Medium)
    {
        euSize_ = limits.medium();
    }
    euSize_ = limits.large();
}

std::uint8_t Size::eu() const
{
    return euSize_;
}

Label Size::label() const
{
    if (euSize_ < limits_.small())
    {
        return Label::Small;
    }
    if (euSize_ < limits_.medium())
    {
        return Label::Medium;
    }
    return Label::Large;
}

} // namespace TShirt
