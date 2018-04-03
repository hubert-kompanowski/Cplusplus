//
// Created by hubert on 25.03.18.
//

#ifndef JIMP_EXERCISES_XXX_H
#define JIMP_EXERCISES_XXX_H


#include <string>
#include <cstring>
#include <algorithm>
using ::std::swap;



class XXX {
public:
    //domyślny konstruktor
    XXX();
    XXX(int param);
    XXX(const std::string name);

    //Rule of five://
    //1. konstruktor kopiujący
    XXX(const XXX &xxx);
    //2. konstruktor przenoszący
    XXX(XXX &&xxx);
    //3. operator przypisania kopiujący
    XXX &operator=(const XXX &xxx);
    //4. operator przypisania przenoszący
    XXX &operator=(XXX &&xxx);
    //5. Destruktor
    ~XXX();

private:
    char* name_;
};

#endif //JIMP_EXERCISES_XXX_H
