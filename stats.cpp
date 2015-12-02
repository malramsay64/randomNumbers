//
// Created by malcolm on 26/11/15.
//

#include "stats.h"

stats::stats(){
    M1 = M2 = M3 = M4 = 0.0;
    n=0;
}

void stats::push(double val) {
    double delta, delta_n, delta_n2, term1;
    long long n1 = n;
    n++;
    delta = val - M1;
    delta_n = delta/n;
    delta_n2 = delta_n * delta_n;
    term1 = delta * delta_n * n1;
    M1 += delta_n;
    M4 += term1 * delta_n2 * (n*n - 3*n + 3) + 6 * delta_n2 * M2 - 4 * delta_n * M3;
    M3 += term1 * delta_n * (n-2)-3*delta_n * M2;
    M2 += term1;
}

double stats::getMean() {
    return M1;
}

double stats::getVariance() {
    return M2/(n-1.0);
}
double stats::getStandardDeviation(){
    return sqrt(getVariance());
}
double stats::getSkewness(){
    return sqrt(double(n))*M3/pow(M2,1.5);
}
double stats::getKurtosis() {
    return double(n)*M4/(M2*M2)-3.0;
}
