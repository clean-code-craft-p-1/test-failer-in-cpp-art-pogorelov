// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <ColorMap/Print.h>

#include <ColorCodes/Mapping.h>
#include <ColorCodes/Types.h>

#include <format>
#include <numeric>
#include <ranges>
#include <string>

namespace ColorMap {

[[nodiscard]] std::string printColorMap()
{
    using namespace ColorCodes;
    constexpr auto kSize    = std::size(kMajorColorNames) * std::size(kMinorColorNames);
    constexpr auto kIndices = std::views::iota(1ULL, kSize);

    return std::accumulate(
        kIndices.begin(), kIndices.end(), std::string{}, [](auto&& colorMap, const auto& number) {
            const auto     pair      = colorPair(number);
            const auto     minor     = static_cast<std::size_t>(pair->minor);
            const auto     major     = static_cast<std::size_t>(pair->major);
            const auto&    majorName = kMajorColorNames.at(major);
            const auto&    minorName = kMinorColorNames.at(minor);
            constexpr auto kLine     = "{}{:2} | {:6} | {:6}\n";
            return std::format(kLine, colorMap, number, majorName, minorName);
        });
}

} // namespace ColorMap
