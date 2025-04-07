// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#pragma once

#include <cstdint>

namespace TShirt {

class SizeLimits
{
  public:
    SizeLimits() = default;

    explicit SizeLimits(std::uint8_t min,
                        std::uint8_t max,
                        std::uint8_t small,
                        std::uint8_t medium,
                        std::uint8_t large);

    [[nodiscard]] std::uint8_t min() const;
    [[nodiscard]] std::uint8_t max() const;
    [[nodiscard]] std::uint8_t small() const;
    [[nodiscard]] std::uint8_t medium() const;
    [[nodiscard]] std::uint8_t large() const;

  private:
    std::uint8_t min_{20};
    std::uint8_t max_{60};
    std::uint8_t small_{38};
    std::uint8_t medium_{42};
    std::uint8_t large_{45};
};

} // namespace TShirt
