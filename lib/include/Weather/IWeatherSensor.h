// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#pragma once

#include <cstdint>

namespace Weather {

class IWeatherSensor
{
  public:
    [[nodiscard]] virtual double       temperatureInC() const = 0;
    [[nodiscard]] virtual std::uint8_t precipitation() const  = 0;
    [[nodiscard]] virtual std::uint8_t humidity() const       = 0;
    [[nodiscard]] virtual std::uint8_t windSpeedKMPH() const  = 0;

    virtual ~IWeatherSensor()                        = default;
    IWeatherSensor(const IWeatherSensor&)            = delete;
    IWeatherSensor(IWeatherSensor&&)                 = delete;
    IWeatherSensor& operator=(const IWeatherSensor&) = delete;
    IWeatherSensor& operator=(IWeatherSensor&&)      = delete;

  protected:
    IWeatherSensor() = default;
};

} // namespace Weather
