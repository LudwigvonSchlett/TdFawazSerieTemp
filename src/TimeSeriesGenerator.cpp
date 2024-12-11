//
// Created by ludwig_van_schlett on 20/11/24.
//

#include "../headers/TimeSeriesGenerator.h"


TimeSeriesGenerator::TimeSeriesGenerator():
    TimeSeriesGenerator(0)
{

}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
    seed(_seed), rng(_seed)
{

}

void TimeSeriesGenerator::setSeed(int _seed) {
    rng.seed(_seed);
    seed = _seed;
}

int TimeSeriesGenerator::getSeed() const {
    return seed;
}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& timeSeries) {

    for (double value : timeSeries) {

        std::cout << value << " ";

    }

}

double TimeSeriesGenerator::euclideanDistance(const std::vector<double> &x, const std::vector<double> &y) {

    if (x.size() != y.size()) {
        throw std::invalid_argument("Time series must be of equal length for Euclidean Distance.");
    }

    double sum = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        sum += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return std::sqrt(sum);
}


double TimeSeriesGenerator::dtw(const std::vector<double> &x, const std::vector<double> &y) {
    size_t n = x.size();
    size_t m = y.size();

    // Initialize DP table with infinite values
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(m + 1, std::numeric_limits<double>::infinity()));
    dp[0][0] = 0.0;

    // Fill the DP table
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            double cost = (x[i - 1] - y[j - 1]) * (x[i - 1] - y[j - 1]);
            dp[i][j] = cost + std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1]));

        }
    }

    return std::sqrt(dp[n][m]);
}



