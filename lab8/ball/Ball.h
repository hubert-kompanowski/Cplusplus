//
// Created by hubert on 25.04.18.
//

#ifndef JIMP_EXERCISES_BALL_H
#define JIMP_EXERCISES_BALL_H


#include <iostream>
using namespace std;

class CircleException{
public:
    CircleException(){}
};

class BallException : public CircleException{
public:
    BallException(){}
};

void drawBall();


#endif //JIMP_EXERCISES_BALL_H






/*
 *
 *
 * w main()

 try{

    metoda z obsługą wyjątku z invalid_arg

 }catch(const invalid_argument &e){
    cerr << e.what() << endl;
 }

 */
