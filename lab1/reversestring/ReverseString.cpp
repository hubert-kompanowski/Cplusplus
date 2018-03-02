//
// Created by komphube on 27.02.18.
//

#include "ReverseString.h"

std::string reverse(std::string str) {
    const char *characters = str.c_str();
    std::string reversed_characters;
    size_t size = str.size();

    for(int i=0; i<size; i++){
        reversed_characters += characters[size-i-1];
    }

    return reversed_characters;
}
