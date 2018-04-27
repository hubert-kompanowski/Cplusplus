//
// Created by hubert on 15.04.18.
//

#include "Comparable.h"

using namespace academia;


bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) {
    if(left.FirstName() < right.FirstName()){
        return true;
    }
    return false;
}

bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) {
    if(left.FirstName() > right.FirstName()){
        return true;
    }
    return false;
}

bool ByLastNameAscending::IsLess(const Student &left, const Student &right) {
    if(left.LastName() < right.LastName()){
        return true;
    }
    return false;
}

bool ByProgramAscendingEmptyFirst::IsLess(const Student &left, const Student &right) {
    if(left.Program().size() == 0){
        return true;
    }
    if(right.Program().size() == 0){
        return false;
    }
    if(left.Program() < right.Program()){
        return true;
    }
    return false;
}

bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) {
    if(left.Program().size() == 0){
        return false;
    }
    if(right.Program().size() == 0){
        return true;
    }
    if(left.Program() < right.Program()){
        return true;
    }
    return false;
}

bool StudentComparator::operator()(const Student &left, const Student &right) {
    return this->IsLess(left, right);
}