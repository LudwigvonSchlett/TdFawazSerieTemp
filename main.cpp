
#include <iostream>

#include "headers/TimeSeriesGenerator.h"
#include "headers/GaussianGenerator.h"
#include "headers/StepGenerator.h"
#include "headers/SinWaveGenerator.h"


int main() {

    GaussianGenerator g = GaussianGenerator(1, 0.5, 7448);

    StepGenerator s = StepGenerator(7531);

    SinWaveGenerator sw = SinWaveGenerator(2, 0.3, 0,4509);

    std::vector<double> series1 = g.generateTimeSeries(20);

    std::vector<double> series2 = g.generateTimeSeries(20);

    std::vector<double> series3 = s.generateTimeSeries(20);

    std::vector<double> series4 = s.generateTimeSeries(20);

    std::vector<double> series5 = sw.generateTimeSeries(20);

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

    return 0;
}
