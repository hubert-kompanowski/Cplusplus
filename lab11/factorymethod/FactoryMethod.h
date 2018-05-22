//
// Created by abrajner on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H
#include <string>
#include <vector>

namespace factoryMethod {
    template<typename T>
    T Create() {
        T value{};
        return value;
    };

    class  MyType{
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
    T Mean(std::vector<T> v){
        T sum{};
        for (int i = 0; i<v.size(); i++){\
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
