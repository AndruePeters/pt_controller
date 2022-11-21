#pragma once

#include <string_view>

namespace driver::wifi {

class Wifi {

public:
    void connectStation(std::string_view ssid, std::string_view password);
};

} ///< namespace driver::wifi