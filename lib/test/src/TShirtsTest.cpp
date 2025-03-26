// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <TShirts.h>

#include <gtest/gtest.h>

TEST(TShirt, SizeShouldReturnCorrectLabel)
{
    EXPECT_EQ(TShirt::size(37), 'S');
    EXPECT_EQ(TShirt::size(38), 'M');
    EXPECT_EQ(TShirt::size(40), 'M');
    EXPECT_EQ(TShirt::size(42), 'L');
    EXPECT_EQ(TShirt::size(43), 'L');
}
