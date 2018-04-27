//
// Created by hubert on 21.04.18.
//

#include <iostream>
#include "Iterable.h"

using namespace utility;

ZipperIterator::ZipperIterator(std::vector<int>::const_iterator l,
                               std::vector<std::string>::const_iterator r,
                               std::vector<int>::const_iterator l_end,
                               std::vector<std::string>::const_iterator r_end) {
    left = l;
    right = r;
    left_end = l_end;
    right_end = r_end;
}


std::pair<int, std::string> ZipperIterator::Dereference() const{
    if(right == right_end && left == left_end){
        return std::pair<int, std::string>{0,""};
    }
    return std::pair<int,std::string>{*left, *right};
};


IterableIterator& ZipperIterator::Next() {
    if(right+1 == right_end && left+1 == left_end) {
        right = right_end;
        left = left_end;
    } else {
        if (left+1 != left_end)
            ++left;
        if (right+1 != right_end)
            ++right;
    }
    return *this;
}

bool getBoolDereference(std::pair<int, std::string> f, std::pair<int, std::string> s){
    if(f==s){
        return false;
    }
    return true;
}

bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const{
    return getBoolDereference(this->Dereference(), other->Dereference());
}


IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> other){
    iterator = std::move(other);
}


bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other)const{
    return this->iterator->NotEquals(other.iterator);
}


std::pair<int, std::string> IterableIteratorWrapper::operator*()const{
    return iterator->Dereference();
}


IterableIteratorWrapper &IterableIteratorWrapper::operator++(){
    auto temp = std::unique_ptr<IterableIterator>(&iterator->Next());
    iterator.release();
    iterator = std::move(temp);
    return *this;
}


IterableIteratorWrapper Iterable::cbegin() const{
    return IterableIteratorWrapper(ConstBegin());
}
IterableIteratorWrapper Iterable::cend() const {
    return IterableIteratorWrapper(ConstEnd());
}
IterableIteratorWrapper Iterable::begin() const {
    return cbegin();
}
IterableIteratorWrapper Iterable::end() const {
    return cend();
}


Zipper::Zipper(std::vector<int> f, std::vector<std::string> s){
    first = std::move(f);
    second = std::move(s);
}

std::unique_ptr<IterableIterator> Zipper::ConstBegin() const{
    return std::make_unique<ZipperIterator>(first.begin(), second.begin(), first.end(), second.end());
}

std::unique_ptr<IterableIterator> Zipper::ConstEnd() const{
    return std::make_unique<ZipperIterator>(first.end(),second.end(),first.end(),second.end());
}

ProductIterator::ProductIterator(std::vector<int>::const_iterator l,
                                 std::vector<std::string>::const_iterator r,
                                 std::vector<int>::const_iterator l_end,
                                 std::vector<std::string>::const_iterator r_end,
                                 std::vector<std::string>::const_iterator r_start){
    left = l;
    right = r;
    left_end = l_end;
    right_end = r_end;
    right_start = r_start;
}

std::pair<int, std::string> ProductIterator::Dereference() const{
    std::pair<int, std::string> result;
    if(right == right_end || left == left_end){
        if(left != left_end)
            result.second = *right;
        else
            result.second = "";
        if(right != right_end)
            result.first = *left;
        else
            result.first = 0;
        return result;
    }
    return std::pair<int, std::string>{*left, *right};
}

IterableIterator& ProductIterator::Next(){
    if(left == left_end)
        return *this;
    ++right;
    if(right == right_end ) {
        ++left;
        if(left != left_end) {
            right = right_start;
        }
    }
    return *this;
}

bool ProductIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    return getBoolDereference(this->Dereference(), other->Dereference());
}

Product::Product(std::vector<int> f, std::vector<std::string> s){
    first = std::move(f);
    second = std::move(s);
}

std::unique_ptr<IterableIterator> Product::ConstBegin() const {
    return std::make_unique<ProductIterator>(first.begin(),second.begin(),first.end(),second.end(),second.begin());
}

std::unique_ptr<IterableIterator> Product::ConstEnd() const {
    return std::make_unique<ProductIterator>(first.end(),second.end(),first.end(),second.end(),second.begin());
}

EnumerateIterator::EnumerateIterator(std::vector<std::string>::const_iterator b, std::vector<std::string>::const_iterator e){
    begin = b;
    end = e;
    index = 1;
}

std::pair<int, std::string> EnumerateIterator::Dereference() const {
    if(begin == end)
        return std::pair<int, std::string>(0, "");
    else
        return std::pair<int, std::string>(index, *begin);
}

IterableIterator& EnumerateIterator::Next()  {
    if(begin != end) {
        ++begin;
        ++index;
    }
    return *this;
}

bool EnumerateIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    return getBoolDereference(this->Dereference(), other->Dereference());
}

Enumerate::Enumerate( std::vector<std::string> f){
    first = std::move(f);
}

std::unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
    return std::make_unique<EnumerateIterator>(first.begin(),first.end());
}
std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
    return std::make_unique<EnumerateIterator>(first.end(),first.end());
}

