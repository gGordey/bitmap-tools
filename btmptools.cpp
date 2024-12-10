#include "btmptools.h"

#include <vector>
#include <iostream>

using namespace std;

vector<std::byte> btmptools::bitmap_point(btmptools::bitmap& bitmap, int x, int y)
{
    vector<std::byte> res ((int)bitmap.channels);
    int index = bitmap.data.size()/(char)bitmap.channels;
    for (unsigned char i = 0; i < (unsigned char)bitmap.channels; ++i)
    {
        res[i] = bitmap.data[(x + y * bitmap.width) * (unsigned char)bitmap.channels + i];
    }
    return res;
}

void btmptools::fill_bitmap(btmptools::bitmap& bitmap, std::byte value, std::byte channel)
{
    for (int i = (unsigned char)channel; i <= bitmap.data.size(); i += (unsigned char)bitmap.channels)
    {
        bitmap.data[i] = value;
    }
}

btmptools::bitmap btmptools::new_multichannel_bitamp(unsigned pixel_number, unsigned w, unsigned channels)
{
    btmptools::bitmap nw_btmp = *new btmptools::bitmap;
    nw_btmp.channels = std::byte(4);
    nw_btmp.width = w;
    nw_btmp.data = vector<std::byte>(pixel_number*4);
    return nw_btmp;
}

void btmptools::print_bitmap(btmptools::bitmap& bitmap)
{
    for (unsigned i = 0; i <= bitmap.data.size(); ++i)
    {
        cout << static_cast<unsigned>((unsigned char)bitmap.data[i]) << " ";
        if (i % (unsigned char) bitmap.channels == 0) { cout << "\n"; }
    }
}

// following functions are only for using other functions (private)
void change_byte(btmptools::bitmap& bitmap, unsigned index, std::byte value)
{
    bitmap.data[index] = value;
}
void change_pixel(btmptools::bitmap& bitmap, unsigned start_index, vector<std::byte>& pixel)
{
    for (int i = 0; i < pixel.size(); ++i)
    {
        bitmap.data[start_index+5] = pixel[i];
    }
}