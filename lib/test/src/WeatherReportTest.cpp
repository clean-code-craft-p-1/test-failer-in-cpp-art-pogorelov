// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <Weather/WeatherReport.h>

#include <gtest/gtest.h>
#include <rapidcheck.h>

#include <iostream>

namespace Weather::Test {

namespace {
// it could be gmock object
class SensorStub : public IWeatherSensor
{
  public:
    SensorStub(const std::uint8_t humidity,
               const std::uint8_t precipitation,
               const double       temperature,
               const std::uint8_t windSpeed)
        : humidity_{humidity}
        , precipitation_{precipitation}
        , temperature_{temperature}
        , windSpeed_{windSpeed}
    {
    }

    std::uint8_t humidity() const override
    {
        return humidity_;
    }

    std::uint8_t precipitation() const override
    {
        return precipitation_;
    }

    double temperatureInC() const override
    {
        return temperature_;
    }

    std::uint8_t windSpeedKMPH() const override
    {
        return windSpeed_;
    }

  private:
    std::uint8_t humidity_;
    std::uint8_t precipitation_;
    double       temperature_;
    std::uint8_t windSpeed_;
};
} // namespace

TEST(SunnyDay, GivenLowPrecipitationReportReportShouldReturnSunnyDay)
{
    rc::check("Low precipitation is sunny",
              [](const std::uint8_t humidity,
                 const std::uint8_t precipitation,
                 const double       temperature,
                 const std::uint8_t windSpeed) {
                  const auto sensor = SensorStub(humidity, precipitation, temperature, windSpeed);
                  const auto result = report(sensor);
                  if (precipitation < 20)
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
              [](const std::uint8_t humidity,
                 const std::uint8_t precipitation,
                 const double       temperature,
                 const std::uint8_t windSpeed) {
                  const auto sensor = SensorStub(humidity, precipitation, temperature, windSpeed);
                  const auto result = report(sensor);
                  if (precipitation >= 20 && windSpeed > 50)
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
              [](const std::uint8_t humidity,
                 const std::uint8_t precipitation,
                 const double       temperature,
                 const std::uint8_t windSpeed) {
                  const auto sensor = SensorStub(humidity, precipitation, temperature, windSpeed);
                  const auto result = report(sensor);
                  if (precipitation >= 20 && windSpeed <= 50)
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
