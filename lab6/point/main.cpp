//
// Created by hubert on 11.04.18.
//

#include "Point.h"
#include <iomanip>
#include <iostream>
using ::std::istream;


int main(){

    Point punkt;

    std::cin >> punkt;

    std::stringstream d;
    d << punkt;

    std::cout << punkt;

}