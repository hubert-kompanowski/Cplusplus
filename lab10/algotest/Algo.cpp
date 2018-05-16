//
// Created by hubert on 10.05.18.
//

#include <iostream>
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
    std::transform(m.begin(), m.end(), std::inserter(result, result.begin()), [](auto x){
        return x.first;
    });
    return result;
}

bool algo::ContainsValue(const std::map<std::string, int> &v, int value) {
    std::vector<int> result;
    std::transform(v.begin(), v.end(), std::back_inserter(result), [](auto x){
        return x.second;
    });
    return (std::find(result.begin(), result.end(), value)!= result.end());
}

std::vector<int> algo::Values(const std::map<std::string, int> &m) {
    std::vector<int> result;
    std::transform(m.begin(), m.end(), std::back_inserter(result), [](auto x){
        return x.second;
    });
    return result;
}

std::vector<int> algo::DivisableBy(const std::vector<int> &m, int divisor) {
    std::vector<int> result;
    std::copy_if(m.begin(), m.end(), std::back_inserter(result), [divisor](auto x) {return (x%divisor==0);} );
    return result;
}

void algo::SortInPlace(std::vector<int> *v) {
    std::sort(v->begin(), v->end());
}

std::vector<int> algo::Sort(const std::vector<int> &v) {
    std::vector<int> result = v;
    std::sort(result.begin(), result.end());
    return result;
}

bool myfunction (std::pair<int, int> i,std::pair<int, int> j) { return (i.first<j.first); }
bool myfunction2 (std::pair<int, int> i,std::pair<int, int> j) { return (i.second<j.second); }
bool myfunction3 (std::tuple<int, int, int> i,std::tuple<int, int, int> j) { return (std::get<2>(i) < std::get<2>(j)); }

void algo::SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
    std::sort(v->begin(), v->end(), myfunction);
}

void algo::SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
    std::sort(v->begin(), v->end(), myfunction2);

}

void algo::SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
    std::sort(v->begin(), v->end(), myfunction3);

}

std::vector<std::string> algo::RemoveDuplicates(const std::vector<std::string> &v) {
    std::vector<std::string> result;
    std::unique_copy(v.begin(), v.end(), std::back_inserter(result));
    return result;
}

void algo::RemoveDuplicatesInPlace(std::vector<std::string> *v) {
    std::unique(v->begin(), v->end());
}

long algo::HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
    long x = std::count_if(v.begin(), v.end(), [inclusive_short_length] (auto i) {
        if(inclusive_short_length < i.length())
            return true;
        return false;
    });
    return x;

}