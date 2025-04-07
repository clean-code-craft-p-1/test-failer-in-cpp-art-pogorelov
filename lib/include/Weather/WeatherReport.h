#pragma once

#include "IWeatherSensor.h"

#include <string>

namespace Weather {

enum class WeatherReport : std::uint8_t
{
    Sunny,
    Rainy,
    Stormy
};

[[nodiscard]] WeatherReport report(const IWeatherSensor& sensor);
[[nodiscard]] std::string   toString(WeatherReport report);

} // namespace Weather
