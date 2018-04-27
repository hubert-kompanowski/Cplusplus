//
// Created by hubert on 15.04.18.
//

#include <iostream>
using namespace std;

class LiczbaRzeczywista{
protected:
    double re;
public:
    LiczbaRzeczywista(double r){re=r;}
    virtual void wypisz(){
        cout << re << endl;
    }
    void powitaj(){
        cout << "Czesc!" << endl;
    }

    LiczbaRzeczywista operator+(const LiczbaRzeczywista& r){
        LiczbaRzeczywista rr(re+r.re);
        return rr;
    }

};

class LiczbaZespolona : public LiczbaRzeczywista{
protected:
    double im;
public:
    LiczbaZespolona(double re, double i):LiczbaRzeczywista(re){im=i;}
    void wypisz() override {
        cout << re << " + " << im << "i" << endl;
    }
};

int main(){
    LiczbaRzeczywista a(12);
    LiczbaZespolona b(23,5);

    a.powitaj();         //Czesc!
    a.wypisz();          //12
    (a+a).wypisz();      //24

    b.powitaj();         //Czesc!
    b.wypisz();          //23 + 5I


    (b+b).wypisz();      //Co się wypisze? odp. 46
}