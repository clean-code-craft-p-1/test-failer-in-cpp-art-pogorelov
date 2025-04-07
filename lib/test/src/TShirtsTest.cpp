// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <TShirts/Print.h>

#include <gtest/gtest.h>

#include <cstdint>
#include <string>
#include <utility>

namespace TShirt::Test {
struct TShirtTest : public ::testing::TestWithParam<std::pair<std::uint8_t, std::string>>
{
};

TEST_P(TShirtTest, SizeShouldReturnCorrectLabelString)
{
    const auto& [euSize, label] = GetParam();
    EXPECT_EQ(toString(Size{euSize}.label()), label);
}

INSTANTIATE_TEST_SUITE_P(TShirtTest,
                         TShirtTest,
                         ::testing::Values(std::make_pair(37, "S"),
                                           std::make_pair(38, "M"),
                                           std::make_pair(40, "M"),
                                           std::make_pair(42, "L"),
                                           std::make_pair(43, "L")));
}
