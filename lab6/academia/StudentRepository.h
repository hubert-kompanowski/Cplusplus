//
// Created by hubert on 11.04.18.
//


#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H


#include <set>
#include <initializer_list>
#include <vector>
#include <string>
#include <memory>
#include "Student.h"

namespace academia {
    class Query {
    public:
        virtual bool Accept(const Student &student) const =0;
    };


    class StudentRepository {
    public:
        StudentRepository(std::initializer_list<Student> in);
        void AddStudent(Student &in);
        void RemoveStudent(Student out);
        void RemoveStudent(std::string outbyid);
        int StudentCount() const;

//        std::vector<Student> FindByQuery(const Query &query);
        std::vector<Student> FindByQuery(const std::unique_ptr<Query> &query);

        std::vector<Student> get() const;

        Student &operator[]( const std::string &searchforid);

        friend bool operator==(const StudentRepository &firstrep,  const StudentRepository &secondrep);
    private:
        std::vector<Student> studentcontainer_;

    };

    bool operator==(const StudentRepository &firstrep, const StudentRepository &secondrep);
    std::ostream &operator<<(std::ostream &os, StudentRepository stdrep);
}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
