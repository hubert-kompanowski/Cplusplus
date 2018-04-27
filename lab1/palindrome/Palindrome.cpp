//
// Created by hubert on 02.03.18.
//

#include "Palindrome.h"


bool IsPalindrome(std::string str){
    for(unsigned long i=0; i<str.size(); i++ ){
        if(str.at(i) != str.at(str.size()-i-1)){
            return false;
        }
    }
    return true;
}
