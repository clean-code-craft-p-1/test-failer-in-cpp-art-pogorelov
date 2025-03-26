#include <gtest/gtest.h>

#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

namespace WeatherSpace {

namespace {
constexpr auto kSunnyDay  = "Sunny Day";
constexpr auto kRainyDay  = "Rainy Day";
constexpr auto kStormyDay = "Alert, Stormy with heavy rain";
} // namespace

class IWeatherSensor
{
  public:
    virtual double TemperatureInC() const = 0;
    virtual int    Precipitation() const  = 0;
    virtual int    Humidity() const       = 0;
    virtual int    WindSpeedKMPH() const  = 0;
};
/// <summary>
/// This is a stub for a weather sensor. For the sake of testing
/// we create a stub that generates weather data and allows us to
/// test the other parts of this application in isolation
/// without needing the actual Sensor during development
/// </summary>
class SensorStub : public IWeatherSensor
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

string Report(const IWeatherSensor& sensor)
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

void TestSunny()
{
    SensorStub sensor(0, 0, 100, 0);
    const auto report = Report(sensor);
    cout << report << endl;
    EXPECT_EQ(report, kSunnyDay);
}

void TestRainy()
{
    SensorStub sensor(100, 100, 0, 0);
    const auto report = Report(sensor);
    cout << report << endl;
    EXPECT_EQ(report, kRainyDay);
}

void TestHighPrecipitation()
{
    SensorStub sensor(100, 100, 0, 100);
    const auto report = Report(sensor);
    EXPECT_EQ(report, kStormyDay);
}
} // namespace WeatherSpace

void testWeatherReport()
{
    cout << "\nWeather report test\n";
    WeatherSpace::TestSunny();
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}
