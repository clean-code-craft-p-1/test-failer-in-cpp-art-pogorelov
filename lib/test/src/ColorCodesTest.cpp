// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <ColorCodes.h>

#include <gtest/gtest.h>

#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <utility>

TEST(Number, NumberShouldReturnCorrectValue)
{
    for (auto i = 0; i < 5; ++i)
    {
        for (auto j = 0; j < 5; ++j)
        {
            const auto expectedNumber = i * 5 + j + 1;
            EXPECT_EQ(ColorCodes::number(i, j), expectedNumber);
        }
    }
}

TEST(ColorMap, printColorMapShouldBeAligned)
{
    const auto colorMap = ColorCodes::printColorMap();
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
