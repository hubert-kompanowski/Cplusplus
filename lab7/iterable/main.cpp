//
// Created by hubert on 21.04.18.
//

#include <iostream>
#include "Iterable.h"
using namespace utility;
using namespace std;

int main(){

    cout << "ddd";


    const vector<int> vi {4, 77, -91};
    const vector<string> vs {"4", "9991", "adfskld"};



    for (const auto &p : Zipper(vi, vs)) {
        cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    //wypisze: (4, "4") (77, "9991") (-91,"adfskld")

    for (const auto &p : Enumerate(vs)) {
        cout << "(" << p.first << ", \"" << p.second << "\") ";
    }
    //wypisze: (0, "4") (1, "9991") (2,"adfskld")

    for (const auto &p : Product(vi,vs)) {
        cout << "(" << p.first << ", \"" << p.second << "\") ";
    }


}