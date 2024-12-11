//
// Created by ludwig_van_schlett on 11/12/24.
//

#ifndef KNN_H
#define KNN_H
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "TimesSeriesDataset.h"

class KNN {

    public:
        KNN(int _k, std::string _similarity_measure);

        ~KNN() = default;

        double evaluate(TimesSeriesDataset &trainDataset, TimesSeriesDataset &testDataset, std::vector<int> &groundTruth) const;

    private:
        int k;
        std::string similarity_measure;

};



#endif //KNN_H
