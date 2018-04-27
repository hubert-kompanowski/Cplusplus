//
// Created by hubert on 15.04.18.
//

#include "Student.h"

namespace academia {
    Student::Student() {}

    bool IsCorrectFi

    Student::Student(std::string id, std::string first_name, std::string last_name, std::string program,
                     StudyYear year) {


        id_ = id;
        first_name_ = first_name;
        last_name_ = last_name;
        program_ = program;
        year_ = year.GetYear();
    }

    std::string Student::Id() const {
        return id_;
    }

    std::string Student::FirstName() const {
        return first_name_;
    }

    std::string Student::LastName() const {
        return last_name_;
    }

    std::string Student::Program() const {
        return program_;
    }

    int Student::Year() const {
        return year_.GetYear();
    }


    void Student::ChangeId(std::string id) {
        id_ = id;
    }

    void Student::ChangeFirstName(std::string first_name) {
        first_name_ = first_name;
    }

    void Student::ChangeLastName(std::string last_name) {
        last_name_ = last_name;
    }

    void Student::ChangeProgram(std::string program) {
        program_ = program;
    }

    void Student::ChangeYear(const StudyYear &year) {
        year_ = year;
    }

    std::istream &operator>>(std::istream &is, Student &student) {
        is>>student.id_>>student.first_name_>>student.last_name_>>student.program_>>student.year_;
    }

    std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Id: "<<student.Id();
        os << "First name: "<<student.FirstName();
        os << "Lastname: "<<student.LastName();
        os << "Program: "<<student.Program();
        os << "Year: "<<student.Year();
    }

    bool operator==(const Student &a, const Student &b) {
        if (a.Id() == b.Id())
            return true;
        return false;
    }

    bool operator<(const Student &a, const Student &b) {
        if (a.Id() < b.Id())
            return true;
        return false;
    }


}