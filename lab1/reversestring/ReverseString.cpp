//
// Created by komphube on 27.02.18.
//
#include <string>
#include "ReverseString.h"

std::string Reverse(std::string str) {
    size_t size = str.length();
    std::string reversed_characters;

    if(size <= 1){
        return str;
    }

    char last_character = str[size-1];
    str.erase((size-1), 1);
    reversed_characters = last_character + Reverse(str);
    return std::string(reversed_characters);
    }
