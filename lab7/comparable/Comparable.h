//
// Created by hubert on 15.04.18.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include <string>
#include <StudentRepository.h>

using std::string;

namespace academia {

    //klasa abstrakcyjna
    class StudentComparator {
    public:
        virtual bool IsLess(const Student &left, const Student &right) = 0;
        bool operator()(const Student &left, const Student &right);
    };

    class ByFirstNameAscending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right);
    };

    class ByFirstNameDescending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right);
    };

    class ByLastNameAscending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right);
    };

    class ByProgramAscendingEmptyFirst : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right);
    };

    class ByProgramAscendingEmptyLast : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right);
    };


}
#endif //JIMP_EXERCISES_COMPARABLE_H
