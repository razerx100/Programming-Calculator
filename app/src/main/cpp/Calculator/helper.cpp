#include "helper.hpp"

bool hex_table[128] = {
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, true, true,
        true, true, true, true, true, true, true, true, false, false,
        false, false, false, false, false, true, true, true, true, true,
        true, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false
};

bool is_number(const std::string& str){
    return !str.empty() and std::find_if(str.begin(), str.end(), [](char c){return !std::isdigit(c);}) == str.end();
}

bool is_zero(const std::string& str){
    return std::find_if(str.begin(), str.end(), [](char c){return c != '0';}) == str.end();
}

bool is_binary(const std::string& str){
    return !str.empty() and std::find_if(str.begin(), str.end(), [](char c){return c != '1' and c != '0';}) == str.end();
}

bool is_hex(const std::string& str){
    return !str.empty() and std::find_if(str.begin(), str.end(),[](char c){return !hex_table[c];}) == str.end();
}

void formatBinary(std::string& str){
    for(int i = str.length() - 4; i > 0; i -= 4)
        str.insert(i, " ");
}

void formatDecimal(std::string& str){
    for(int i = str.length() - 3; i > 0; i -= 3)
        str.insert(i, " ");
}
