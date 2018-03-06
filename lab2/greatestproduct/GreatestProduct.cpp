//
// Created by hubert on 05.03.18.
//

#include <iostream>
#include "GreatestProduct.h"


int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector<int> max_number_vector;
    std::vector < int >::const_iterator begin_vector;
    std::vector < int >::const_iterator min_index;
    int min_numer;

    for(int v : numbers) {
        if(max_number_vector.size() < k){
            max_number_vector.push_back(v);
        }
        else{
            begin_vector = max_number_vector.begin();
            min_index = max_number_vector.begin();
            min_numer=100000;
            for(int x : max_number_vector) {
                if (min_numer > x) {
                    min_numer = x;
                    min_index = begin_vector;
                }
                begin_vector++;
            }
            if(v > min_numer){
                max_number_vector.erase(min_index);
                max_number_vector.insert(min_index, v);
            }

        }
    }
    int iloczyn = 1;

    for(int i : max_number_vector){
        iloczyn *=i;
    }
    max_number_vector.clear();

    return iloczyn;
}