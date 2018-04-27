//
// Created by hubert on 15.04.18.
//

#include "Kula.h"

#include "Kula.h"

double Kula::Pole() {
    return 4/3*M_PI*pow(getR(),3);
}

double Kula::getZ() const {
    return z_;
}