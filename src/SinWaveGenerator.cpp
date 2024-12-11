//
// Created by ludwig_van_schlett on 11/12/24.
//

#include "../headers/SinWaveGenerator.h"

SinWaveGenerator::SinWaveGenerator():
    SinWaveGenerator(0)
{

}

SinWaveGenerator::SinWaveGenerator(int _seed):
    SinWaveGenerator(1,1, _seed)
{

}

SinWaveGenerator::SinWaveGenerator(double _alpha, double _omega):
    SinWaveGenerator(_alpha, _omega, 0)
{

}

void SinWaveGenerator::setPhi(double _phi) {

    while (_phi > M_PI*2) {
        _phi -= 2*M_PI;
    }
    while (_phi < 0) {
        _phi += 2*M_PI;
    }

    phi = _phi;
}

double SinWaveGenerator::getPhi() const {
    return phi;
}

SinWaveGenerator::SinWaveGenerator(double _alpha, double _omega, int _seed):
    TimeSeriesGenerator(_seed), alpha(_alpha), omega(_omega), phi(0)
{

}

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) const {
    std::vector<double> series;


    // Si la taille demandée est 0, retourner une série vide
    if (size <= 0) {
        return series;
    }

    // Génération des valeurs à chaque instant x
    for (int i = 0; i < size; ++i) {
        double value = alpha * std::sin(omega * static_cast<double>(i) + phi);
        series.push_back(value);
    }

    return series;
}




