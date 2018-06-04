//
// Created by hubert on 04.06.18.
//

#include "TeacherHash.h"

using namespace academia;

TeacherId::TeacherId(int i){
    id = i;
}

TeacherId::operator int()const {
    return id;
}

Teacher::Teacher(TeacherId i, std::string n, std::string d) : id(i){
    name = std::move(n);
    department = std::move(d);
}

TeacherId Teacher::Id() const{
    return id;
}

std::string Teacher::Name()const {
    return name;
}

std::string Teacher::Department()const{
    return department;
}

size_t TeacherHash::operator()(Teacher t) const{
    std::hash <std::string> StringHash;
    std::hash <int> IntHash;
    return IntHash(t.Id()) << StringHash(t.Department()) + StringHash(t.Name());
}

bool TeacherId::operator!=(const TeacherId& other) const{
    return (int)(*this) != (int)(other);
}

bool Teacher::operator!=(const Teacher& other)const{
    return Id() != other.Id() || Name() != other.Name() || Department() != other.Department();
}

bool Teacher::operator==(const Teacher& other)const{
    return Id() == other.Id() && Name() == other.Name() && Department() == other.Department();
}