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

        // Initialize a vector to store the distances to each training series
        std::vector<std::pair<double, int>> distances;

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

            distances.push_back({distance, trainLabels[j]});
        }

        // Sort the distances in ascending order
        std::sort(distances.begin(), distances.end());

        // Find the most frequent label among the k nearest neighbors
        std::unordered_map<int, int> labelCount;
        for (int j = 0; j < k; ++j) {
            int label = distances[j].second;
            labelCount[label]++;
        }

        // Find the label with the highest count
        int predictedLabel = -1;
        int maxCount = -1;
        for (const auto& pair : labelCount) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                predictedLabel = pair.first;
            }
        }

        // Compare with ground truth
        if (predictedLabel == groundTruth[i]) {
            correctPredictions++;
        }
    }

    // Compute accuracy
    return static_cast<double>(correctPredictions) / testData.size();
}
