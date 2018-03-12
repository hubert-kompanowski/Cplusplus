//
// Created by abrajner on 12.03.18.
//
#include <iostream>
#include "XorCypherBreaker.h"

std::string GenerateKey (int numer1, int numer2, int numer3){
    std::string key;

    key += 97+numer1;
    key += 97+numer2;
    key += 97+numer3;

    return key;
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length, const std::vector<std::string> &dictionary){

    std::string key;

    char symbol_xor;
    int x=0;
    int count;
    unsigned long size;

    std::string result;

    std::vector<std::string> words;
    std::string word;

    std::vector<char> solution;

    for(int numer1=0; numer1<=25; numer1++){
        for(int numer2=0; numer2<=25; numer2++){
            for(int numer3=0; numer3<=25; numer3++){
                key = GenerateKey(numer1, numer2, numer3);

                solution.clear();

                for(char symbol : cryptogram){
                    symbol_xor = symbol xor key.at(x);
                    x++;
                    if(x>2) x=0;

                    solution.push_back(symbol_xor);
                }

                words.clear();
                for(char symbol : solution){
                    if((symbol >= 97 && symbol <= 122) || (symbol >= 65 && symbol <= 90)){
                        word += symbol;
                    }
                    else{
                        if(word.empty()){
                            continue;
                        }
                        words.push_back(word);
                        word.clear();
                    }
                }

                size = words.size();

                count=0;
                for(std::string good_word : words) {
                    if (std::find(dictionary.begin(), dictionary.end(), good_word) != dictionary.end()){
                        count++;
                    }
                }

                if(count>size/3.6){
                    result += 97+numer3;
                    result += 97+numer1;
                    result += 97+numer2;
                    return result;
                }
            }
        }
    }
}
