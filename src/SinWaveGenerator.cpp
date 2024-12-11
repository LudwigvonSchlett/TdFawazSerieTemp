//
// Created by ludwig_van_schlett on 11/12/24.
//

#include "../headers/SinWaveGenerator.h"

SinWaveGenerator::SinWaveGenerator():
    SinWaveGenerator(0)
{

}

SinWaveGenerator::SinWaveGenerator(int _seed):
    SinWaveGenerator(1,1,0, _seed)
{

}

SinWaveGenerator::SinWaveGenerator(double _alpha, double _omega, double _phi):
    SinWaveGenerator(_alpha, _omega, _phi, 0)
{

}

SinWaveGenerator::SinWaveGenerator(double _alpha, double _omega, double _phi, int _seed):
    TimeSeriesGenerator(_seed), alpha(_alpha), omega(_omega), phi(_phi)
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



