#include <iostream>
#include "SDL.h"
#include "Screen.h"
#include "ConsoleMenu.h"
#include "Curve.h"
#include <math.h>
#include <ctime>

int REFRESH_TIME_MS = 5000;

int main(int argc, char *argv[]){

    srand((unsigned int) time (NULL));

//    ConsoleMenu::generateInitialContent();
    Screen screen;
    Curve curve;
    if(!screen.init())
        std::cout << "Error initializing SDL" << std::endl;

    while(true){
        int elapsed = SDL_GetTicks();

        auto green = static_cast<unsigned char>((1 + sin(elapsed * 0.0001)) * 128);
        auto red = static_cast<unsigned char>((1 + sin(elapsed * 0.0002)) * 128);
        auto blue = static_cast<unsigned char>((1 + sin(elapsed * 0.0003)) * 128);

        auto normalizedData = curve.getNormalizedData(screen.SCREEN_WIDTH, screen.SCREEN_HEIGHT);

        for (unsigned int i = 0 ; i < Curve::SAMPLES ; i++){
            auto x = static_cast<int>(normalizedData.at(i).first) + screen.SCREEN_WIDTH;
            auto y = static_cast<int>(normalizedData.at(i).second) + screen.SCREEN_HEIGHT;
            screen.setPixel(x,y,green,red,blue);
        }
        screen.boxBlur();
        screen.update();
        if(!curve.processEvents()){
            break;
        }

        if(SDL_GetTicks() > REFRESH_TIME_MS ){
            REFRESH_TIME_MS += 5000;
            curve.randomizeFactors();
            curve.calculateCurve();
        }
    }

    screen.close();
    return 0;
}