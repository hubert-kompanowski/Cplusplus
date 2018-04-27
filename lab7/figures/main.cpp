//
// Created by hubert on 15.04.18.
//

#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main(){
    Kula k(0,0,0,10);
    Kolo ko(0,0,4);
    std::cout<<"Wspolrzędne kola: "<<"X: "<<ko.getX()<<" Y: "<<ko.getY()<<" R: "<<ko.getR()<<std::endl;
    std::cout<<"Wspolrzędne kuli: "<<"X: "<<k.getX()<<" Y: "<<k.getY()<<" R: "<<k.getR()<<" Z: "<<k.getZ()
             <<std::endl;
    std::cout<<"Pole kola: "<<ko.Pole()<<std::endl;
    std::cout<<"Pole kuli: "<<k.Pole()<<std::endl;

    std::cout << k.Kolo::Pole();
}