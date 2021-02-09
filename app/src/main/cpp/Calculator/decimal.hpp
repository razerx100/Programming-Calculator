#ifndef __DECIMAL_HPP__
#define __DECIMAL_HPP__
#include <string>

std::string decimalToDecimal(const std::string& decimal);
std::string binaryToDecimal(const std::string& binary);
std::string asciiToDecimal(const std::string& ascii);
std::string hexToDecimal(const std::string& hex);

std::string maxDecimalWithBits(const std::string& bits);

uint64_t hexToUInt(const std::string& hex);
uint64_t binaryToUInt(const std::string& binary);
uint64_t bitsToMaxUInt(const int& bits);

#endif
