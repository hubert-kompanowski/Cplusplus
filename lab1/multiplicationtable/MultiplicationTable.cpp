//
// Created by hubert on 02.03.18.
//

#include "MultiplicationTable.h"
#include <iostream>

void MultiplicationTable(int tab[][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tab[i][j] = (i+1)*(j+1);
        }
    }
}

void drawtable(int tab[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(tab[i][j] < 10){
                std::cout << " ";
            }
            std::cout << tab[i][j] << " ";
        }
        std::cout << "\n";
    }
}



