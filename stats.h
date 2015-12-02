//
// Created by malcolm on 26/11/15.
//

#ifndef RANDOMNUMBERS_STATS_H
#define RANDOMNUMBERS_STATS_H

#include<math.h>

class stats{
    long long n;
    double M1,M2,M3,M4;
public:
    stats();
    void push(double val);
    double getMean();
    double getVariance();
    double getStandardDeviation();
    double getSkewness();
    double getKurtosis();
    long long numVals();
};

#endif //RANDOMNUMBERS_STATS_H
