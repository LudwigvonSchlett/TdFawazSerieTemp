//
// Created by ludwig_van_schlett on 20/11/24.
//

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H
#include <vector>


class TimeSeriesGenerator {

    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int _seed);

        virtual ~TimeSeriesGenerator() = default;

        void setSeed(int _seed);
        int getSeed() const;

        virtual std::vector<double> generateTimeSeries(int size) const = 0;
        static void printTimeSeries(std::vector<double> timeSerie);

    protected:
        int seed;

};



#endif //TIMESERIESGENERATOR_H
