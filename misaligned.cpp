#include <gtest/gtest.h>

#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <utility>

int number(const int i, const int j)
{
    return i * 5 + j;
}

std::string printColorMap()
{
    const char*       majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char*       minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int               i = 0, j = 0;
    std::stringstream result;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            result << number(i, j) << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return result.str();
}

void testNumber()
{
    for (auto i = 0; i < 5; ++i)
    {
        for (auto j = 0; j < 5; ++j)
        {
            const auto expectedNumber = i * 5 + j + 1;
            EXPECT_EQ(number(i, j), expectedNumber);
        }
    }
}

void testPrintColorMap()
{
    std::cout << "\nPrint color map test\n";

    const auto colorMap = printColorMap();
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
