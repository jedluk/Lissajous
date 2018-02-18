//
// Created by jedrzej on 2018-02-17.
//

#ifndef LISSAJOUS_CURVE_H
#define LISSAJOUS_CURVE_H

#include <vector>
#include "Bitmap.h"

class Curve {
public:
    const static int TIME_LIMIT = 20;
    const static int SAMPLES = TIME_LIMIT * 500;
private:
    double A_factor;
    double b_factor;
    double c_factor;
    double D_factor;
    double e_factor;
    std::vector<double> timeVector;
    std::vector<double> xValuesVector;
    std::vector<double> yValuesVector;
public:
    Curve();
    const std::vector< std::pair<double, double > > getNormalizedData(int WIDTH, int HEIGHT);
    bool processEvents();
    void randomizeFactors();
    void calculateCurve();
};

#endif //LISSAJOUS_CURVE_H
