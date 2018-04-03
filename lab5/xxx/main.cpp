//
// Created by hubert on 25.03.18.
//
#include "XXX.h"
#include <iostream>


XXX make_copy(XXX xxx) {
    return xxx;
}

int main() {

    XXX old_xxx {};

    XXX new_xxx {std::move(old_xxx)};

    XXX another_xxx {};

    another_xxx = std::move(new_xxx);

    XXX one_more = make_copy(another_xxx);

    return 0;
}