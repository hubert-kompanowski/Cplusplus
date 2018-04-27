//
// Created by hubert on 25.04.18.
//

#include "Ball.h"

int main(){
    try{
        drawBall();
    }catch(const BallException &b){
        cout << "Blad podczas rysowania kuli" << endl;
    } catch(const CircleException &a){
        cout << "Blad podczas rysowania kola" << endl;
    }

}