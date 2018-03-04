//
// Created by hubert on 02.03.18.
//

#include <iostream>
#include "DoubleBasePalindromes.h"
#include <cmath>


int main() {
    int tmp_num = 1234;
    int reverse_num;
    while (tmp_num > 0) {
        reverse_num = tmp_num % 10 + reverse_num * 10;
        tmp_num /= 10;
    }
    std::cout << reverse_num;
}


