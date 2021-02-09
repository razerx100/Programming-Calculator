#include "hex.hpp"
#include "helper.hpp"
#include "decimal.hpp"

std::string decimalToHex(const std::string& decimal){
    if(!is_number(decimal))
        return INVALID;
    else
        return uIntToHex(std::stoul(decimal));
}

std::string asciiToHex(const std::string& ascii) {
    if (!is_ascii(ascii))
        return INVALID;
    else
        return uIntToHex(static_cast<uint64_t>(ascii[0]));
}

std::string binaryToHex(const std::string& binary){
    if(!is_binary(binary))
        return INVALID;
    else {
        int extra = binary.length() % 4;
        std::string hex;
        int i = ((extra) ? extra : 4);
        hex.append(uIntDigitToHex(binaryToUInt(binary.substr(0, i))));
        for (; i < binary.length(); i += 4) {
            hex.append(uIntDigitToHex(binaryToUInt(binary.substr(i, 4))));
        }
        return hex;
    }
}

std::string hexToHex(const std::string& hex){
    if(!is_hex(hex))
        return INVALID;
    else
        return hex;
}

std::string maxHexWithBits(const std::string& bits){
    if(!is_bits_valid(bits))
        return INVALID;
    else
        return uIntToHex(bitsToMaxUInt(std::stoi(bits)));
}

std::string uIntToHex(const uint64_t & uInt){
    uint64_t num = uInt;
    std::string hex;
    if(num == 0)
        hex = "0";
    else {
        while (num > 0) {
            uint8_t fourBit = 15;
            fourBit = fourBit & num;
            hex.insert(0, uIntDigitToHex(fourBit));
            num = num >> 4U;
        }
    }
    return hex;
}

std::string uIntDigitToHex(const uint64_t & uInt){
    return std::string (1, static_cast<char>((uInt < 10) ? uInt + 48 : uInt + 55));
}
