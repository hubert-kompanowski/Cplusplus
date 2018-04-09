//
// Created by hubert on 09.04.18.
//

#include <iostream>
#include "Matrix.h"
using namespace algebra;

int main(){

    Matrix m("[1i3 2i5 3; 3 4 5; 6 7 8]");


    Matrix m2("[3 2 1; 5 4 3; 7 6 5]");
    Matrix wynik = m.Add(m2);

    std::cout <<m2.Print();

}