//
// Created by hubert on 23.05.18.
//

#ifndef JIMP_EXERCISES_REPO_H
#define JIMP_EXERCISES_REPO_H


#include <cstdio>
#include <map>
#include <algorithm>

template<typename T>
class Repository {
public:

    Repository<T>(T t ,int i){
        repo.emplace(std::pair<int, std::string>(i, t));
    }

    size_t Size(){
        return repo.size();
    }


    T operator[](int id){
        return repo[id];
    }

    int NextId(){
        int i;
        for(auto p : repo){
            i = p.first;
        }
        i++;
        return i;
    }




    std::map<int,T> repo;
};


#endif //JIMP_EXERCISES_REPO_H
