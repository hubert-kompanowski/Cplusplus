//
// Created by hubert on 18.03.18.
//

#include "Square.h"
#include "Point.h"

using namespace geometry;

Square::Square(Point &a, Point &b, Point &c, Point &d){
    p1=a;
    p2=b;
    p3=c;
    p4=d;
}

bool Square::is_square(){
    double d1, d2, d3, d4;
    d1 = p1.Distance(p2);
    d2 = p2.Distance(p4);
    d3 = p4.Distance(p3);
    d4 = p3.Distance(p1);
    if(d1 == d2 && d3 == d4 && d2 == d3){
        return true;
    }
    return false;
}

double Square::Circumference(){
    if(!is_square()){
        return 0.0;
    }
    return p1.Distance(p2)*4;
}

double Square::Area(){
    if(!is_square()){
        return 0.0;
    }
    return p1.Distance(p2)*p1.Distance(p2);
}
