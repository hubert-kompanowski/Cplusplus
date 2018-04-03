//
// Created by hubert on 27.03.18.
//

#ifndef JIMP_EXERCISES_CHILD_H
#define JIMP_EXERCISES_CHILD_H

#include "Parent.h"
#include <string>

class Child {
public:
    Child();
    Child(std::string, std::string, int, std::string = "AGH");
    ~Child();
    friend class Parent;
    void wyswietl_dane();

private:
    std::string imie;
    std::string nazwisko;
    int wiek;
    std::string szkola;
};


#endif //JIMP_EXERCISES_CHILD_H
