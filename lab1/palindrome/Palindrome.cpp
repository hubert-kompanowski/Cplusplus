//
// Created by hubert on 02.03.18.
//

#include "Palindrome.h"


bool is_palindrome(std::string str){
    size_t size = str.length();
    const char *characters = str.c_str();
    if(size<=1) {
        return true;
    }

    for(int i=0; i<size/2; i++) {
        if(characters[i] != characters[size-1-i]) {
            return false;
        }
    }
    return true;
}
