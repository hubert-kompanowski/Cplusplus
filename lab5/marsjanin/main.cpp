//
// Created by hubert on 27.03.18.
//

#include <iostream>
#include <list>
#include <stdlib.h>
#include <unistd.h>
#include "Marsjanie.h"
using namespace std;

int main(void){
    list<Marsjanin> lista;
    Marsjanin ja;
    
    while(1){
        if(rand()%2==0){
            lista.push_front(ja);
            Marsjanin::liczbaMarsjan++;
        }
        else{
            if (Marsjanin::liczbaMarsjan > 0){
                lista.pop_front();
                Marsjanin::liczbaMarsjan--;
            };
        };
        if (Marsjanin::liczbaMarsjan > 1)
            ja.atakuj();
        if (Marsjanin::liczbaMarsjan <= 1)
            ja.ukryjSie();
        sleep(1);
        
    };

    return 0;
}