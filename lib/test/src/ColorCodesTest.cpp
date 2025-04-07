// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <ColorMap/Print.h>

#include <gtest/gtest.h>

#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <utility>

TEST(ColorMap, printColorMapShouldBeAligned)
{
    const auto colorMap = ColorMap::printColorMap();
    std::cout << colorMap;

    // In each line of the color map there are 3 tokens separated by '|'
    // In the map we store the size of each token
    std::unordered_map<std::size_t, std::size_t> tokenSizes;

    // Compare the length of the tokens for each line
    const auto checkToken = [&](const auto index, auto&& token) {
        if (const auto size = std::size(token); !tokenSizes.try_emplace(index, size).second)
        {
            EXPECT_EQ(tokenSizes[index], size);
        }
    };

    const auto checkLine = [&](const auto& line) {
        std::size_t index = 0;
        std::ranges::for_each(line | std::views::split('|'),
                              [&](auto&& token) { checkToken(index++, token); });
    };

    std::ranges::for_each(colorMap | std::views::split('\n'), checkLine);
}
