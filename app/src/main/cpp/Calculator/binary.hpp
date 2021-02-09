#ifndef __BINARY_HPP__
#define __BINARY_HPP__
#include <string>

std::string decimalToBinary(const std::string& decimal);
std::string hexToBinary(const std::string& hex);
std::string asciiToBinary(const std::string& ascii);
std::string binaryToBinary(const std::string& binary);

std::string maxBinaryWithBits(const std::string& bits);

std::string uIntToBinary(const uint64_t& uInt);

#endif
