#pragma once

#include <string>
#include <stdint.h>
#include <vector>

struct MMIOField 
{
    std::string name;
    std::string bits;
    std::string type;
    std::string description;
    uint32_t resetValue;
};

struct MMIORegister 
{
    std::string name;
    std::string type;
    std::string description;

    uint16_t address;
    uint16_t width;

    uint32_t resetValue;
    std::vector<MMIOField> fields;
};
