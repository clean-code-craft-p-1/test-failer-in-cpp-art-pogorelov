// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices
#include <ColorCodes.h>

#include <sstream>
#include <string>

namespace ColorCodes {
[[nodiscard]] int number(const int i, const int j)
{
    return i * 5 + j;
}

[[nodiscard]] std::string printColorMap()
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
} // namespace ColorCodes
