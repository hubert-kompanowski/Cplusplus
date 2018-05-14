//
// Created by hubert on 10.05.18.
//

#include "Algo.h"


void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
    std::copy_n(v.cbegin(), n_elements, std::back_inserter(*out));

}

bool algo::Contains(const std::vector<int> &v, int element) {
    return (std::find(v.begin(), v.end(), element)!=v.end());
}

void algo::InitializeWith(int initial_value, std::vector<int> *v) {
    std::fill(v->begin(), v->end(), initial_value);
}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value) {
    std::vector<int> result;
    std::fill_n(std::back_inserter(result), length, initial_value);
    return result;
}

std::vector<std::string> algo::MapToString(const std::vector<double> &v) {
    std::vector<std::string> s;
    std::transform(v.begin(), v.end(), std::back_inserter(s), [](double i){
        return std::to_string(i);
    });
    return s;
}

bool algo::ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
    return (v.find(key)!=v.end());
}

std::set<std::string> algo::Keys(const std::map<std::string, int> &m) {
    std::set<std::string> result;

    return result;
}