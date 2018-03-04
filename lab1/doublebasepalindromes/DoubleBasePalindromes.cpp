//
// Created by hubert on 02.03.18.
//

#include <cmath>
#include <iostream>
#include <string>
#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    int size_10;
    int digit, number_in_2, j=1;
    uint64_t sum;

    for(int number_in_10=1; number_in_10<=max_vaule_exculsive; number_in_10++){
        size_10 = (int)log10(number_in_10) + 1;
        std::cout << number_in_10 << "-";
        for(int i=0; i<size_10/2; i++) {
            if(number_in_10/10*size_10-i == number_in_10/i){

                while(number_in_10!=0){
                    digit = number_in_10%2;
                    number_in_2 = digit*j;
                    j*=10;
                    number_in_10/10;
                    std::cout << number_in_2 << "#";

                }
                sum += number_in_2;
            }

        }
    }
    return sum;
}
