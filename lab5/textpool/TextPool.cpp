//
// Created by hubert on 04.04.18.
//

#include "TextPool.h"

using namespace pool;

TextPool::TextPool() { }
TextPool::~TextPool() { }

TextPool::TextPool(TextPool && other) {
    pool = other.pool;
    other.pool.clear();
}

TextPool & TextPool::operator=(TextPool && other) {
    if(this == &other){
        return *this;
    }
    pool = other.pool;
    other.pool.clear();
}

TextPool::TextPool(const std::initializer_list<std::experimental::string_view> list) {
    for(std::experimental::string_view v : list) {
        pool.emplace(v);
    }
}

std::experimental::string_view TextPool::Intern(const std::string &str) {
    for(std::experimental::string_view v : pool){
        if(v == str){
            return *pool.emplace(str).first;
        }
    }
    pool.insert(str);
    return *pool.emplace(str).first;
}

size_t TextPool::StoredStringCount() const {
    return pool.size();
}
