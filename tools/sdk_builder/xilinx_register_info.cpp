#include "xilinx_register_info.h"

#define STOUL(str, a, base) \
        try { \
            a = std::stoul(str, nullptr, base); \
        } catch(std::exception const& e) \
        { \
            printf("Exception %s from %s\n", e.what(), str.c_str() ); \
        }

#define STOUL_HEX(str, a) STOUL(str, a, 16)

XilinxRegisterInfo::XilinxRegisterInfo(std::string const& line)
{
    {
        std::string tmpBuffer;
        tmpBuffer.reserve(2048);

        char const * cur = line.c_str();
        while(*cur != ' ' && *cur != 0) {
            name += *cur;
            cur++;
        }
        cur++;
/*        static int count = 0;
        if (count > 200 && count < 400)
            printf("%s\n", name.c_str());*/

        while(*cur != ' ') {
            tmpBuffer += *cur;
            cur++;
        }

        STOUL_HEX(tmpBuffer, address);
        tmpBuffer.clear();
        cur++;

        if(address > 0x1FFF) {
            printf("WARNING: register can't be using by init programs! %s\n", name.c_str());
        }

        while(*cur != ' ') {
            tmpBuffer += *cur;
            cur++;
        }
        STOUL_HEX(tmpBuffer, width);
        tmpBuffer.clear();
        cur++;

        char lastchar = ' ';

        while (!(*cur == '0' || (lastchar == ' ' && *cur == 'x')))
        {
            tmpBuffer += *cur;
            lastchar = *cur;
            cur++;
        }
        tmpBuffer.resize(tmpBuffer.size() - 1); // remove final space
        tmpBuffer.clear();

        if (*cur == 'x' || *cur == 'X')
        {
            resetValue = 0;
        } else 
        {
            bool hexFound = false;

            while(hexFound == false)
            {
                if( *cur == '\n' || *cur == 0)
                {
                    hexFound = true;
                }
                else if( (*cur == '0') && (*(cur+1)== 'x'))
                {
                    cur++;
                    hexFound = true;
                }
            }
            cur++;
            tmpBuffer += '0';
            while(*cur != ' ') {
                tmpBuffer += *cur;
                cur++;
            }
            STOUL_HEX(tmpBuffer, resetValue);
            tmpBuffer.clear();
        }
        cur++;

        while(*cur != '\n') {
            description += *cur;
            cur++;
        }
    }
}