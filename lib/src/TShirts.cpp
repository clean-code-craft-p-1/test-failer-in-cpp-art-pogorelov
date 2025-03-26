// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <TShirts.h>

namespace TShirt {

[[nodiscard]] char size(const int cms)
{
    char sizeName = '\0';
    if (cms < 38)
    {
        sizeName = 'S';
    }
    else if (cms > 38 && cms < 42)
    {
        sizeName = 'M';
    }
    else if (cms > 42)
    {
        sizeName = 'L';
    }
    return sizeName;
}
} // namespace TShirt
