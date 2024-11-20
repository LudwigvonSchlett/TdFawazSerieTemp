cmake_minimum_required(VERSION 3.29)
project(TdFawazSerieTemp)

set(CMAKE_CXX_STANDARD 20)

add_executable(TdFawazSerieTemp main.cpp
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.h)
