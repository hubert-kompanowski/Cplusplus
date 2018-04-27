//
// Created by hubert on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H
#include <stdexcept>
#include <iostream>
#include <sstream>

namespace academia {

    class AcademiaDataValidationError : public std::runtime_error{
    public:
        AcademiaDataValidationError(std::string a):runtime_error(a){
            invalid_argument_= a;
        }
    private:
        std::string invalid_argument_;
    };


    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const std::string &pesel, int checksum): AcademiaDataValidationError("Invalid PESEL("+pesel+") checksum: "+std::to_string(checksum)){}
    private:
        std::string pesel_;
    };


    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string pesel, int length): AcademiaDataValidationError("Invalid PESEL("+pesel+") length: "+std::to_string(length)){}
    private:
        std::string pesel_;
    };


    class InvalidPeselCharacter:public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(std::string pesel): AcademiaDataValidationError("Invalid PESEL("+pesel+") character set"){}
    private:
        std::string pesel_;
    };


    class Pesel {
    public:
        Pesel(std::string);
        void validatePESEL(std::string);
    private:
        std::string pesel_;
    };
}
#endif //JIMP_EXERCISES_PESEL_H
