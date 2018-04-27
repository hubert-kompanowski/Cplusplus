//
// Created by komphube on 27.02.18.
//
#include <string>
#include "ReverseString.h"

std::string Reverse(std::string str) {
    std::string results;
    for(char c : str){
        results = c + results;
    }
    return results;
}
