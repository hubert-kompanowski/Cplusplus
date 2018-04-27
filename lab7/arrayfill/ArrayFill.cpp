//
// Created by hubert on 14.04.18.
//

#include "ArrayFill.h"

using namespace arrays;


ArrayFill::ArrayFill() {}


UniformFill::UniformFill(int value) {
    value_ = value;
}
IncrementalFill::IncrementalFill(int start, int step) {
    for(int i=0; i <=35; i++){
        tab.push_back(start);
        start += step;
    }
}
SquaredFill::SquaredFill(int a, int b) {
    for(int i=0; i <=100; i++){
        tab.push_back(a*i*i+b);
    }
}
RandomFill::RandomFill(std::unique_ptr<default_random_engine> x, std::unique_ptr<uniform_int_distribution<int>> y) {
    this->random_engine_ = std::move(x);
    this->int_distribution_ = std::move(y);

}


int UniformFill::Value(int index) const {
    return value_;
}
int IncrementalFill::Value(int index) const {
    return tab.at(index);
}
int SquaredFill::Value(int index) const {
    return tab.at(index);
}
int RandomFill::Value(int index) const {
    return (*int_distribution_)(*random_engine_);
}


void arrays::FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
    v->clear();
    v->reserve(size);
    for(size_t i = 0; i < size; i++) {
        v->emplace_back(filler.Value(i));
    }
}