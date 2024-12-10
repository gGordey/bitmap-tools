#include <iostream>
#include <vector>

#ifndef _BTMP_TOOLS_
#define _BTMP_TOOLS_

// id for different color storing types
#define RGBA_8bit_palette 0
#define RGB_8bit_palette 1

using namespace std;

namespace btmptools
{
    struct bitmap
    {
        vector<std::byte> data;
        unsigned width;
        std::byte channels;
    };
    // converts X and Y coord to a vector with all color channels at this pixel
    [[nodiscard]] vector<std::byte> bitmap_point(bitmap& btmp, int X, int Y);
    // creates empty bitmap with four color chanals per pixel
    [[nodiscard]] bitmap new_multichannel_bitamp(unsigned pixel_number, unsigned w, unsigned channels);
    // fully fills all the pixels in one channel with given value 
    void fill_bitmap(btmptools::bitmap& bitmap, std::byte value, std::byte channel);
    // printing bitmap
    void print_bitmap(btmptools::bitmap& bitmap);
}

#endif // _BTMP_TOOLS_