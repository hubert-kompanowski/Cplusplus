//
// Created by hubert on 02.03.18.
//

#include <bits/stdc++.h>
#include "DoubleBasePalindromes.h"
using namespace std;


string integer_to_string(int palindrome_num_in_10) {
    string str;

    //konwesja int -> string liczby(10) oraz zamiana na system (2)
    while (palindrome_num_in_10 > 0) {
        int digit = palindrome_num_in_10 % 2;
        palindrome_num_in_10 /= 2;
        str.push_back(digit + '0');
    }
    return str;
}

int isPalindrome(int number) {
    int tmp_num = number;
    int reverse_num = 0;

    //odwracanie liczby zapisanej w systemie dziesiętnym
    while (tmp_num > 0) {
        reverse_num = tmp_num % 10 + reverse_num * 10;
        tmp_num /= 10;
    }

    if (reverse_num == number) {
        string str = integer_to_string(reverse_num);
        string reverse_string = str;
        reverse(reverse_string.begin(), reverse_string.end());

        if (str == reverse_string) {
            return number;
        }
    }
    return 0;
}

uint64_t sumPalindrome(int max_value){

    uint64_t sum = 0;
    for (int number = 1; number < max_value; number++) {
        sum += isPalindrome(number);
    }
    return sum;
}


uint64_t DoubleBasePalindromes(int max_vaule_exculsive){

    uint64_t sum = sumPalindrome(max_vaule_exculsive);
    return sum;
}





