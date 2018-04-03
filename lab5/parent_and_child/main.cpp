//
// Created by hubert on 27.03.18.
//

#include "Child.h"
#include "Parent.h"


int main(){

    Child dziecko("Hubert", "Kompanowski", 21, "AGH");
    dziecko.wyswietl_dane();

    Parent rodzic("Marcin", "Kompanowski", 50, "Hubert");
    rodzic.przepiszDoInnejSzkoly("UJ", dziecko);


    dziecko.wyswietl_dane();



}
