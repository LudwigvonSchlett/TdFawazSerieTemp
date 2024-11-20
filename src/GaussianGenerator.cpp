//
// Created by ludwig_van_schlett on 20/11/24.
//

#include "../headers/GaussianGenerator.h"

GaussianGenerator::GaussianGenerator():
    GaussianGenerator(0.0, 1.0)
{

}

GaussianGenerator::GaussianGenerator(const double _mean, const double _std):
    TimeSeriesGenerator(0), mean(_mean), std(_std)
{

}

GaussianGenerator::GaussianGenerator(const int _seed, const double _mean, const double _std):
    TimeSeriesGenerator(_seed), mean(_mean), std(_std)
{

}

void GaussianGenerator::setMean(double _mean) {

    mean = _mean;

}

double GaussianGenerator::getMean() const {

    return mean;

}

void GaussianGenerator::setStd(const double _std) {

    std = _std;

}

double GaussianGenerator::getStd() const {

    return std;

}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {

}