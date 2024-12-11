//
// Created by ludwig_van_schlett on 20/11/24.
//

#include "../headers/GaussianGenerator.h"

GaussianGenerator::GaussianGenerator():
    GaussianGenerator(0.0, 1.0)
{

}

GaussianGenerator::GaussianGenerator(int _seed):
    GaussianGenerator(0.0, 1.0, _seed)
{

}

GaussianGenerator::GaussianGenerator(const double _mean, const double _std):
    GaussianGenerator(_mean, _std, 0)
{

}

GaussianGenerator::GaussianGenerator(const double _mean, const double _std, const int _seed):
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

std::vector<double> GaussianGenerator::generateTimeSeries(int size) const{

    std::vector<double> series;

    std::uniform_real_distribution<double> dist(0.0, 1.0);

    if (size == 0) {
        return series;
    }

    for (int i = 0; i < size/2 ; i ++) {

        // Générer deux nombres uniformes dans [0, 1)
        double u1 = dist(rng);
        double u2 = dist(rng);

        // Appliquer la transformation de Box-Muller
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double z1 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);


        series.push_back(z0);
        series.push_back(z1);

    }

    return series;

}