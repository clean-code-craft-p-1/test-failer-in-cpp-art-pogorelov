// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <WeatherReport.h>

#include <gtest/gtest.h>

#include <iostream>

namespace {
// it could be gmock object
class SensorStub : public WeatherSpace::IWeatherSensor
{
  public:
    int Humidity() const override
    {
        return humidity_;
    }

    int Precipitation() const override
    {
        return precipitation_;
    }

    double TemperatureInC() const override
    {
        return temperature_;
    }

    int WindSpeedKMPH() const override
    {
        return windSpeed_;
    }

    SensorStub(int humidity, int precipitation, double temperature, int windSpeed)
        : humidity_{humidity}
        , precipitation_{precipitation}
        , temperature_{temperature}
        , windSpeed_{windSpeed}
    {
    }

  private:
    int    humidity_;
    int    precipitation_;
    double temperature_;
    int    windSpeed_;
};
} // namespace

TEST(TestSunny, ReportShouldReturnSunnyDay)
{
    SensorStub sensor(0, 50, 100, 0);
    const auto report = Report(sensor);
    std::cout << report << std::endl;
    EXPECT_EQ(report, WeatherSpace::kSunnyDay);
}

TEST(RainyDay, ReportShouldReturnRainyDay)
{
    SensorStub sensor(100, 100, 0, 0);
    const auto report = Report(sensor);
    std::cout << report << std::endl;
    EXPECT_EQ(report, WeatherSpace::kRainyDay);
}

TEST(StormyDay, ReportShouldReturnStormyDay)
{
    SensorStub sensor(100, 100, 0, 100);
    const auto report = Report(sensor);
    std::cout << report << std::endl;
    EXPECT_EQ(report, WeatherSpace::kStormyDay);
}
