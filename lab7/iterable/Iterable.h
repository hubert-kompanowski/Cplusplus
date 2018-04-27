//
// Created by hubert on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLEITERATOR_H
#define JIMP_EXERCISES_ITERABLEITERATOR_H

#include <string>
#include <vector>
#include <memory>


namespace utility {

    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const IterableIterator &other) const = 0;
    };

    class ZipperIterator : public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        std::pair<int, std::string> Dereference()const override;
        IterableIterator &Next() override ;
        bool NotEquals(const IterableIterator &other)const override;
    };

    class ProductIterator : public IterableIterator{

    };

    class EnumerateIterator : public  IterableIterator{

    };

    class IterableIteratorWrapper{
    public:
        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();

    };

    class Iterable{
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin = 0;
        virtual std::unique_ptr<IterableIterator> ConstEnd = 0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;


    };

    class Zipper : public Iterable{
    };

    class Product : public Iterable{

    };

    class Enumerate : public Iterable{

    };





}

#endif //JIMP_EXERCISES_ITERABLEITERATOR_H
