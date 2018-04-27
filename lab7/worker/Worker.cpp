//
// Created by hubert on 15.04.18.
//

#include "Worker.h"

double Umowa::pobierzBrutto() {
    return wynagrodzenieBrutto;
}

double UmowaDzielo::pobierzNetto() {
    double a=wynagrodzenieBrutto;
    return (wynagrodzenieBrutto-a*0.18);
}
double UmowaPraca::pobierzNetto() {
    double a=wynagrodzenieBrutto;
    return (wynagrodzenieBrutto-a*0.0976-a*0.0245-a*0.015-a*0.09-111.25);
}
double Pracownik::pobierzPensje() { return umowa->pobierzNetto();}

std::ostream &operator<<(std::ostream &output, Pracownik& a) {
    output<<"Imie: "<<a.imie<<", ";
    output<<"Nazwisko: "<<a.nazwisko<<", ";
    output<<"Pesel: "<<a.pesel<<", ";
    output<<"Zarobki brutto: "<<a.umowa->pobierzBrutto()<<" ";
    return output;
}