//
// Created by hubert on 19.04.18.
//

#include "Zipper.h"
#include "Zipper.h"
#include <map>
namespace datastructures{

    Zipper::Zipper() {}
    Zipper::~Zipper() {}

    std::map<std::string, int> Zipper::zip (std::vector<std::string> string_vector, std::vector<int> int_vector){
        std::map<std::string, int> result={};
        std::map <std::string, int>::iterator map_iterator = result.begin();
        Iterator it;
        Iterator end;
        it.iterator_int_ = int_vector.begin();
        it.iterator_string_ = string_vector.begin();
        end.iterator_int_ = int_vector.end();
        end.iterator_string_ = string_vector.end();

        for(it; it!=end; ++it){
            int integer = *it.iterator_int_;
            std::string string = *it.iterator_string_;
            result.insert(map_iterator, std::pair<std::string, int>(string, integer));
        }
        return result;
    }
    Iterator::Iterator() {}
    Iterator::Iterator(std::vector <std::string>::iterator string_pointer, std::vector <int>::iterator int_pointer){
        iterator_string_= string_pointer;
        iterator_int_ = int_pointer;
    }

    bool Iterator::operator!=(Iterator new_iterator){
        if(new_iterator.iterator_int_==iterator_int_){
            return false;
        }
        if(new_iterator.iterator_string_==iterator_string_){
            return false;
        }
        return true;
    }
    Iterator & Iterator::operator++(){
        ++iterator_int_;
        ++iterator_string_;
        return  *this;

    }
    std::pair<std::string, int> Iterator::operator*(){
        std::pair <std::string, int> new_pair;
        new_pair.first = *iterator_string_;
        new_pair.second = *iterator_int_;
        return new_pair;
    }
}