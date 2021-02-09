#ifndef __HEX_HPP__
#define __HEX_HPP__
#include <string>

std::string decimalToHex(const std::string& decimal);
std::string asciiToHex(const std::string& ascii);
std::string binaryToHex(const std::string& binary);
std::string hexToHex(const std::string& hex);

std::string maxHexWithBits(const std::string& bits);

std::string uIntToHex(const uint64_t & uInt);
std::string uIntDigitToHex(const uint64_t& uInt);

#endif
