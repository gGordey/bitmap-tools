#include "btmptools.h"

#include <vector>
#include <iostream>

using namespace std;

[[nodiscard]] btmptools::bitmap* btmptools::new_RGBA_bitamp(auto pixel_number, auto w)
{
    btmptools::bitmap nw_btmp;
    nw_btmp.channels = 4;
    nw_btmp.width = w;
    nw_btmp.data = vector<std::byte>(pixel_number*4);
    return &nw_btmp;
}
