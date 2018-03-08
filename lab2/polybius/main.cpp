//
// Created by hubert on 08.03.18.
//

#include <iostream>
#include "Polybius.h"



int main(int argc, char argv[]){

    std::string wiad = "hubert";

    std::string szyfr = PolybiusCrypt(wiad);

    std::cout << szyfr;

}