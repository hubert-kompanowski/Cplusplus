//
// Created by hubert on 15.04.18.
//

#include "Worker.h"
#include <iostream>

int main(){
    UmowaDzielo x(3200.23);
    Pracownik a("Marek", "Nowak", "0000", &x);
    UmowaPraca y(3200.23);
    Pracownik b("Adam", "Kowalski", "1111", &y);
    std::cout<<"1.: "<<a<<std::endl;
    std::cout<<"2.: "<<b<<std::endl;
    std::cout<<"1 zarabia: "<<a.pobierzPensje()<<std::endl;
    std::cout<<"2 zarabia: "<<b.pobierzPensje()<<std::endl;
}