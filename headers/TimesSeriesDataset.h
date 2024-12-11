//
// Created by ludwig_van_schlett on 11/12/24.
//

#ifndef TIMESSERIESDATASET_H
#define TIMESSERIESDATASET_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <stdexcept>


class TimesSeriesDataset {

    public:
        TimesSeriesDataset();
        TimesSeriesDataset(bool _znormalize, bool _isTrain);
        ~TimesSeriesDataset() = default;

        void addTimeSeries(const std::vector<double>& _series);
        void addTimeSeries(const std::vector<double>& _series, int _label);

        std::vector<double> znormalizeSeries(const std::vector<double>& _series) const;

        std::vector<std::vector<double>> getData() const;

    private:
        bool znormalize;
        bool isTrain;
        std::vector<std::vector<double>> data;
        std::vector<int> label;
        int maxLength;
        int numberOfSamples;

};



#endif //TIMESSERIESDATASET_H
