//
// Created by hubert on 23.05.18.
//


#include <iostream>
#include "Repo.h"


int main(){

    Repository<std::string> repository("sgs", 5);



    std::cout<< repository.NextId();

}