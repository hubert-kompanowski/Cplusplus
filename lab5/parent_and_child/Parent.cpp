//
// Created by hubert on 27.03.18.
//

#include "Parent.h"

#include "Child.h"

Parent::Parent(std::string i, std::string n, int w, std::string d) {
    imie = i;
    nazwisko = n;
    wiek = w;
    dziecko = d;
}

Parent::~Parent() {

}

void Parent::przepiszDoInnejSzkoly(std::string nazwa, Child &k) {
    k.szkola = nazwa;
}
