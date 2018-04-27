//
// Created by hubert on 18.04.18.
//

#include <iostream>
#include "Name.h"
using namespace model;

int main(){
    Name name("John              Reuel \n\n\r\t Tolkien");

    std::cout<< name.first_name_<<name.second_name_<<name.third_name_<<name.last_name_;

}