#ifndef __DECIMAL_HPP__
#define __DECIMAL_HPP__
#include <string>

std::string decimalToDecimal(const std::string& str);
std::string binaryToDecimal(const std::string& str);
std::string asciiToDecimal(const std::string& str);
std::string hexToDecimal(const std::string& str);
uint64_t hexToUInt(const std::string& str);

#endif
