#include "hex.hpp"
#include "helper.hpp"


std::string decimalToHex(const std::string& decimal){
    if(!is_number(decimal))
        return INVALID;
    else
        return uIntToHex(decimal);
}

std::string uIntToHex(const std::string& uInt){
    uint64_t num = std::stoul(uInt);
    std::string hex;
    while(num > 0){
        uint8_t fourBit = 15;
        fourBit = fourBit & num;
        if(fourBit < 10)
            hex.insert(0, std::string(1,static_cast<char>(fourBit + 48)));
        else
            hex.insert(0, std::string(1,static_cast<char>(fourBit + 55)));
        num = num >> 4U;
    }
    return hex;
}

std::string asciiToHex(const std::string& ascii){
    if(ascii.empty())
        return INVALID;
    else
        return uIntToHex(std::to_string(static_cast<int>(ascii[0])));
}
