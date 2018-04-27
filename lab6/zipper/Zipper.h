//
// Created by hubert on 19.04.18.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace datastructures{

    class Zipper{
    public:
        friend class Iterator;
        Zipper();
        ~Zipper();
        static std::map<std::string, int> zip(std::vector<std::string> string_vector, std::vector<int> int_vector); 

    private:

    };

    class Iterator{
    public:
        Iterator();
        Iterator(std::vector <std::string>::iterator string_pointer, std::vector <int>::iterator int_pointer); 
        bool operator!=(Iterator new_iterator);
        Iterator & operator++();
        std::pair<std::string, int> operator*();

        std::vector <int>::iterator iterator_int_;
        std::vector <std::string>::iterator iterator_string_;

    };
}


#endif //JIMP_EXERCISES_ZIPPER_H
