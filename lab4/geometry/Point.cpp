//
// Created by hubert on 20.03.18.
//

#include "Point.h"

using namespace geometry;

Point::Point() {
}

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
}

Point::~Point() {
}

void Point::ToString(std::ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

double Point::GetX() const{
    return x_;
}
double Point::GetY() const{
    return y_;
}
