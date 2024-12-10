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
    // converts X and Y coord to an index
    auto bitmap_point(bitmap& btmp, auto X, auto Y) { return (X + Y * btmp.width) * btmp.channels; }
    // creates empty bitmap with four color chanals per pixel
    [[nodiscard]] bitmap* new_RGBA_bitamp(auto pixel_number, auto w);
    // 8 bit bitmap 3 chanals per pixel
    [[nodiscard]] bitmap* new_RGB_bitamp(auto pixel_number, auto w);
};

#endif // _BTMP_TOOLS_