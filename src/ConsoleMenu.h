//
// Created by jedrzej on 2018-02-17.
//

#ifndef LISSAJOUS_CONSOLEMENU_H
#define LISSAJOUS_CONSOLEMENU_H


#include <vector>

class ConsoleMenu {
public:
    static void generateInitialContent();
    static void printManual();
    static void printCurveParameters(double array[]);
};


#endif //LISSAJOUS_CONSOLEMENU_H
