#ifndef __DECIMAL_HPP__
#define __DECIMAL_HPP__
#include <string>

std::string decimalToDecimal(const std::string& decimal);
std::string binaryToDecimal(const std::string& binary);
std::string asciiToDecimal(const std::string& ascii);
std::string hexToDecimal(const std::string& hex);

uint64_t hexToUInt(const std::string& hex);

#endif
