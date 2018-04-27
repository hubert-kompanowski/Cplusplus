//
// Created by hubert on 14.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <memory>
#include <random>

using ::std::default_random_engine;
using ::std::uniform_int_distribution;
using ::std::make_unique;


namespace arrays {

    class ArrayFill {
    public:
        ArrayFill();
        virtual int Value(int index) const =0;
    };


    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0);
        virtual int Value(int index) const override;
    private:
        int value_;
    };


    class IncrementalFill : public ArrayFill{
    public:
        IncrementalFill(int start, int step = 1);
        virtual int Value(int index) const override;
    private:
        std::vector<int> tab;
    };


    class SquaredFill : public ArrayFill{
    public:
        SquaredFill(int a=1, int b=0);
        virtual int Value(int index) const override;
    private:
        std::vector<int> tab;
    };


    class RandomFill : public ArrayFill{
    public:
        RandomFill(std::unique_ptr<default_random_engine>, std::unique_ptr<uniform_int_distribution<int>>);
        virtual int Value(int index) const override;

    private:
        std::vector<int> tab;
        std::unique_ptr<default_random_engine> random_engine_;
        std::unique_ptr<uniform_int_distribution<int>> int_distribution_;
    };


    void FillArray(size_t , const ArrayFill &, std::vector<int> *);

}
#endif //JIMP_EXERCISES_ARRAYFILL_H
