//
// Created by jedrzej on 2018-02-17.
//

#ifndef LISSAJOUS_SCREEN_H
#define LISSAJOUS_SCREEN_H

#include "SDL.h"
#include "Bitmap.h"
#include <iostream>

using namespace std;

class Screen
{
public:
    const static int SCREEN_WIDTH = 1280;
    const static int SCREEN_HEIGHT = 720;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;
    Bitmap bitmap;
public:
    Screen();
    ~Screen();
    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void close();
    void clear();
    void boxBlur();
    void save();
};



#endif //LISSAJOUS_SCREEN_H
