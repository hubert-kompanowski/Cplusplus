//
// Created by hubert on 15.04.18.
//

#ifndef JIMP_EXERCISES_WORKER_H
#define JIMP_EXERCISES_WORKER_H


#include <iostream>
#include <list>

using namespace std;

class Umowa{
protected:
    double wynagrodzenieBrutto;
public:
    Umowa(double pensja):wynagrodzenieBrutto(pensja){};
    virtual double pobierzNetto()=0;
    double pobierzBrutto();
};

class UmowaDzielo: public Umowa{
public:
    UmowaDzielo(double pensja):Umowa(pensja){};
    double pobierzNetto() override; //+virtual na poczatku?
};

class UmowaPraca: public Umowa{
public:
    UmowaPraca(double pensja):Umowa(pensja){};
    double pobierzNetto() override; //+virtual na poczatku?
};

class Pracownik{
private:
    string imie,nazwisko,pesel;
    Umowa* umowa;
public:
    Pracownik(string i,string n,string p,Umowa* u)
            :imie(i),nazwisko(n),pesel(p),umowa(u){};
    Pracownik(const Pracownik&);
    ~Pracownik(){};
    double pobierzPensje();
    friend ostream& operator<<(ostream&,Pracownik&);
};

ostream& operator<<(ostream&, Pracownik&);



#endif //JIMP_EXERCISES_WORKER_H
