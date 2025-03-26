#include <gtest/gtest.h>

#include <iostream>

char size(int cms)
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

void testTshirtSize()
{
    std::cout << "\nTshirt size test\n";
    EXPECT_EQ(size(37), 'S');
    EXPECT_EQ(size(38), 'M');
    EXPECT_EQ(size(40), 'M');
    EXPECT_EQ(size(42), 'L');
    EXPECT_EQ(size(43), 'L');
    std::cout << "All is well (maybe!)\n";
}
