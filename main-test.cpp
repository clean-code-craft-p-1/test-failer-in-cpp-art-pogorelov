#include <gtest/gtest.h>

void testTshirtSize();
void testPrintColorMap();
void testNumber();
void testWeatherReport();

TEST(TShirt, Size)
{
    testTshirtSize();
}

TEST(ColorMap, Print)
{
    testNumber();
    testPrintColorMap();
}

TEST(WeatherReport, Report)
{
    testWeatherReport();
}
