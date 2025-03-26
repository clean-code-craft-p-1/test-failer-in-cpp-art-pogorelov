#pragma once

#include <string>

namespace WeatherSpace {

constexpr auto kSunnyDay  = "Sunny Day";
constexpr auto kRainyDay  = "Rainy Day";
constexpr auto kStormyDay = "Alert, Stormy with heavy rain";

class IWeatherSensor
{
  public:
    virtual ~IWeatherSensor()             = default;
    virtual double TemperatureInC() const = 0;
    virtual int    Precipitation() const  = 0;
    virtual int    Humidity() const       = 0;
    virtual int    WindSpeedKMPH() const  = 0;
};

[[nodiscard]] std::string Report(const IWeatherSensor& sensor);

} // namespace WeatherSpace
