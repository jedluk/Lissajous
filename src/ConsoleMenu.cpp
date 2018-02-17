#include "ConsoleMenu.h"
#include <iostream>

void ConsoleMenu::generateInitialContent() {
    std::cout << "\t******LISSAJOUS CURVE GENERATOR******\t" << std::endl << std::endl;
    std::cout << "Lissajous curve is pattern formed when two harmonic ";
    std::cout << "vibrations along perpendicular lines are superimposed." << std::endl << std::endl;
    std::cout << "It can bed described via parametric equation:" << std::endl;
    std::cout << "x(t) = A sin(bt + c)" << std::endl;
    std::cout << "y(t) = D sin(et)" << std::endl << std::endl << std::endl;
    std::cout << "MANUAL:" << std::endl;
    std::cout << "1. Press 1-5 to see predefined curves" << std::endl;
    std::cout << "2. Press:" << std::endl <<
                            "\tA/a to increase/decrease A factor\n"
                            "\tB/b to increase/decrease b factor\n"
                            "\tC/c to increase/decrease c factor\n"
                            "\tD/d to increase/decrease D factor\n"
                            "\tE/e to increase/decrease e factor\n";
    std::cout << "3. Type 's value' and hit enter to set step value. You can choose values in the range <-3*pi,3*pi>" << std::endl;
    std::cout << "   [if you provide the value written as 2pi / 2PI / 2*pi / 2*PI it will be interpreted correctly]" << std::endl;
    std::cout << "Example of usage: s 2*pi -- setting positive step as 2pi. From now each parameter will be increased/decreased by this value" << std::endl;

}
