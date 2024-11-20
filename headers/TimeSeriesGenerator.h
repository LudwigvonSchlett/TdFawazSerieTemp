//
// Created by ludwig_van_schlett on 20/11/24.
//

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H
#include <random>
#include <vector>


class TimeSeriesGenerator {

    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int _seed);

        virtual ~TimeSeriesGenerator() = default;

        void setSeed(int _seed);
        int getSeed() const;

        virtual std::vector<double> generateTimeSeries(int size) const = 0;
        static void printTimeSeries(const std::vector<double>& timeSeries);

    protected:
        int seed;

        mutable std::mt19937 rng;


};



#endif //TIMESERIESGENERATOR_H
