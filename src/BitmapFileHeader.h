//
// Created by jedrzej on 2018-02-18.
//

#ifndef LISSAJOUS_BITMAPFILEHEADER_H
#define LISSAJOUS_BITMAPFILEHEADER_H
#include <cstdint>
using namespace std;

#pragma pack(push, 2)

struct BitmapFileHeader {
    char header[2]{ 'B', 'M' };
    int32_t fileSize;
    int32_t reserved{ 0 };
    int32_t dataOffset;
};

#pragma pack(pop)

#endif //LISSAJOUS_BITMAPFILEHEADER_H
