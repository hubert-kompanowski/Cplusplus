//
// Created by hubert on 11.04.18.
//

#include "StudentRepository.h"
using namespace academia;

StudyYear::StudyYear():year(1){}
StudyYear::StudyYear(int a):year(a){}

StudyYear StudyYear::operator++(int){
    year++;
}
StudyYear StudyYear::operator++(){
    year++;
}
StudyYear StudyYear::operator--(){
    year--;
}
StudyYear StudyYear::operator--(int){
    year--;
}




StudyYear::operator int(){
    return year;
}
Student::Student(string a,string b ,string c,string d,StudyYear e):id(a),first_name(b),last_name(c),program(d),year(e){}

StudentRepository::StudentRepository(){}
StudentRepository::StudentRepository(initializer_list<Student> list){
    for(auto pointer = list.begin();pointer!=list.end();pointer++) {
        rep.emplace_back(*pointer);
    }
}

StudyYear Student::GetYear() {
    return this->year;
}

void Student::ChangeFirstName(string temp){
    first_name=temp;
}
void Student::ChangeLastName(string temp) {
    last_name = temp;
}
string Student::Id(){
    return id;
}
string Student::FirstName(){
    return first_name;
}

string Student::LastName() {
    return last_name;
}

string Student::Program() {
    return program;
}

StudyYear Student::Year() {
    return year;
}

size_t StudentRepository::StudentCount(){
    return rep.size();
}
Student& StudentRepository::operator[](string id){
    for(int a =0; a<StudentCount();a++ ) {
        if(rep[a].Id()==id) {
            return rep[a];
        }
    }

}





istream& operator>>(istream & input, Student& p){

    input >> p.year;
    return input;
}

ostream& operator<<(ostream & output, Student& p){

    output << p.year;
    return output;
}

/*
 *
 *
 *
 */