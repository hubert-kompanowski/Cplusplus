//
// Created by hubert on 25.04.18.
//

#include <iostream>
#include <vector>
#include "Student.h"


int main(){

    std::string imie;
    std::string nazwisko;
    int wiek;
    std::string kierunek;

    std::vector<Student> wektor;

    while(true) {

        try{
        std::cin >> imie >> nazwisko >> wiek >> kierunek;
        Student student(imie, nazwisko, wiek, kierunek);
        wektor.push_back(student);
        }catch(const std::invalid_argument &e){
            std::cerr << e.what()<< std::endl;
        }

    }

}
