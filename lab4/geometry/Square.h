//
// Created by hubert on 18.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <iostream>
#include <cmath>
#include "Point.h"

namespace geometry {

    class Square {
    private:
        Point p1;
        Point p2;
        Point p3;
        Point p4;

    public:
        bool is_square();
        Square(Point &, Point &, Point &, Point &);
        double Circumference();
        double Area();
    };

}
#endif //JIMP_EXERCISES_SQUARE_H
