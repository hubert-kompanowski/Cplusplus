//
// Created by hubert on 05.03.18.
//

#include <iostream>
#include "GreatestProduct.h"


std::vector<int> getVector(const std::vector<int> &numbers, int k, bool abs);

int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector<int> max_number_vector = getVector(numbers, k, false);
    std::vector<int> max_number_vector_no_plus = getVector(numbers, k, true);

    if(k%2==1){
        int iloczyn = 1;
        for(int i : max_number_vector) iloczyn *=i;

        int max=-3;
        for(int x : max_number_vector) if(max<x) max=x;

        int iloczyn_2=1;
        std::vector<int> max_number_vector_no_plus_two = getVector(numbers, 2, true);

        for(int i : max_number_vector_no_plus_two) iloczyn_2 *=i;

        iloczyn_2 *= max;
        if(iloczyn>iloczyn_2) return iloczyn;
        else return iloczyn_2;
    }

    int iloczyn = 1;
    int iloczyn_2 = 1;

    for(int i : max_number_vector) iloczyn *=i;

    for(int i : max_number_vector_no_plus) iloczyn_2 *=i;

    max_number_vector.clear();

    if(iloczyn>iloczyn_2) return iloczyn;
    else return iloczyn_2;
}

std::vector<int> getVector(const std::vector<int> &numbers, int k, bool is_abs) {
    std::vector<int> max_number_vector;
    std::vector<int>::const_iterator begin_vector;
    std::vector<int>::const_iterator min_index;
    int min_numer;

    for(int v : numbers) {
        if(is_abs){
            if(v>0) continue;
        }
        if(max_number_vector.size() < k){
            max_number_vector.push_back(v);
        }
        else{
            begin_vector = max_number_vector.begin();
            min_index = max_number_vector.begin();
            min_numer=100000;
            
            for(int x : max_number_vector) {
                if(is_abs) x=abs(x);
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
    return max_number_vector;
}

