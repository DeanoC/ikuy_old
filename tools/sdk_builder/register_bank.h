#pragma once

#include <string>
#include <map>
#include <vector>

#include "mmio.h"
struct XilinxRegisterInfo;

struct RegisterBank 
{
    RegisterBank(   std::string const & name_,
                    std::string const & description_,
                    const char * xilinxRegisterTxt,
                    const char * xilinxFieldTxt);
    void ParseRegisterText(const char * xilinxRegisterTxt);

    void ParseFieldText(const char * xilinxFieldTxt);

    void addAt(XilinxRegisterInfo const & xi);

    void addFieldsFor(std::string const& name, std::vector<MMIOField> const & fields );

    std::vector<MMIORegister> registersAsSortedVector() const;
    std::string name;
    std::string description;

    std::map<std::string, MMIORegister> registers;
};
