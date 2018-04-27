//
// Created by hubert on 20.03.18.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <iostream>
#include <cmath>

namespace geometry {

    class Point {
    public:
        Point();

        Point(double, double);

        ~Point();

        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;

        double GetX() const;

        double GetY() const;

    private:
        double x_, y_;
    };
}

#endif //JIMP_EXERCISES_POINT_H
