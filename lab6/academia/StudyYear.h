//
// Created by hubert on 15.04.18.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H


#include <iostream>

using std::string;
namespace academia {


    int ReadNumber(std::istream* is);
    void CheckNextChar(char c, std::istream* is);

    class StudyYear {
    public:
        //metody klasy:
        StudyYear() : studyyear_(1) {};
        StudyYear(int yr) : studyyear_(yr) {};
        int GetYear() const;

        //przciążone operatory:
        StudyYear &operator++();
        StudyYear operator++(int);
        StudyYear &operator--();
        StudyYear operator--(int);

        operator int() const;
        friend std::istream &operator>>(std::istream &is, StudyYear howlongread);
    private:
        int studyyear_;
    }; //end of class

    bool operator>(const StudyYear oneman, const StudyYear otherman );
//    bool operator>=(const StudyYear oneman, const StudyYear otherman );
//    bool operator<(const StudyYear oneman, const StudyYear otherman );
//    bool operator<=(const StudyYear oneman, const StudyYear otherman );
    bool operator==(const StudyYear &a, const int b);
    bool operator==(const int b, const StudyYear &a);

    std::istream &operator>>(std::istream &is, StudyYear howlongread);
    std::ostream &operator<<(std::ostream &os, StudyYear howlong);



}


#endif //JIMP_EXERCISES_STUDYYEAR_H
