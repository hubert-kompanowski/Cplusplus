//
// Created by hubert on 15.04.18.
//

#include "StudentRepositoryQueries.h"

using namespace academia;

ByFirstName::~ByFirstName() {
    delete[] &firstname_;
}

bool ByFirstName::Accept(const Student &student) const {
    if(student.FirstName() == firstname_){
        return true;
    }
    return false;
}


bool ByLastName::Accept(const Student &student) const {
    if(student.LastName() == lastname_){
        return true;
    }
    return false;
}


bool ByOneOfPrograms::Accept(const Student &student) const {
    for(auto i : program_){
        if(i==student.Program()) return true;
    }
    return false;
}

bool ByYearLowerOrEqualTo::Accept(const Student &student) const {
    if(student.Year() <= year_){
        return true;
    }
    return false;
}

bool OrQuery::Accept(const Student &student) const {
    return a_->Accept(student) || b_->Accept(student);
}

bool AndQuery::Accept(const Student &student) const {
    return a_->Accept(student) && b_->Accept(student);
}
