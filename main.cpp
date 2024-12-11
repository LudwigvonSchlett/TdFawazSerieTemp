
#include <iostream>
#include <vector>

#include "headers/TimeSeriesGenerator.h"
#include "headers/GaussianGenerator.h"
#include "headers/StepGenerator.h"
#include "headers/SinWaveGenerator.h"
#include "headers/TimesSeriesDataset.h"
#include "headers/KNN.h"


int main() {

    GaussianGenerator g = GaussianGenerator(11);

    StepGenerator s = StepGenerator(11);

    SinWaveGenerator sw = SinWaveGenerator(11);

    std::vector<double> series1 = g.generateTimeSeries(20);

    std::vector<double> series2 = g.generateTimeSeries(20);

    std::vector<double> series3 = s.generateTimeSeries(20);

    std::vector<double> series4 = s.generateTimeSeries(20);

    std::vector<double> series5 = sw.generateTimeSeries(20);

    sw.setPhi(M_PI/2);
    std::vector<double> series6 = sw.generateTimeSeries(20);

    std::vector<double> series7 = g.generateTimeSeries(20);

    std::vector<double> series8 = s.generateTimeSeries(20);

    sw.setPhi(3*M_PI/4);
    std::vector<double> series9 = sw.generateTimeSeries(20);

    std::cout<<"series1: "<<series1.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series1);
    std::cout << std::endl;

    std::cout << "series2: "<<series2.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series2);
    std::cout << std::endl;

    std::cout << "series3: "<<series3.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series3);
    std::cout << std::endl;

    std::cout << "series4: "<<series4.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series4);
    std::cout << std::endl;

    std::cout << "series5: "<<series5.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series5);
    std::cout << std::endl;

    std::cout << "series6: "<<series6.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series6);
    std::cout << std::endl;

    std::cout << "series7: "<<series7.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series7);
    std::cout << std::endl;

    std::cout << "series8: "<<series8.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series8);
    std::cout << std::endl;

    std::cout << "series9: "<<series9.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series9);
    std::cout << std::endl;

    TimesSeriesDataset trainData(false, true), testData(false, false);

    trainData.addTimeSeries(series1, 0);
    trainData.addTimeSeries(series2, 0);
    trainData.addTimeSeries(series3, 1);
    trainData.addTimeSeries(series4, 1);
    trainData.addTimeSeries(series5, 2);
    trainData.addTimeSeries(series6, 2);

    std::vector<int> ground_truth;
    ground_truth.push_back(0);
    ground_truth.push_back(1);
    ground_truth.push_back(2);

    testData.addTimeSeries(series7);
    testData.addTimeSeries(series8);
    testData.addTimeSeries(series9);

    KNN knn_1(1,"dtw");
    std::cout << knn_1.evaluate(trainData,testData,ground_truth) << std::endl;
    KNN knn_2(2,"euclidean_distance");
    std::cout << knn_2.evaluate(trainData,testData,ground_truth) << std::endl;
    KNN knn_3(3,"euclidean_distance");
    std::cout << knn_3.evaluate(trainData,testData,ground_truth) << std::endl;

    return 0;
}
