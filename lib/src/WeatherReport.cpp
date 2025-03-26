// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <WeatherReport.h>

#include <string>

namespace WeatherSpace {

std::string Report(const IWeatherSensor& sensor)
{
    int precipitation = sensor.Precipitation();
    // precipitation < 20 is a sunny day

    if (sensor.TemperatureInC() > 25)
    {
        if (precipitation >= 20 && precipitation < 60) return kRainyDay;
        if (sensor.WindSpeedKMPH() > 50) return kStormyDay;
    }
    return kSunnyDay;
}
} // namespace WeatherSpace
