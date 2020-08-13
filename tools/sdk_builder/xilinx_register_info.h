#pragma once

#include <stdint.h>
#include <string>

struct XilinxRegisterInfo 
{
    XilinxRegisterInfo(){}
    XilinxRegisterInfo(std::string const& line);

    std::string name;
    uint32_t address;
    uint32_t width;
    std::string type;
    uint32_t resetValue;
    std::string description;
};
