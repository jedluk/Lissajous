//
// Created by jedrzej on 2018-02-18.
//

#ifndef LISSAJOUS_BITMAP_H
#define LISSAJOUS_BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

class Bitmap {
private:
    int bitmapNumber{0};
    int m_width{ 0 };
    int m_height{ 0 };
    unique_ptr<uint8_t[]> m_pPixels{ nullptr };
public:
    Bitmap(int width, int height);
    bool write(string filename);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    ~Bitmap();
};


#endif //LISSAJOUS_BITMAP_H
