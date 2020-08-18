
#include "register_bank_implementations.h"


#include <unistd.h>
#include <sstream>
#include <errno.h>
#include <cctype>
#include <string.h>

static void DecodeBits(    std::string const & bits, 
                    uint32_t & outShift, 
                    uint32_t & outMask,
                    uint32_t & outBitCount )
{
    auto split = bits.find(':');
    if( split != bits.npos )
    {
        std::string hi = bits.substr(0, split);
        std::string lo = bits.substr(split+1);
        uint32_t vhi = std::stoul(hi);
        uint32_t vlo = std::stoul(lo);
        outShift = vlo;
        outBitCount = (vhi - vlo) + 1;
        outMask = ((1 << outBitCount) - 1) << vlo;
    } else
    {
        //easier case
        uint32_t v = std::stoul(bits);
        outShift = v;
        outMask = 1 << v;
        outBitCount = 1;
    }
}

void RegisterBankImplementations::GenerateRegisterStructures()
{
    std::stringstream s;

    s << "#pragma once\n";
    s << "// Copyright Deano Calver\n";
    s << "// SPDX-License-Identifier: MIT\n";

    s << "\n#include <stdint.h>\n";

    s << "\n// " << bank.description << "\n";
    s << "\n// " << hw.size() << " bank" << (hw.size() > 1 ? "s" : "") << " of " << bank.name << "\n\n";


    for (auto &&impl : hw)
    {
        s << "#define " << impl.first << "_" << "BASE_ADDR ";
        s << "0x" << std::hex << impl.second << std::dec << "U\n";       
    }

    s << "\n// Registers\n\n";

    for (auto &&i : bank.registersAsSortedVector())
    {
        s << "// " << i.description << "\n";
        s << "#define " << bank.name << "_" << i.name << "_REG ";
        s << "0x" << std::hex << i.address << std::dec << "U\n";

        uint32_t bitsAllocated = 0;
        for (auto &&f : i.fields)
        {
            uint32_t shift = 0;
            uint32_t mask = 0;
            uint32_t bitWidth = 0;
            DecodeBits(f.bits,shift, mask, bitWidth);
            bitsAllocated += bitWidth;
        }

        // no fields just write uint32_t to as a blind register
        if(bitsAllocated == 0)
        {
//            s << "typedef uint32_t " << bank.name << "_" << i.name << ";\n";
            s << "\n\n";
            continue;
        }
        
        if(bitsAllocated != 32)
        {
            printf("WARNING: Only %i for register %s : %s\n", bitsAllocated, bank.name.c_str(), i.name.c_str());
        }
/*
        s << "typedef union " << bank.name << "_" << i.name << "\n";
        s << "{\n";
        s << "\tstruct\n\t{\n";
*/
        uint32_t totalMask = 0;

        for (auto &&f : i.fields)
        {
            uint32_t shift = 0;
            uint32_t mask = 0;
            uint32_t bitWidth = 0;
            DecodeBits(f.bits,shift, mask, bitWidth);
//            s << "\t\tuint32_t " << f.name << " : " << bitWidth << ";\n";
            if(f.name.find("RESERVED") != f.name.npos|| f.name.find("reserved") != f.name.npos)
            {
                // don't add to total mask
            } else
            {
                totalMask |= mask;

            }
        }
        

/*        s << "\t} fields;\n";
        s << "\tuint32_t v;\n";
        s << "} " << bank.name << "_" << i.name <<";\n";

        s << "\n";*/
        for (auto &&f : i.fields)
        {
            uint32_t shift = 0;
            uint32_t mask = 0;
            uint32_t bitWidth = 0;
            DecodeBits(f.bits,shift, mask, bitWidth);
            s << "#define " << bank.name << "_" << i.name << "_" << f.name << "_LSHIFT " << shift << "U\n";
            // have an non mask postfix for single bits as well
            // mask version is kept for consistance
            if(bitWidth == 1) 
            {
                s << "#define " << bank.name << "_" << i.name << "_" << f.name << " ";
                s << "0x" << std::hex << mask << std::dec << "U\n";
            }

            s << "#define " << bank.name << "_" << i.name << "_" << f.name << "_MASK ";
            s << "0x" << std::hex << mask << std::dec << "U\n";        
        }
        s << "#define " << bank.name << "_" << i.name << "_MASK ";
        s << "0x" << std::hex << totalMask << std::dec << "U\n";

        s << "\n\n";

    }

    char cwd[1024];    
    getcwd(cwd, sizeof(cwd));
    printf("Current working dir: %s\n", cwd);

    std::string bankStructsFN = std::string("../../generated/sdk/") + bank.name + ".h";
    FILE* bankStructsFH = fopen(bankStructsFN.c_str(), "w");

    if(!bankStructsFH) 
    {       
        printf("%s error %s\n", bankStructsFN.c_str(), strerror(errno));
        exit(0);
    }

    std::string ss = s.str();
    fwrite( ss.c_str(), ss.size(), 1, bankStructsFH);

    fclose(bankStructsFH);
}

void RegisterBankImplementations::DumpFieldDefNoDescription()
{
    printf("R\"(");

    for (auto &&i : bank.registersAsSortedVector())
    {
        printf("%s\n",i.name.c_str());

        for (auto &&j : i.fields)
        {
            printf("%s %s %s 0x%.8x\n",  j.name.c_str(), 
                                    j.bits.c_str(), 
                                    j.type.c_str(),
                                    j.resetValue);
        }
        printf("\n");
    }    

    printf(")\";");
}

void RegisterBankImplementations::LogRegisterBank() 
{
    for (auto &&i : bank.registersAsSortedVector())
    {
        printf("\n%s, 0x%.4x, %i, %s, 0x%.8x, %s\nFields:\n",
                i.name.c_str(), i.address, i.width, 
                i.type.c_str(), i.resetValue, i.description.c_str()
                );

        for (auto &&j : i.fields)
        {

            printf("%s %s %s 0x%.8x\n%s",  
                                    j.name.c_str(), 
                                    j.bits.c_str(), 
                                    j.type.c_str(),
                                    j.resetValue,
                                    j.description.c_str());
        }
    }    
}
