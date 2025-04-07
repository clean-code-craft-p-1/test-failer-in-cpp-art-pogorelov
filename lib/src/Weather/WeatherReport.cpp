// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <Weather/IWeatherSensor.h>
#include <Weather/WeatherReport.h>

#include <string>

namespace Weather {

namespace {
constexpr auto kSunnyDay  = "Sunny Day";
constexpr auto kRainyDay  = "Rainy Day";
constexpr auto kStormyDay = "Alert, Stormy with heavy rain";
} // namespace

WeatherReport report(const IWeatherSensor& sensor)
{
    const auto precipitation = sensor.precipitation();

    if (precipitation < 20) return WeatherReport::Sunny;
    if (sensor.windSpeedKMPH() > 50) return WeatherReport::Stormy;
    return WeatherReport::Rainy;
}

std::string toString(const WeatherReport report)
{
    if (report == WeatherReport::Sunny)
    {
        return kSunnyDay;
    }
    if (report == WeatherReport::Rainy)
    {
        return kRainyDay;
    }
    return kStormyDay;
}

} // namespace Weather
