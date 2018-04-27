//
// Created by hubert on 15.04.18.
//
#include <string>
#include <vector>
#include <initializer_list>
#include "StudyYear.h"
#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

namespace academia {

    class Student {
    public:
        Student();
        Student(std::string id, std::string first_name, std::string last_name, std::string program, StudyYear year);


        std::string Id()const;
        std::string FirstName()const;
        std::string LastName()const;
        std::string Program()const;
        int Year()const;

        void ChangeId(std::string id);
        void ChangeFirstName(std::string first_name);
        void ChangeLastName(std::string last_name);
        void ChangeProgram(std::string program);
        void ChangeYear(const StudyYear &year);



        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;



    };
    bool operator==(const Student &a , const Student &b);
    bool operator<(const Student &a , const Student &b);
    std::ostream &operator<<(std::ostream &os, const Student &student) ;
    std::istream &operator>>(std::istream &is, Student &student);

    class
}


#endif //JIMP_EXERCISES_STUDENT_H
