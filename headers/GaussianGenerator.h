//
// Created by ludwig_van_schlett on 20/11/24.
//

#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"


class GaussianGenerator: public TimeSeriesGenerator {

    public:
        GaussianGenerator();
        GaussianGenerator(double _mean, double _std);
        GaussianGenerator(int _seed, double _mean, double _std);

        ~GaussianGenerator() = default;

        void setMean(double _mean);
        double getMean() const;
        void setStd(double _std);
        double getStd() const;

        double boxMuller();
        std::vector<double> generateTimeSeries(int size) const override;

    private:
        double mean;
        double std;
};



#endif //GAUSSIANGENERATOR_H
