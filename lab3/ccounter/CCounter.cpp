//
// Created by abrajner on 13.03.18.
//

#include "CCounter.h"

namespace ccounter{

    struct Counter {
        std::map <std::string,int> text;
        int counter = 0;
    };

    std::unique_ptr<Counter> Init() {

        std::unique_ptr <Counter> pointer = std::make_unique<Counter>();
        return nullptr;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {

    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
        return 0;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {

    }
}