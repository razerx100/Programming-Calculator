#ifndef __HELPER_HPP__
#define __HELPER_HPP__
#include <string>
bool is_number(const std::string& str);
bool is_zero(const std::string& str);
bool is_binary(const std::string& str);
bool is_hex(const std::string& str);
bool is_ascii(const std::string& str);
bool is_bits_valid(const std::string& bits);

void formatBinary(std::string& binary);
void formatDecimal(std::string& decimal);

static std::string INVALID = "Invalid Input.";
#endif
