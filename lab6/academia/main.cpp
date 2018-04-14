//
// Created by hubert on 11.04.18.
//

#include <iostream>
#include "StudentRepository.h"

using namespace academia;


int main(){


    StudyYear year(1);
    Student student("24334", "Hubert", "Kompanowski", "Informatyka", year);
    year++;

    ++year;

    year--;
    --year;


    std::cout << student.year;




}