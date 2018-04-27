//
// Created by hubert on 15.04.18.
//

#include "StudyYear.h"


namespace academia {

    int ReadNumber(std::istream* is) {
        int d;
        (*is) >> d;
        return d;
    }

    void CheckNextChar(char c, std::istream* is) {
        int next_char = is->peek();
        if (next_char != c) {
            throw std::runtime_error("invalid character");
        }
        is->ignore();
    }



    int StudyYear::GetYear() const { return studyyear_; }

    StudyYear &StudyYear::operator++(){
        ++studyyear_;
    }
    StudyYear StudyYear::operator++(int){
        studyyear_++;
    }
    StudyYear &StudyYear::operator--(){
        if (studyyear_>0)
            --studyyear_;
    }
    StudyYear StudyYear::operator--(int){
        if (studyyear_>0)
            studyyear_--;
    }

    bool operator>(const StudyYear oneman, const StudyYear otherman ){
        return (oneman.GetYear()>otherman.GetYear());
    }
//    bool operator>=(const StudyYear oneman, const StudyYear otherman ){
//        return (oneman.GetYear()>=otherman.GetYear());
//    }
    bool operator<(const StudyYear oneman, const StudyYear otherman ){
        return (oneman.GetYear()<otherman.GetYear());
    }
//    bool operator<=(const StudyYear oneman, const StudyYear otherman ){
//        return (oneman.GetYear()<=otherman.GetYear());
//    }
    bool operator==(const StudyYear &a, const int b) {
        if (a.GetYear() == b)
            return true;
        return false;
    }

    bool operator==(const int b, const StudyYear &a) {
        if (a.GetYear() == b)
            return true;
        return false;
    }

    std::istream &operator>>(std::istream &is, StudyYear howlongread){
        is>>howlongread.studyyear_;
        return is;
    }
    std::ostream &operator<<(std::ostream &os, StudyYear howlong) {
        os << howlong.GetYear();
    }
    StudyYear::operator int() const {
        return studyyear_;
    }

}