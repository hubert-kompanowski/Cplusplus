//
// Created by hubert on 13.03.18.
//


#include <iostream>
#include "TinyUrl.h"

using tinyurl::NextHash;

int main(){

    std::array<char, 6> tmp = {'0','0','0', '0', '0', '0'};

    NextHash(&tmp);
}