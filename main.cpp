
#include <iostream>

#include "headers/TimeSeriesGenerator.h"
#include "headers/GaussianGenerator.h"


int main() {

    GaussianGenerator g = GaussianGenerator(1, 0.5, 7448);

    std::vector<double> series1 = g.generateTimeSeries(20);

    std::vector<double> series2 = g.generateTimeSeries(20);

    std::cout<<"series1: "<<series1.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series1);
    std::cout << std::endl;

    std::cout << "series2: "<<series2.size()<< std::endl;
    TimeSeriesGenerator::printTimeSeries(series2);
    std::cout << std::endl;


    return 0;
}
