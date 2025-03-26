cmake_minimum_required(VERSION 3.14)
project(StrongTests.Lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}
        include/ColorCodes.h
        include/TShirts.h
        include/WeatherReport.h
        src/ColorCodes.cpp
        src/TShirts.cpp
        src/WeatherReport.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

enable_testing()
add_subdirectory(test)
