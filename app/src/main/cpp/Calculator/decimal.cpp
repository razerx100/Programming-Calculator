#include "decimal.hpp"
#include "helper.hpp"

 std::string decimalToDecimal(const std::string& decimal){
     if(!is_number(decimal))
         return INVALID;
     else
         return decimal;
}

 std::string binaryToDecimal(const std::string& binary){
    if(!is_binary(binary))
        return INVALID;
    else {
        std::string dec;
        u_int64_t num = 0;
        if (is_zero(binary))
            dec = binary;
        else {
            int index = 0, size = binary.length();
            while (index < size) {
                num = num << 1U;
                if (binary[index] == '1')
                    num = num | 1U;
                index++;
            }
            dec = std::to_string(num);
        }
        formatDecimal(dec);
        return dec;
    }
 }

 std::string asciiToDecimal(const std::string& ascii){
     if (ascii.empty())
         return INVALID;
     else
         return std::to_string(static_cast<int>(ascii[0]));
 }

 std::string hexToDecimal(const std::string& hex){
    if(!is_hex(hex))
        return INVALID;
    else
        return std::to_string(hexToUInt(hex));
 }

 uint64_t hexToUInt(const std::string& hex){
    u_int64_t num = 0;
    for(const char& c : hex){
        num = num << 4U;
        if(std::isdigit(c))
            num = num | (c - 48U);
        else
            num = num | (c - 55U);
    }
    return num;
 }
