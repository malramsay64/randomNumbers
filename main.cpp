#include <iostream>
#include <random>
#include "stats.h"

using namespace std;

/*
 * This tests the various random number generators for their statistical
 * distributions over a large number of trials, allowing comparison between
 * them.
 */

int main() {
    long trials = 1e10;
    stats s_default, s_random, s_knuth, s_mersenne;
    // Distribution
    normal_distribution<double> distribution(0,1);

    // Default random engine
    default_random_engine default_generator;

    //Random Device
    random_device random_generator;

    //Knuth_b engine
    knuth_b knuth_generator;

    //Mersenne twister
    mt19937 mersenne_generator;

    for (long i=0; i < trials; i++){
        s_default.push(distribution(default_generator));
        s_random.push(distribution(random_generator));
        s_knuth.push(distribution(knuth_generator));
        s_mersenne.push(distribution(mersenne_generator));
    }
    cout << "Default" << endl;
    cout << "Mean: " << s_default.getMean() << " StdDev: " << s_default.getStandardDeviation() << " Skew: " << s_default.getSkewness() << endl;
    cout << "Random" << endl;
    cout << "Mean: " << s_random.getMean() << " StdDev: " << s_random.getStandardDeviation() << " Skew: " << s_random.getSkewness() << endl;
    cout << "Knuth" << endl;
    cout << "Mean: " << s_knuth.getMean() << " StdDev: " << s_knuth.getStandardDeviation() << " Skew: " << s_knuth.getSkewness() << endl;
    cout << "Mersenne" << endl;
    cout << "Mean: " << s_mersenne.getMean() << " StdDev: " << s_mersenne.getStandardDeviation() << " Skew: " << s_mersenne.getSkewness() << endl;

    return 0;
}