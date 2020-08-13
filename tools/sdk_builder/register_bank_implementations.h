
#include "register_bank.h"

struct RegisterBankImplementations
{
    explicit RegisterBankImplementations( 
                std::vector<std::pair<std::string,uint32_t> > hardware,
                std::string bankName,
                const char * xilinxRegisterTxt,
                const char * xilinxFieldTxt) :
            hw(hardware),
            bank(bankName, xilinxRegisterTxt, xilinxFieldTxt)
    {
    }
    
    explicit RegisterBankImplementations(    
                std::string const & name,
                uint32_t address,
                const char * xilinxRegisterTxt,
                const char * xilinxFieldTxt) :
            bank(name, xilinxRegisterTxt, xilinxFieldTxt)
    {
        hw.emplace_back(name, address);
    }                             

    void GenerateRegisterStructures();
    void DumpFieldDefNoDescription();
    void LogRegisterBank();


    std::vector<std::pair<std::string,uint32_t> > hw;
    RegisterBank bank;
};
