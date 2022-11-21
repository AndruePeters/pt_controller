#pragma once

#include <cctype>
#include <string>

class DeviceInfo {
    uint8_t mac [6];
    std::string deviceName;
    uint64_t irCode;
};