//
// Created by hubert on 24.04.18.
//
#include "Pesel.h"

using namespace academia;

void Pesel::validatePESEL(std::string a){

    if (a.length() != 11){
        throw InvalidPeselLength(a, a.size());
    }

    for(char c : a){
        if((48>c) || (c>57)){
            throw InvalidPeselCharacter(a);
        }
    }

    int array[]= {9, 7, 3, 1, 9, 7, 3, 1, 9, 7};
    int checksum = 0;
    for(int i=0; i<10; i++){
        checksum += array[i]*(a[i]-48);
    }
    if(checksum%10 != a[10]-'0'){
        throw InvalidPeselChecksum(a, checksum);
    }
}


Pesel::Pesel(std::string a){
    validatePESEL(a);
}