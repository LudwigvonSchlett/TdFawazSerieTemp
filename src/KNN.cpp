//
// Created by ludwig_van_schlett on 11/12/24.
//

#include <utility>

#include "../headers/KNN.h"

#include <map>
#include <queue>

#include "../headers/TimeSeriesGenerator.h"

KNN::KNN(int _k, std::string _similarity_measure):
    k(_k), similarity_measure(std::move(_similarity_measure))
{

}


double KNN::evaluate(TimesSeriesDataset &trainDataset, TimesSeriesDataset &testDataset, std::vector<int> &groundTruth) const {
    const auto& trainData = trainDataset.getData();
    const auto& testData = testDataset.getData();
    const auto& trainLabels = trainDataset.getLabel();

    if (testData.size() != groundTruth.size()) {
        throw std::invalid_argument("Mismatch between test data size and ground truth size.");
    }

    int correctPredictions = 0;

    for (size_t i = 0; i < testData.size(); ++i) {
        const auto& testSeries = testData[i];

        // Initialize variables for finding the nearest neighbor
        double minDistance = std::numeric_limits<double>::infinity();
        int nearestNeighborLabel = -1;

        // Compute distance to all training series
        for (size_t j = 0; j < trainData.size(); ++j) {
            const auto& trainSeries = trainData[j];

            double distance;
            if (similarity_measure == "euclidean_distance") {
                distance = TimeSeriesGenerator::euclideanDistance(testSeries, trainSeries);
            } else if (similarity_measure == "dtw") {
                distance = TimeSeriesGenerator::dtw(testSeries, trainSeries);
            } else {
                throw std::invalid_argument("Unsupported similarity measure: " + similarity_measure);
            }

            // Update the nearest neighbor if this distance is smaller
            if (distance < minDistance) {
                minDistance = distance;
                nearestNeighborLabel = trainLabels[j];
            }
        }

        // Compare with ground truth
        if (nearestNeighborLabel == groundTruth[i]) {
            correctPredictions++;
        }
    }

    // Compute accuracy
    return static_cast<double>(correctPredictions) / testData.size();
}