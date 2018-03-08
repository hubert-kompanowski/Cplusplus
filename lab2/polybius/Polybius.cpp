//
// Created by hubert on 08.03.18.
//

#include "Polybius.h"


std::string PolybiusCrypt(std::string message){

    std::transform(message.begin(), message.end(), message.begin(), ::tolower);

    char tab[5][5] = {{'a','b','c','d','e'}, {'f','g','h','i','k'},
                      {'l','m','n','o','p'}, {'q','r','s','t','u'},
                      {'v','w','x','y','z'}};

    unsigned long size = message.length();

    std::string crypt;
    std::string number;
    for(int i=0; i<size; i++){
        if(message.at(i) == 'j'){
            crypt += "24";
            continue;
        }
        for(int x = 1; x<=5; x++){
            for(int y = 1; y<=5; y++){

                if(message.at(i) == tab[x-1][y-1]){

                    number = std::to_string(x);
                    number += std::to_string(y);
                    crypt += number;
                }
            }
        }
    }
    return crypt;
}

std::string PolybiusDecrypt(std::string crypted){
    char tab[5][5] = {{'a','b','c','d','e'}, {'f','g','h','i','k'},
                      {'l','m','n','o','p'}, {'q','r','s','t','u'},
                      {'v','w','x','y','z'}};

    unsigned long size = crypted.length();
    std::string message;
    std::string part_crypted;
    int number_x;
    int number_y;

    for(int i=0; i<size; i+=2){
        part_crypted = crypted[i];
        number_x = std::stoi(part_crypted);
        part_crypted = crypted[i+1];
        number_y = std::stoi(part_crypted);

        message += tab[number_x-1][number_y-1];
    }

    return message;
}

