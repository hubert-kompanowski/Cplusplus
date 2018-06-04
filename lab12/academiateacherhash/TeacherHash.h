//
// Created by hubert on 04.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H


#include <string>
#include <utility>


namespace academia {
    class TeacherId{
    public:
        TeacherId(int);
        operator int() const;
        bool operator!=(const TeacherId& other) const;
    private:
        int id;
    };
    class Teacher{
    public:
        Teacher(TeacherId i, std::string n, std::string d);
        TeacherId Id() const;
        std::string Name() const;
        std::string Department() const;
        bool operator!=(const Teacher& other)const;
        bool operator==(const Teacher& other)const;
    private:
        TeacherId id;
        std::string name;
        std::string department;
    };
    class TeacherHash {
    public:
        TeacherHash()= default;
        size_t operator()(Teacher) const;
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
