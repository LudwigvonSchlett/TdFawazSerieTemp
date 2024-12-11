//
// Created by ludwig_van_schlett on 20/11/24.
//

#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"


class StepGenerator: public TimeSeriesGenerator{

    public:
        StepGenerator();
        StepGenerator(int _seed);
        ~StepGenerator() = default;

        std::vector<double> generateTimeSeries(int size) const override;

};



#endif //STEPGENERATOR_H
