#include <iostream>
#include "SDL.h"
#include "Screen.h"

int main(int argc, char *argv[]){

    Screen screen;
    if(!screen.init()){
        std::cout << "Error initalizing SDL" << std::endl;
    }

    while(true){

        screen.setPixel(300,300,128,128,0);
        screen.update();
        if(!screen.processEvents()){
            break;
        }
    }
    screen.close();
    return 0;
}