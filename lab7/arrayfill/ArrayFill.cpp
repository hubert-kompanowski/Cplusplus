//
// Created by hubert on 14.04.18.
//

#include "ArrayFill.h"

using namespace arrays;


ArrayFill::ArrayFill() {

}

int ArrayFill::Value(int index) const {
    return tab.at(index);
}


int UniformFill::Value(int index) const {
    return value_;
}