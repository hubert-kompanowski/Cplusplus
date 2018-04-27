//
// Created by hubert on 15.04.18.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


#include <cmath>

class Kolo {
public:
    Kolo(double x=0, double y=0, double r=0): x_(x), y_(y), r_(r){};
    double Pole();
    double getX() const;
    double getY() const;
    double getR() const;

private:
    double x_,y_,r_;
};



#endif //JIMP_EXERCISES_KOLO_H
