//
// Created by abrajner on 12.03.18.
//

#include "XorCypherBreaker.h"

void Decrypting (size_t sizeOfText, const std::vector<char > &cryptogram, char *key, char *NewText){
    int number = 0;
    for(int i = 0; i < sizeOfText; i++){
        if(number > 3){
            number = 0;
        }
            NewText[i] = cryptogram[i] xor key[number];
            number++;
    }
}

bool CheckingWord(const std::vector<string> &dictionary, char* NewText){

}

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary){
    size_t sizeOfText = cryptogram.size();
    char NewText[sizeOfText];

    char key[key_length] = {97, 97, 97};
    bool check = false;

    while (!check){
        while(key[0]<=122){
            while(key[1]<=122){
                while(key[2]<=122){
                    key[2]++;
                    Decrypting(sizeOfText, cryptogram, key, NewText);
                    if(CheckingWord(dictionary, NewText)){
                        check = true;
                    }
                }
                key[2] = 97;
                key[1]++;
            }
            key[1] = 97;
            key[0]++;
        }
    }
}