#include "decimal.hpp"
#include "helper.hpp"

 std::string decimalToDecimal(const std::string& decimal){
     if(!is_number(decimal))
         return INVALID;
     else {
         std::string dec = decimal;
         formatDecimal(dec);
         return dec;
     }
}

 std::string binaryToDecimal(const std::string& binary){
    if(!is_binary(binary))
        return INVALID;
    else {
        std::string dec;
        if (is_zero(binary))
            dec = "0";
        else {
            dec = std::to_string(binaryToUInt(binary));
            formatDecimal(dec);
        }
        return dec;
    }
 }

 std::string asciiToDecimal(const std::string& ascii){
     if (!is_ascii(ascii))
         return INVALID;
     else
         return std::to_string(static_cast<int>(ascii[0]));
 }

 std::string hexToDecimal(const std::string& hex){
    if(!is_hex(hex))
        return INVALID;
    else {
        std::string dec = std::to_string(hexToUInt(hex));
        formatDecimal(dec);
        return dec;
    }
 }

std::string maxDecimalWithBits(const std::string& bits){
    if(!is_bits_valid(bits))
        return INVALID;
    else {
        std::string dec = std::to_string(bitsToMaxUInt(std::stoi(bits)));
        formatDecimal(dec);
        return dec;
    }
}

uint64_t bitsToMaxUInt(const int& bits){
    uint64_t num = 0;
    for(int i = 0; i < bits; i++){
        num = num << 1U;
        num = num | 1U;
    }
    return num;
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

 uint64_t binaryToUInt(const std::string& binary){
     uint64_t num = 0;
     int index = 0, size = binary.length();
     while (index < size) {
         num = num << 1U;
         if (binary[index] == '1')
             num = num | 1U;
         index++;
     }
     return num;
}
