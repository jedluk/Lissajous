//
// Created by jedrzej on 2018-02-17.
//

#include "Curve.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <SDL_events.h>
#include <ctime>

void Curve::calculateCurve() {
    if(xValuesVector.size() > 0 ){
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
    A_factor(6),
    b_factor(M_PI/2),
    c_factor(M_PI/6),
    D_factor(2),
    e_factor(M_PI/3)
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
        double xNormalized = (xValuesVector.at(i) - A_factor) / (A_factor - A_factor*(-1)) * WIDTH/2;
        double yNormalized = (yValuesVector.at(i) - D_factor) / (D_factor - D_factor*(-1)) * HEIGHT/2;
        normalizedData.push_back(std::make_pair(xNormalized,yNormalized));
    }
    return normalizedData;
}

bool Curve::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return false;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case 97:
                        std::cout << "Coefficients are randomized " << std::endl;
                        randomizeFactors();
                        calculateCurve();
                        break;
                }
        }
    }
    return true;
}

void Curve::randomizeFactors() {
    A_factor = rand() % 10;
    b_factor = static_cast<double>(rand()) / RAND_MAX * M_PI;
    c_factor =static_cast<double>(rand()) / RAND_MAX * M_PI;
    D_factor = rand() % 10;
    e_factor = static_cast<double>(rand()) / RAND_MAX * M_PI;
}
