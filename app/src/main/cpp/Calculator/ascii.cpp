#include "ascii.hpp"
#include "helper.hpp"
#include "decimal.hpp"

std::string decimalToAscii(const std::string& decimal){
    if(!is_number(decimal))
        return INVALID;
    else
        return std::string(1, static_cast<char>(std::stoi(decimal)));
}
std::string asciiToAscii(const std::string& ascii){
    if(!is_ascii(ascii))
        return INVALID;
    else
        return ascii;
}
std::string binaryToAscii(const std::string& binary){
    if(!is_binary(binary))
        return INVALID;
    else
        return std::string(1, static_cast<char>(binaryToUInt(binary)));
}
std::string hexToAscii(const std::string& hex){
    if(!is_hex(hex))
        return INVALID;
    else
        return std::string(1, static_cast<char>(hexToUInt(hex)));
}
std::string maxAsciiWithBits(const std::string& bits){
    return std::string("Illogical request.");
}
