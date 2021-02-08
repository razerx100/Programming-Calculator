#include "binary.hpp"
#include "helper.hpp"

std::string decimalToBinary(const std::string& decimal){
    if (!is_number(decimal))
        return INVALID;
    else {
        unsigned int value = std::stoul(decimal);
        std::string bin;
        if (is_zero(decimal))
            bin = decimal;
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
