//
// Created by ludwig_van_schlett on 20/11/24.
//

#include "../headers/TimeSeriesGenerator.h"

#include <iostream>

TimeSeriesGenerator::TimeSeriesGenerator():
    TimeSeriesGenerator(0)
{

}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
    seed(_seed)
{

}

void TimeSeriesGenerator::setSeed(int _seed) {
    seed = _seed;
}

int TimeSeriesGenerator::getSeed() const {
    return seed;
}

void TimeSeriesGenerator::printTimeSeries(std::vector<double> timeSerie) {

    for (double value : timeSerie) {

        std::cout << value << " ";

    }

}




