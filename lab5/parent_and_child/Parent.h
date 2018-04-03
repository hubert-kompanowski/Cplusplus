//
// Created by hubert on 27.03.18.
//

#ifndef JIMP_EXERCISES_PARENT_H
#define JIMP_EXERCISES_PARENT_H

#include <string>
#include "Child.h"

class Child;

class Parent {

public:
    Parent(std::string, std::string, int, std::string);
    ~Parent();
    void przepiszDoInnejSzkoly(std::string, Child &k);


private:
    std::string imie;
    std::string nazwisko;
    int wiek;
    std::string dziecko;
};


#endif //JIMP_EXERCISES_PARENT_H
