#include "binary.hpp"
#include "helper.hpp"

std::string decimalToBinary(const std::string& str){
    if (!is_number(str))
        return INVALID;
    else {
        unsigned int value = std::stoul(str);
        std::string bin;
        if (is_zero(str))
            bin = str;
        else {
            while (value > 0) {
                if (value & 1U)
                    bin.insert(0, "1");
                else
                    bin.insert(0, "0");
                value = value >> 1U;
            }
        }
        formatBinary(bin);
        return bin;
    }
}
