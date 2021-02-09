#ifndef __ASCII_HPP__
#define __ASCII_HPP__
#include <string>

std::string decimalToAscii(const std::string& decimal);
std::string asciiToAscii(const std::string& ascii);
std::string binaryToAscii(const std::string& binary);
std::string hexToAscii(const std::string& hex);

std::string maxAsciiWithBits(const std::string& bits);

#endif
