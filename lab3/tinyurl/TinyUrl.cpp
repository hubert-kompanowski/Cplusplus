//
// Created by hubert on 13.03.18.
//

#include <iostream>
#include "TinyUrl.h"

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init() {
        return std::make_unique<TinyUrlCodec>();
    }

                    // tablica sześciu charów
    void NextHash(std::array<char, 6> *state) {

        bool change = false;
        for(int x=5; x>=0; --x){
            if(change || x==5){

                if(state->at(x) !='z'){

                    if(state->at(x) =='9') {
                        state->at(x) = 'A';
                    } else {
                        if (state->at(x) == 'Z') {
                            state->at(x) = 'a';
                        } else{
                            state->at(x)++;
                        }
                    }
                }
                change = false;
            }
            if( state->at(x)== 'z' && !change){
                state->at(x) = '0';
                change = true;
                continue;
            }
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        unsigned long size =codec->operator->()->name_and_hash.size();
        std::string result;

        if(size == 0){
            codec->operator->()->name_and_hash.push_back({{'0','0','0','0','0','0'}, url});
            return "000000";
        }

        for(std::pair <std::array<char,6>, std::string> temp: codec->operator->()->name_and_hash){
            if(temp.second == url){
                for(char character : temp.second){
                    result += character;
                }
                return result;
            }
        }

        std::array<char,6> hash = codec->operator->()->name_and_hash.at(size-1).first;
        NextHash(&hash);

        codec->operator->()->name_and_hash.push_back({hash,url});

        for(char character : hash){
            result += character;
        }
        return result;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        std::string str_hash;
        std::string str_name;
        for(std::pair <std::array<char,6>, std::string> temp : codec->name_and_hash){
            for(char character : temp.first){
                str_hash += character;
            }

            if(str_hash == hash){
                for(char character : temp.second){
                    str_name += character;
                }
                return str_name;
            }

        }
    }
}



