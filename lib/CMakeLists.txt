cmake_minimum_required(VERSION 3.14)
project(StrongTests.Lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        ColorCodes
        URL https://github.com/clean-code-craft-p-1/well-named-in-cpp-art-pogorelov/archive/refs/tags/v1.0.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(ColorCodes)

add_library(${PROJECT_NAME}
        include/ColorMap/Print.h
        include/Weather/WeatherReport.h
        include/TShirts/Print.h
        include/TShirts/Size.h
        include/TShirts/SizeLimits.h
        src/ColorMap/Print.cpp
        src/Weather/WeatherReport.cpp
        src/TShirts/Print.cpp
        src/TShirts/Size.cpp
        src/TShirts/SizeLimits.cpp
        include/Weather/IWeatherSensor.h)

target_link_libraries(
        ${PROJECT_NAME}
        ColorCodes.Lib
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

enable_testing()
add_subdirectory(test)
