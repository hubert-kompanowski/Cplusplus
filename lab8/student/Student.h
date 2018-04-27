//
// Created by hubert on 25.04.18.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include <string>
#include <stdexcept>

class Student {
public:
    Student(std::string, std::string, int, std::string);

private:
    std::string imie;
    std::string nazwisko;
    int wiek;
    std::string kierunek;
};

class InvalidNameSurname : public std::invalid_argument{
public:
    InvalidNameSurname(std::string n, std::string s) : invalid_argument("Invalid Name Surname"){
        imie = n;
        nazwisko = s;
    }
private:
    std::string imie;
    std::string nazwisko;
};


class InvalidAge : public std::invalid_argument{
public:
    InvalidAge(int x) : invalid_argument("Invalid Age"){
        wiek = x;
    }
private:
    int wiek;
};


class InvalidProgram : public std::invalid_argument{
public:
    InvalidProgram(std::string p) : invalid_argument("Invalid Program"){
        program = p;
    }
private:
    std::string program;
};




#endif //JIMP_EXERCISES_STUDENT_H
