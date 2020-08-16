
#include "register_bank.h"

struct RegisterBankImplementations
{
    explicit RegisterBankImplementations( 
                std::vector<std::pair<std::string,uint32_t> > hardware,
                std::string const bankName,
                std::string const description,
                const char * xilinxRegisterTxt,
                const char * xilinxFieldTxt) :
            hw(hardware),
            bank(bankName, description, xilinxRegisterTxt, xilinxFieldTxt)
    {
    }
    
    explicit RegisterBankImplementations(    
                std::string name,
                std::string description,
                uint32_t const address,
                const char * xilinxRegisterTxt,
                const char * xilinxFieldTxt) :
            bank(name, description, xilinxRegisterTxt, xilinxFieldTxt)
    {
        hw.emplace_back(name, address);
    }                             

    void GenerateRegisterStructures();
    void DumpFieldDefNoDescription();
    void LogRegisterBank();


    std::vector<std::pair<std::string,uint32_t> > hw;
    RegisterBank bank;
};
