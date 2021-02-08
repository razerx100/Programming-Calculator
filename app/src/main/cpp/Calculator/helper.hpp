#ifndef __HELPER_HPP__
#define __HELPER_HPP__
#include <string>
bool is_number(const std::string& str);
bool is_zero(const std::string& str);
bool is_binary(const std::string& str);
bool is_hex(const std::string& str);

void formatBinary(std::string& str);
void formatDecimal(std::string& str);

static std::string INVALID = "Invalid Input.";
#endif
