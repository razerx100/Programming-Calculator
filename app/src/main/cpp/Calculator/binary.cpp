#include "binary.hpp"
#include "helper.hpp"
#include "decimal.hpp"

std::string decimalToBinary(const std::string& decimal){
    if (!is_number(decimal))
        return INVALID;
    else {
        std::string bin;
        if (is_zero(decimal))
            bin = "0";
        else {
            bin = uIntToBinary(std::stoul(decimal));
            formatBinary(bin);
        }
        return bin;
    }
}

std::string hexToBinary(const std::string& hex){
    if(!is_hex(hex))
        return INVALID;
    else {
        std::string bin = uIntToBinary(hexToUInt(hex));
        formatBinary(bin);
        return bin;
    }
}

std::string asciiToBinary(const std::string& ascii){
    if(!is_ascii(ascii))
        return INVALID;
    else {
        std::string bin = uIntToBinary(static_cast<uint64_t>(ascii[0]));
        formatBinary(bin);
        return bin;
    }
}

std::string binaryToBinary(const std::string& binary){
    if(!is_binary(binary))
        return INVALID;
    else {
        std::string bin = binary;
        formatBinary(bin);
        return bin;
    }
}

std::string maxBinaryWithBits(const std::string& bits){
    if(!is_bits_valid(bits))
        return INVALID;
    else {
        std::string bin = uIntToBinary(bitsToMaxUInt(std::stoi(bits)));
        formatBinary(bin);
        return bin;
    }
}

std::string uIntToBinary(const uint64_t& uInt){
    std::string bin;
    uint64_t value = uInt;
    while (value > 0) {
        if (value & 1U)
            bin.insert(0, "1");
        else
            bin.insert(0, "0");
        value = value >> 1U;
    }
    return bin;
}
