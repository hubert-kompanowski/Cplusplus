//
// Created by hubert on 14.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H


#include <vector>
#include <cstdio>

namespace arrays {


    class ArrayFill {
    public:
        ArrayFill();
        virtual int Value(int index) const =0;

    private:
        std::vector<int> tab;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };



    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }
}
#endif //JIMP_EXERCISES_ARRAYFILL_H
