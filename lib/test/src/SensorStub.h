// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#pragma once

#include <Weather/IWeatherSensor.h>
#include <random>

#include <rapidcheck.h>

namespace Weather::Test {

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

} // namespace Weather::Test

namespace rc {
using Weather::IWeatherSensor;
using Weather::Test::SensorStub;

template <>
struct Arbitrary<std::shared_ptr<IWeatherSensor>>
{
    static Gen<std::shared_ptr<IWeatherSensor>> arbitrary()
    {
        // temperature in range [-50.0, 60.0]
        const auto temperatureRange = []() -> double {
            static std::random_device        rd;
            static std::mt19937              gen(rd());
            std::uniform_real_distribution<> dis(-50.0, 60.0);
            return dis(gen);
        };

        return gen::apply(
            [](std::uint8_t h, std::uint8_t p, double t, std::uint8_t w) {
                return std::static_pointer_cast<IWeatherSensor>(
                    std::make_shared<SensorStub>(h, p, t, w));
            },
            gen::inRange<std::uint8_t>(0, 100),  // humidity
            gen::inRange<std::uint8_t>(0, 100),  // precipitation
            gen::exec(temperatureRange),         // temperature
            gen::inRange<std::uint8_t>(0, 100)); // windSpeed
    }
};
} // namespace rc
