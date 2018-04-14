//
// Created by hubert on 04.04.18.
//


#include <fstream>
#include "WordCounter.h"

using namespace datastructures;

int main(){

    std::ifstream is("/home/hubert/Pulpit/JiMP2/Cplusplus/lab6/wordcounter");

    if(!is.good()){
        std::cout <<"alshdaosd";
    }

    WordCounter wc = wc.FromInputStream(is);

    for(auto x : wc.dict_vector){
        std::cout << x.first.Get_word() << " " << x.second.Get_counter() << std::endl;
    }
    //std::cout << wc["raz"] << wc["dwa"];




}