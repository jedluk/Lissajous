#include <iostream>
#include "SDL.h"
#include "Screen.h"
#include "ConsoleMenu.h"
#include "Curve.h"
#include "Bitmap.h"
#include <math.h>
#include <ctime>

int REFRESH_TIME_MS = 5000;

int main(int argc, char *argv[]){

    srand((unsigned int) time (nullptr));

//    ConsoleMenu::generateInitialContent();
    Screen screen;
    Curve curve;
    Bitmap bitmap(screen.SCREEN_WIDTH, screen.SCREEN_HEIGHT);
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
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                std::cout << "key pressed " << event.key.keysym.sym << std::endl;
                if (event.key.keysym.sym == 115) {
                    for (int x = 0; x < screen.SCREEN_WIDTH; x++)
                        for (int y = 0; y < screen.SCREEN_HEIGHT; y++)
                            bitmap.setPixel(x, y, 0, 0, 0);

                    for (auto const &value: normalizedData)
                        bitmap.setPixel(static_cast<int>(value.first)  + screen.SCREEN_WIDTH,
                                        static_cast<int>(value.second) + screen.SCREEN_HEIGHT,
                                        green, red, blue);
                    bitmap.write("test.bmp");
                    return false;
                }
            }
        }

//        if(!curve.processEvents()){
//            break;
//        }

        if(SDL_GetTicks() > REFRESH_TIME_MS ){
            REFRESH_TIME_MS += 5000;
            curve.randomizeFactors();
            curve.calculateCurve();
        }
    }

    screen.close();
    return 0;
}