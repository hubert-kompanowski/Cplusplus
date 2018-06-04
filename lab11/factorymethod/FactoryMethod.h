//
// Created by abrajner on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H
#include <string>
#include <vector>

namespace factoryMethod {
    template<typename T>
    T Create(){
        return T();
    }

    class MyType{
    public:
        std::string SayHello(){
            return "hello";
        }

    };

    template<typename  T>
    T Add(T x, T y){
        return x+y;
    }

    template <typename T>
    T Mean(const std::vector<T> &v){
        T sum = Create<T>();
        for (int i = 0; i<v.size(); i++){
            sum += v[i];
        }
        return (sum/v.size());
    }

    template<typename T>
    auto Value(const T &v){
        return *v;
    }
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H



