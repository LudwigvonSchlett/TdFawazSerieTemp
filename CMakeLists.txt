cmake_minimum_required(VERSION 3.29)
project(TdFawazSerieTemp)

set(CMAKE_CXX_STANDARD 20)

add_executable(TdFawazSerieTemp main.cpp
        src/TimeSeriesGenerator.cpp
        headers/TimeSeriesGenerator.h
        src/GaussianGenerator.cpp
        headers/GaussianGenerator.h
        src/StepGenerator.cpp
        headers/StepGenerator.h
        src/SinWaveGenerator.cpp
        headers/SinWaveGenerator.h
        src/TimesSeriesDataset.cpp
        headers/TimesSeriesDataset.h
        src/KNN.cpp
        headers/KNN.h)
