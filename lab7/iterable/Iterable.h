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
        virtual IterableIterator& Next() = 0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const = 0;
    };


    class ZipperIterator : public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override ;
    private:
        std::vector<int>::const_iterator left;
        std::vector<std::string>::const_iterator right;
        std::vector<int>::const_iterator left_end;
        std::vector<std::string>::const_iterator right_end;
    };


    class IterableIteratorWrapper{
    public:
        explicit IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other)const ;
        std::pair<int, std::string> operator*()const;
        IterableIteratorWrapper &operator++();
    private:
        std::unique_ptr<IterableIterator> iterator;
    };


    class Iterable{
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const=0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const=0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
    };


    class Zipper : public Iterable{
    public:
        Zipper(std::vector<int> f, std::vector<std::string> s);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    private:
        std::vector<int> first;
        std::vector<std::string> second;
    };


    class ProductIterator : public IterableIterator{
    public:
        explicit ProductIterator(std::vector<int>::const_iterator left,
                                 std::vector<std::string>::const_iterator right,
                                 std::vector<int>::const_iterator left_end,
                                 std::vector<std::string>::const_iterator right_end,
                                 std::vector<std::string>::const_iterator right_start);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override ;
    private:
        std::vector<int>::const_iterator left;
        std::vector<std::string>::const_iterator right;
        std::vector<int>::const_iterator left_end;
        std::vector<std::string>::const_iterator right_end;
        std::vector<std::string>::const_iterator right_start;
    };


    class Product : public Iterable{
    public:
        Product(std::vector<int>, std::vector<std::string>);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    private:
        std::vector<int> first;
        std::vector<std::string> second;
    };


    class EnumerateIterator : public IterableIterator{
    public:
        explicit EnumerateIterator(std::vector<std::string>::const_iterator b, std::vector<std::string>::const_iterator e);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override ;
    private:
        unsigned int index;
        std::vector<std::string>::const_iterator begin;
        std::vector<std::string>::const_iterator end;
    };


    class Enumerate : public Iterable{
    public:
        explicit Enumerate(std::vector<std::string> f);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    private:
        std::vector<std::string> first;
    };

}

#endif //JIMP_EXERCISES_ITERABLEITERATOR_H
