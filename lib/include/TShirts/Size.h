// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#pragma once

#include "SizeLimits.h"

#include <cstdint>

namespace TShirt {

enum class Label
{
    Small,
    Medium,
    Large
};

class Size
{
  public:
    explicit Size(std::uint8_t euSize, SizeLimits = {});
    explicit Size(Label label, SizeLimits = {});

    [[nodiscard]] std::uint8_t eu() const;
    [[nodiscard]] Label        label() const;

  private:
    std::uint8_t euSize_;
    SizeLimits   limits_;
};

} // namespace TShirt
