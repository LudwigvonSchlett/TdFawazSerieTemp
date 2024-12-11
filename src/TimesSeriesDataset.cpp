//
// Created by ludwig_van_schlett on 11/12/24.
//

#include "../headers/TimesSeriesDataset.h"

TimesSeriesDataset::TimesSeriesDataset():
    TimesSeriesDataset(false, false)
{

}

TimesSeriesDataset::TimesSeriesDataset(bool _znormalize, bool _isTrain):
    znormalize(_znormalize), isTrain(_isTrain), maxLength(50), numberOfSamples(0)
{

}


std::vector<double> TimesSeriesDataset::znormalizeSeries(const std::vector<double>& _series) const {

    double mean = std::accumulate(_series.begin(), _series.end(), 0.0) / _series.size();
    double variance = 0.0;
    for (double value : _series) {
        variance += (value - mean) * (value - mean);
    }
    double stddev = std::sqrt(variance / _series.size());
    if (stddev == 0.0) stddev = 1.0; // Avoid division by zero

    std::vector<double> normalized(_series.size());
    std::transform(_series.begin(), _series.end(), normalized.begin(), [mean, stddev](double value) { return (value - mean) / stddev; });
    return normalized;

}


void TimesSeriesDataset::addTimeSeries(const std::vector<double>& _series, int _label) {

    std::vector<double> newSeries = _series;

    if (!isTrain) {
        throw std::invalid_argument("Testing data can't be labeled");
    }

    // Normalize if z-normalize is enabled
    if (znormalize) {
        newSeries = znormalizeSeries(_series);
    }

    // Optionally enforce maxLength
    if (newSeries.size() > static_cast<size_t>(maxLength)) {
        newSeries.resize(maxLength);
    }

    data.push_back(newSeries);
    label.push_back(_label);
    numberOfSamples++;

}

void TimesSeriesDataset::addTimeSeries(const std::vector<double>& _series) {

    std::vector<double> newSeries = _series;

    if (isTrain) {
        throw std::invalid_argument("Training data must be labeled");
    }

    // Normalize if z-normalize is enabled
    if (znormalize) {
        newSeries = znormalizeSeries(_series);
    }

    // Optionally enforce maxLength
    if (newSeries.size() > static_cast<size_t>(maxLength)) {
        newSeries.resize(maxLength);
    }

    data.push_back(newSeries);
    numberOfSamples++;

}

std::vector<std::vector<double> > TimesSeriesDataset::getData() const {
    return data;
}





