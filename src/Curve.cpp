//
// Created by jedrzej on 2018-02-17.
//

#include "Curve.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <SDL_events.h>
#include <ctime>
#include "ConsoleMenu.h"
#include <SDL_timer.h>

void Curve::calculateCurve() {
    if(!xValuesVector.empty()){
        xValuesVector.clear();
        yValuesVector.clear();
    }

    for(unsigned int sample = 0; sample <= Curve::SAMPLES ; sample++ ){
        xValuesVector.push_back(
                A_factor * sin(b_factor * timeVector.at(sample) + c_factor));
        yValuesVector.push_back(
                D_factor * sin(e_factor * timeVector.at(sample)));
    }
}

Curve::Curve():
    A_factor(3),
    b_factor(5),
    c_factor(0),
    D_factor(3),
    e_factor(4)
{
    double step = static_cast<double>(TIME_LIMIT)/SAMPLES;
    double time = 0;
    while(time < TIME_LIMIT){
        timeVector.push_back(time);
        time += step;
    }
    calculateCurve();
}

const std::vector<std::pair<double, double> > Curve::getNormalizedData(int WIDTH, int HEIGHT) {
    std::vector<std::pair<double, double>> normalizedData;
    for(unsigned int i = 0 ; i  < xValuesVector.size(); i++){
        double xNormalized = (xValuesVector.at(i) - A_factor) / (A_factor - A_factor*(-1)) * WIDTH;
        double yNormalized = (yValuesVector.at(i) - D_factor) / (D_factor - D_factor*(-1)) * HEIGHT;
        normalizedData.emplace_back(xNormalized,yNormalized);
    }
    return normalizedData;
}

void Curve::randomizeFactors() {
    A_factor = rand() % 10;
    b_factor = static_cast<double>(rand()) / RAND_MAX * M_PI;
    c_factor = static_cast<double>(rand()) / RAND_MAX * M_PI;
    D_factor = rand() % 10;
    e_factor = static_cast<double>(rand()) / RAND_MAX * M_PI;
    calculateCurve();
}

void Curve::handleSaveBitmapEvent() {
    double coefficients[] = {A_factor, b_factor, c_factor, D_factor, e_factor};
    ConsoleMenu::printCurveParameters(coefficients);
}

void Curve::handleRefreshParamsEvent() {
    randomizeFactors();
}
