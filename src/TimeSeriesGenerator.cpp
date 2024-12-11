//
// Created by ludwig_van_schlett on 20/11/24.
//

#include "../headers/TimeSeriesGenerator.h"


TimeSeriesGenerator::TimeSeriesGenerator():
    TimeSeriesGenerator(0)
{

}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
    seed(_seed), rng(_seed)
{

}

void TimeSeriesGenerator::setSeed(int _seed) {
    rng.seed(_seed);
    seed = _seed;
}

int TimeSeriesGenerator::getSeed() const {
    return seed;
}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& timeSeries) {

    for (double value : timeSeries) {

        std::cout << value << " ";

    }

}




