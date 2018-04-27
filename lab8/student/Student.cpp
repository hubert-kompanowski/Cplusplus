//
// Created by hubert on 25.04.18.
//

#include "Student.h"
#include <vector>

bool IsCOrrectNameSurname(std::string imie, std::string nazwisko){
    if(imie.at(0)< 65 || imie.at(0) > 90){
        return true;
    }
    if(imie == "" || nazwisko == ""){
        return true;
    }

    bool flaga = true;
    for(char c : imie){
        if(flaga){
            flaga = false;
            continue;
        }
        if(c<97 || c>122){
            return true;
        }
    }
}

Student::Student(std::string i, std::string n, int w, std::string k) {

    if(IsCOrrectNameSurname(i,n)){
        throw InvalidNameSurname(i, n);
    }

    if(w <10 || w > 100){
        throw InvalidAge(w);
    }

    std::vector<std::string> kier = {"informatyka", "ekonomia", "matematyka", "fizyka", "filozofia"};
    bool is_correct = false;
    for(std::string c : kier){
        if(k == c){
            is_correct = true;
        }
    }
    if(!is_correct){
        throw InvalidProgram(k);
    }
    
    imie = i;
    nazwisko = n;
    wiek = w;
    kierunek = k;

}