//
// Created by hubert on 14.04.18.
//

#include <iostream>
#include "ArrayFill.h"
using namespace arrays;

int main(){
    std::vector<int> vs;
    FillArray(1024, UniformFill {77}, &vs);

    for(auto v : vs){
        std::cout << v << "  ";
    }
}