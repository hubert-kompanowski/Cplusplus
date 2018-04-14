//
// Created by hubert on 11.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H
#include <string>
#include <vector>

using namespace std;


namespace academia {
    class StudyYear{
    public:
        StudyYear();
        explicit StudyYear(int);

        explicit operator int();

        StudyYear operator++();
        StudyYear operator++(int);
        StudyYear operator--();
        StudyYear operator--(int);




    private:
        int year;
    };
    class Student{
    public:
        Student();
        Student(string,string,string,string,StudyYear);

        StudyYear GetYear();
        string Id();
        string FirstName();
        string LastName();
        string Program();
        StudyYear Year();
        void ChangeFirstName(string);
        void ChangeLastName(string);
        StudyYear year;
    private:
        string id;
        string first_name;
        string last_name;
        string program;

    };
    class StudentRepository {
    public:
        StudentRepository();
        StudentRepository(initializer_list<Student>);
        size_t StudentCount();
        Student&operator[](string);

    private:
        vector<Student> rep;
    };


    std::istream& operator>>(std::istream &is, StudyYear&);
    std::ostream& operator<<(std::ostream &is, StudyYear&);
}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
