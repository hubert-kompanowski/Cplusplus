//
// Created by hubert on 18.04.18.
//

#include <iostream>
#include "Name.h"

using namespace model;


Name::Name(const string &first_names_surname) {
    std::regex wzor{R"(([^ |\n|\t|\r]+)([ |\n|\t|\r]+)([^ |\n|\t|\r]*)([ |\n|\t|\r]*)([^ |\n|\t|\r]*)([ |\n|\t|\r]*)([^ |\n|\t|\r]*))"};

    std::__cxx11::smatch matches;

    if (std::regex_match(first_names_surname, matches, wzor)) {
        for(int i=1; i<=7; i+=2){
            if(matches[i]!=""){
                wektor.push_back(matches[i]);
            }
        }
    }
}

string Name::FirstName() const {
    return wektor.at(0);
}

optional<string> Name::SecondName() const {
    if(wektor.size() >= 3){
        return wektor.at(1);
    }
    return {};
}

optional<string> Name::ThirdName() const {
    if(wektor.size() == 4){
        return wektor.at(2);
    }
    return {};
}

string Name::Surname() const {
    return wektor.at(wektor.size()-1);
}

string Name::ToFullInitials() const {
    std::string result;

    for(auto s : wektor){
        result = result + s.at(0) + '.';

        if(s != Surname()){
            result += ' ';
        }

    }

    return result;
}

string Name::ToFirstNamesInitials() const {
    std::string result;
    std::string temp;

    for(auto s : wektor){
        if(s != Surname()){
            result = result + s.at(0) + ". ";
        } else {
            result += s;
        }
    }
    return result;
}

string Name::ToNamesSurname() const {
    std::string result;

    for(auto s : wektor){
        result = result + s;
        if(s != Surname()){
            result += ' ';
        }
    }

    return result;
}

string Name::ToSurnameNames() const {
    std::string result;
    result =  Surname();

    for(auto s : wektor){
        if(s != Surname()){
            result = result + " " + s;
        }
    }
    return result;
}

bool Name::IsBeforeBySurname(const Name &other) const {
    if(Surname() < other.Surname()){
        return true;
    }
    return false;
}

bool Name::IsBeforeByFirstName(const Name &other) const {
    if(FirstName() < other.FirstName()){
        return true;
    }
    return false;
}

