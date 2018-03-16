//
// Created by hubert on 13.03.18.
//

#include "CCounter.h"

namespace ccounter{


    std::unique_ptr<Counter> Init() {
        return std::make_unique<Counter>();
    }


    void Inc(std::string key, std::unique_ptr<Counter> *counter) {

        bool not_exist = true;
        auto size = counter->operator->()->data.size();

        for(unsigned long part = 0; part <size ;part++) {
            if(counter->operator->()->data.at(part).first == key) {
                not_exist = false;
                counter->operator->()->data.at(part).second+=1;
                break;
            }
        }
        if(not_exist) {
            counter->operator->()->data.push_back({key,1});
        }
    }


    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
        int number = 0;
        for(std::pair <std::string, int> part : counter->data){
            if(part.first == key){
                number += part.second;
            }
        }
        return number;
    }


    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {
        bool not_exist = true;

        for(std::pair <std::string, int> part : counter->operator->()->data){
            if(part.first == key) {
                not_exist = false;
                part.second = value;
                break;
            }
        }
        if(not_exist){
            counter->operator->()->data.push_back({key, value});
        }
    }
}