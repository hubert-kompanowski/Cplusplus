//
// Created by hubert on 04.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <initializer_list>
#include <sstream>
#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <set>

namespace datastructures {

    class Word{
    public:
        Word(std::string);
        void Set_word(std::string);
        std::string Get_word() const;
        bool operator==(Word) const;
        bool operator<(const Word&)const;


    private:
        std::string word;

    };


    class Counts{
    public:
        Counts(int);
        void Set_counter(int);
        int Get_counter() const;
        Counts &operator++(int);
        Counts &operator++();
        bool operator==(Counts) const;
        bool operator>(Counts) const;
        bool operator<(Counts) const;

    private:
        int counter;
    };


    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word>);
        WordCounter(std::vector<Word>);

        WordCounter(WordCounter&);
        WordCounter(const WordCounter&);
        WordCounter&operator=(WordCounter&);
        WordCounter& operator=(const WordCounter&);
        ~WordCounter();

        static WordCounter FromInputStream(std::istream&);
        int operator[](std::string);
        size_t DistinctWords();
        size_t TotalWords();
        std::set<Word> Words();

        friend std::ostream& operator<<(std::ostream& output,const WordCounter& WordC);

    private:
        std::vector<std::pair<Word, Counts>> dict_vector;
    };

    std::ostream& operator<<(std::ostream&,const WordCounter&);
    bool compare(std::pair<Word, Counts> temp1, std::pair<Word, Counts> temp2);


}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
