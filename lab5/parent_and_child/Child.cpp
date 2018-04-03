//
// Created by hubert on 27.03.18.
//

#include "Child.h"
#include "Parent.h"
#include <iostream>
Child::Child() {

}

Child::Child(std::string i, std::string n, int w, std::string s) {
    imie = i;
    nazwisko = n;
    wiek = w;
    szkola = s;
}

Child::~Child() {

}

void Child::wyswietl_dane() {
    std::cout << "Imie: " << imie<< std::endl;
    std::cout << "Nazwisko: " << nazwisko<< std::endl;
    std::cout << "Wiek: " << wiek<< std::endl;
    std::cout << "Szkoła: " << szkola<< std::endl;
    std::cout << "###" << std::endl;
}
