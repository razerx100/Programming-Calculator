#include "header/helper.hpp"
bool is_number(const std::string& str){
    return !str.empty() && std::find_if(str.begin(), str.end(), [](char c){return !std::isdigit(c);}) == str.end();
}

bool is_zero(const std::string& str){
    return std::find_if(str.begin(), str.end(), [](char c){return c != '0';}) == str.end();
}

void formatBinary(std::string& str){
    for(int i = str.length() - 4; i > 0; i -= 4)
        str.insert(i, " ");
}

void formatDecimal(std::string& str){
    for(int i = str.length() - 3; i > 0; i -= 3)
        str.insert(i, " ");
}
