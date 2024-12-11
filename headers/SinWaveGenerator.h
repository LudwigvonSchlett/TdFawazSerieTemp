//
// Created by ludwig_van_schlett on 11/12/24.
//

#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"

class SinWaveGenerator: public TimeSeriesGenerator {

    public:
        SinWaveGenerator();
        SinWaveGenerator(int _seed);
        SinWaveGenerator(double _alpha, double _omega);
        SinWaveGenerator(double _alpha, double _omega, int _seed);

        ~SinWaveGenerator() = default;

        std::vector<double> generateTimeSeries(int size) const override;

        void setPhi(double _phi);
        double getPhi() const;

    private:
        double alpha;
        double omega;
        double phi;

};



#endif //SINWAVEGENERATOR_H
