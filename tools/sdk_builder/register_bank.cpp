#include "register_bank.h"
#include "xilinx_register_info.h"

#include <assert.h>
#include <algorithm>
#include <sstream>


#define STOUL(str, a, base) \
        try { \
            a = std::stoul(str, nullptr, base); \
        } catch(std::exception const& e) \
        { \
            printf("Exception %s from %s\n", e.what(), str.c_str() ); \
        }

#define STOUL_HEX(str, a) STOUL(str, a, 16)


RegisterBank::RegisterBank( 
                std::string const & name_,
                std::string const & description_,
                const char * xilinxRegisterTxt,
                const char * xilinxFieldTxt) : 
    name(name_),
    description(description_)
{
    ParseRegisterText(xilinxRegisterTxt);
    ParseFieldText(xilinxFieldTxt);
}


void RegisterBank::addAt(XilinxRegisterInfo const & xi) 
{
    assert((xi.address & 0xFFFF0000) == 0);
    registers[xi.name] = MMIORegister{ xi.name, 
                            xi.type,
                            xi.description,
                            (uint16_t) xi.address, 
                            (uint16_t) xi.width, 
                            xi.resetValue,
                            {} };
}

void RegisterBank::addFieldsFor(std::string const& name, std::vector<MMIOField> const & fields )
{
    if(registers.find(name) == registers.end()) {
        printf("ERROR: Trying to add fields to non existant register %s\n", name.c_str());
        return;
    }

    assert(registers.find(name) != registers.end());
    assert(registers[name].fields.empty());
    registers[name].fields = fields;
}


std::vector<MMIORegister> RegisterBank::registersAsSortedVector() const
{
    std::vector<MMIORegister> registerVector;
    registerVector.reserve(registers.size());
    for (auto &&i : registers)
    {
        registerVector.push_back(i.second);
    }
    std::sort( registerVector.begin(),
                registerVector.end(),
                [](MMIORegister const & a, MMIORegister const & b){
                    return a.address < b.address;
                } );
    return registerVector;
}    

 void RegisterBank::ParseRegisterText(const char * xilinxRegisterTxt)
{
    char const * cur = xilinxRegisterTxt;
    std::string lineBuffer;
    lineBuffer.reserve(2048);

    while(*cur != 0)
    {
        while(*cur != '\n' && *cur != 0) {
            lineBuffer += *cur;
            cur++;
        }

        if(*cur != 0) 
        {
            cur++;
        }
        if(!lineBuffer.empty())
        {
            lineBuffer += '\n';                
            XilinxRegisterInfo tmp(lineBuffer);            
            addAt(tmp);
            lineBuffer.clear();
        }
    }

}

void RegisterBank::ParseFieldText(const char * xilinxFieldTxt)
{
    std::stringstream fieldStream(xilinxFieldTxt);
    std::map<std::string, std::string> regs;
    std::vector<std::string> fieldsInRegister;

    std::string buf;
    buf.reserve(2048);
    std::string buf2;
    buf2.reserve(2048);

    std::string registerName;
    std::string regFieldTxt;

    while(std::getline(fieldStream, buf, '\n'))
    {
        bool isField = false;
        auto const nameSpacePos = buf.find_first_of(' ');
        // any spaces except at the end means its a field not a register name
        if(nameSpacePos != std::string::npos ) {           
            auto otherCharAfterSpace = buf.find_first_not_of(" \t", nameSpacePos+1);

            if(otherCharAfterSpace != std::string::npos)
            {
                isField = true;
            } else
            {
                // truncate any white space 
                buf.resize(nameSpacePos);
            }
        } 

        if(!isField)
        {
            // must be upper case
            for (auto &&firstc : buf)
            {
                if(firstc == '_') continue;

                if(std::islower(firstc))
                {
                    isField = true;
                    break;
                }

                if(!std::isalnum(firstc))
                {
                    isField = true;
                    break;
                }                            
            }
        }
        if(isField) 
        {
            regFieldTxt += buf;
            regFieldTxt += '\n';
        } else
        {
            if(!registerName.empty())
            {
                regs[registerName] = regFieldTxt;
            }
            registerName = buf;
            regFieldTxt.clear();
        }
        
        buf.clear();
    }

    bool hasLetters = false;
    bool word4anX = false;

    for (auto &&i : regs)
    {
        std::stringstream fieldStream2(i.second);
        std::string words[4];
        std::string comment;

        MMIOField field;
        int reservedCount = 0;

        while(std::getline(fieldStream2, buf, '\n'))
        {
            std::istringstream wordDecoder(buf);
            if(!std::getline(wordDecoder, buf2, ' '))
            {
                goto MustBeAComment;
            }
            words[0] = buf2;
            if(!std::getline(wordDecoder, buf2, ' '))
            {
                goto MustBeAComment;
            }
            words[1] = buf2;
            if(!std::getline(wordDecoder, buf2, ' '))
            {
                goto MustBeAComment;
            }
            words[2] = buf2;
            if(!std::getline(wordDecoder, buf2, ' '))
            {
                goto MustBeAComment;
            }
            words[3] = buf2;

            // we have a least 4 words so *might* be a field def
            // special case reserved (lower case)
            if( (words[0] == "reserved") || (words[0] == "RESERVED"))
            {
                words[0] = std::string("RESERVED_") + std::to_string(reservedCount);
                reservedCount++;
            }

            hasLetters = false;
            // is first all caps?
            for (auto &&firstc : words[0])
            {
                // ignore understand allowe in both cases
                if(firstc == '_') continue;

                if(std::isalpha(firstc)) 
                {
                    hasLetters = true;
                    continue;
                }

                if(std::isdigit(firstc)) continue;

                goto MustBeAComment;
            }
            if(hasLetters == false)
            {
                goto MustBeAComment;
            }

            // is second a valid bit string
            for (auto &&secondc : words[1])
            {
                if(secondc == ':') continue;
                if(!std::isdigit(secondc)) 
                {
                    goto MustBeAComment;
                }
            }

//                printf("%s: %s %s %s %s\n", i.first.c_str(), words[0].c_str(), words[1].c_str(), words[2].c_str(), words[3].c_str());
            word4anX = false;
            // is 4th word a hexdecimal or just x?
            if(words[3][0] != '0' &&
                (words[3][1] != 'x' || words[3][1] != 'X'))
            {
                if((words[3] != "x") && (words[3] != "X"))
                {
                    goto MustBeAComment;                       
                } else
                {
                    word4anX = true;
                }
            }                    

//            printf("%s\n%s\n\n\n",i.first.c_str(), buf.c_str());
            // write out the previous field if any
            if(!field.name.empty())
            {
                if(registers.find(i.first) == registers.end())
                {
                    printf("ERROR register name not found! %s\n", i.first.c_str());
                    exit(0);
                }
                registers[i.first].fields.push_back(field);
            }

            field.name = words[0];
            field.bits = words[1];
            field.type = words[2];
            if(word4anX == false)
            {
                STOUL_HEX(words[3], field.resetValue);
            } else
            {
                field.resetValue = 0;
            }

            std::getline(wordDecoder, field.description, '\n');
            field.description += '\n';
            continue;

MustBeAComment:
            field.description += buf;
            field.description += '\n';
            continue;
        }
        // ensure we got the last one
        if(!field.name.empty())
        {
            registers[i.first].fields.push_back(field);
        }
    }
    
}
