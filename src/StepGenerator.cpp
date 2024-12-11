//
// Created by ludwig_van_schlett on 20/11/24.
//

#include "../headers/StepGenerator.h"


StepGenerator::StepGenerator():
    StepGenerator(0)
{

}

StepGenerator::StepGenerator(int _seed):
    TimeSeriesGenerator(_seed)
{

}

std::vector<double> StepGenerator::generateTimeSeries(int size) const {
    std::vector<double> series;

    // Si la taille demandée est 0, retourner une série vide
    if (size <= 0) {
        return series;
    }

    // Distribution pour générer des valeurs entre 0 et 100
    std::uniform_int_distribution<int> distribution(0, 100);

    // Distribution pour générer un nombre entre 0 et 1 pour la probabilité (50%)
    std::uniform_real_distribution<double> probability(0.0, 1.0);

    // Initialisation de la première valeur à 0
    series.push_back(0);

    // Génération des valeurs suivantes
    for (int i = 1; i < size; ++i) {
        // Tirage d'un nombre entre 0 et 1 pour décider si on garde la valeur précédente ou on génère un nouveau saut
        if (probability(rng) < 0.5) {
            // Garder la valeur précédente
            series.push_back(series[i - 1]);
        } else {
            // Générer une nouvelle valeur aléatoire entre 0 et 100
            series.push_back(distribution(rng));
        }
    }

    return series;
}


