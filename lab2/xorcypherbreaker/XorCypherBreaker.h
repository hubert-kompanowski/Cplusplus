//
// Created by abrajner on 12.03.18.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::find;
using std::vector;
using std::string;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
