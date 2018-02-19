#include "ConsoleMenu.h"
#include <iostream>

void ConsoleMenu::generateInitialContent() {
    std::cout << "\t******LISSAJOUS CURVE GENERATOR******\t" << std::endl << std::endl;
    std::cout << "Lissajous curve is pattern formed when two harmonic ";
    std::cout << "vibrations along perpendicular lines are superimposed." << std::endl << std::endl;
    std::cout << "It can bed described via parametric equation:" << std::endl;
    std::cout << "x(t) = A sin(bt + c)" << std::endl;
    std::cout << "y(t) = D sin(et)" << std::endl << std::endl << std::endl;
    printManual();
}

void ConsoleMenu::printManual(){
    std::cout << "MANUAL:" << std::endl;
    std::cout << "1. Curve is refreshed after each 5 seconds" << std::endl;
    std::cout << "1. Press 'r' to force program to randomize curve factors" << std::endl;
    std::cout << "3. Press 's' to save current view as bitmap" << std::endl;
}

void ConsoleMenu::printCurveParametrs(std::vector<double> coefficients) {
    std::cout << "Succesfully saved bitmap!" << std::endl;
    std::cout << "Your curve equations:" << std::endl;
    std::cout << "x(t) = " << coefficients.at(1) << "sin("
                        << coefficients.at(2) << "t + " << coefficients.at(3) << ")" << std::endl;
    std::cout << "y(t) = " << coefficients.at(4) << "sin("  << coefficients.at(5) << "t)" << std::endl << std::endl;
}

