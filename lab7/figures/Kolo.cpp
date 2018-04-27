//
// Created by hubert on 15.04.18.
//

#include "Kolo.h"

double Kolo::Pole() {
    return M_PI * pow(r_,2);
}

double Kolo::getX() const {
    return x_;
}

double Kolo::getY() const {
    return y_;
}

double Kolo::getR() const {
    return r_;
}