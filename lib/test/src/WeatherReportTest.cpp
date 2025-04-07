// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include "SensorStub.h"
#include <Weather/WeatherReport.h>

#include <gtest/gtest.h>
#include <rapidcheck.h>

#include <iostream>

namespace Weather::Test {

TEST(SunnyDay, GivenLowPrecipitationReportReportShouldReturnSunnyDay)
{
    rc::check("Low precipitation is sunny", [](const std::shared_ptr<IWeatherSensor>& sensor) {
        const auto result = report(*sensor);
        if (sensor->precipitation() < 20)
        {
            RC_ASSERT(result == WeatherReport::Sunny);
        }
        else
        {
            RC_ASSERT_FALSE(result == WeatherReport::Sunny);
        }
    });
}

TEST(StormyDay, GivenHighPrecipitationWithStrongWindReportShouldReturnStormyDay)
{
    rc::check("High precipitation and strong wind is stormy",
              [](const std::shared_ptr<IWeatherSensor>& sensor) {
                  const auto result = report(*sensor);
                  if (sensor->precipitation() >= 20 && sensor->windSpeedKMPH() > 50)
                  {
                      RC_ASSERT(result == WeatherReport::Stormy);
                  }
                  else
                  {
                      RC_ASSERT_FALSE(result == WeatherReport::Stormy);
                  }
              });
}

TEST(RainyDay, GivenHighPrecipitationWithoutStrongWindReportShouldReturnRainyDay)
{
    rc::check("High precipitation without strong wind is rainy",
              [](const std::shared_ptr<IWeatherSensor>& sensor) {
                  const auto result = report(*sensor);
                  if (sensor->precipitation() >= 20 && sensor->windSpeedKMPH() <= 50)
                  {
                      RC_ASSERT(result == WeatherReport::Rainy);
                  }
                  else
                  {
                      RC_ASSERT_FALSE(result == WeatherReport::Rainy);
                  }
              });
}

TEST(SunnyDay, GivenSunnyReportToStringShouldReturnSunny)
{
    constexpr auto kSunny = "Sunny";
    const auto     result = toString(WeatherReport::Sunny);
    EXPECT_TRUE(result.find(kSunny) != std::string::npos);
}

TEST(RainyDay, GivenRainyReportToStringShouldReturnRainy)
{
    constexpr auto kRainy = "Rainy";
    const auto     result = toString(WeatherReport::Rainy);
    EXPECT_TRUE(result.find(kRainy) != std::string::npos);
}

TEST(StormyDay, GivenStormyReportToStringShouldReturnStormy)
{
    constexpr auto kStormy = "Stormy";
    const auto     result  = toString(WeatherReport::Stormy);
    EXPECT_TRUE(result.find(kStormy) != std::string::npos);
}

} // namespace Weather::Test
