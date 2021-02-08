#include "decimal.hpp"
#include "helper.hpp"

 std::string decimalToDecimal(const std::string& str){
     if(!is_number(str))
         return INVALID;
     else
         return str;
}

 std::string binaryToDecimal(const std::string& str){
    if(!is_binary(str))
        return INVALID;
    else {
        std::string dec;
        u_int64_t num = 0;
        if (is_zero(str))
            dec = str;
        else {
            int index = 0, size = str.length();
            while (index < size - 1) {
                if (str[index] == '1')
                    num = num | 1U;
                num = num << 1U;
                index++;
            }
            if (str[index] == '1')
                num = num | 1U;
            dec = std::to_string(num);
        }
        formatDecimal(dec);
        return dec;
    }
 }

 std::string asciiToDecimal(const std::string& str){
     if (str.empty())
         return INVALID;
     else
         return std::to_string(static_cast<int>(str[0]));
 }

 std::string hexToDecimal(const std::string& str){
    if(!is_hex(str))
        return INVALID;
    else
        return std::to_string(hexToUInt(str));
 }

 uint64_t hexToUInt(const std::string& str){
    u_int64_t num = 0;
    for(const char& c : str){
        if(std::isdigit(c))
            num = num | (c - 48U);
        else
            num = num | (c - 55U);
        num = num << 4U;
    }
    return num >> 4U;
 }
