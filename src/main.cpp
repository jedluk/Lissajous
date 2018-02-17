#include <iostream>
#include "SDL.h"
#include "Screen.h"
#include "ConsoleMenu.h"

int main(int argc, char *argv[]){

    ConsoleMenu::generateInitialContent();
    Screen screen;
    if(!screen.init())
        std::cout << "Error initializing SDL" << std::endl;

    while(true){
        // handle user changes and plot curves
        screen.setPixel(300,300,128,128,0);
        screen.update();
        if(!screen.processEvents()){
            break;
        }
    }

    screen.close();
    return 0;
}