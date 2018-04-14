//
// Created by hubert on 04.04.18.
//

#include "WordCounter.h"


using namespace datastructures;


bool isWhiteSpace(char a){
    return (a==' ' || a=='\t' || a =='\n');
}


Word::Word(std::string w) {
    word = w;
}
std::string Word::Get_word() const{
    return word;
}
void Word::Set_word(std::string w) {
    word = w;
}
bool Word::operator==(Word w) const {
    if(this->Get_word() == w.Get_word()){
        return true;
    }
    else
        return false;
}
bool Word::operator<(const Word & other) const {
    return this->Get_word() < other.Get_word();
}


Counts::Counts(int c) {
    counter = c;
}
int Counts::Get_counter() const{
    return counter;
}
void Counts::Set_counter(int c) {
    counter = c;
}
Counts &Counts::operator++(int) {
    counter++;
}
Counts& Counts::operator++() {
    ++counter;
}
bool Counts::operator==(Counts c) const {
    if(this->Get_counter() == c.Get_counter()){
        return true;
    }
    return false;
}
bool Counts::operator>(Counts c) const {
    if(this->Get_counter() > c.Get_counter()){
        return true;
    }
    return false;
}
bool Counts::operator<(Counts c) const {
    if(this->Get_counter() < c.Get_counter()){
        return true;
    }
    return false;
}


WordCounter::WordCounter() {
}
WordCounter::WordCounter(std::initializer_list<Word> list) {
    for(Word v : list){
        bool flag = true;
        for(int i=0; i < dict_vector.size(); i++) {
            if(dict_vector[i].first == v){
                dict_vector[i].second++;
                flag = false;
                break;
            }
        }
        if(flag) {
        std::pair<Word, Counts> x = {v, Counts(1)};
        dict_vector.push_back(x);
        }
    }
}
WordCounter::WordCounter(std::vector<Word> list) {
    for(Word v : list){
        bool flag = true;
        for(int i=0; i < dict_vector.size(); i++) {
            if(dict_vector[i].first == v){
                dict_vector[i].second++;
                flag = false;
                break;
            }
        }
        if(flag) {
            std::pair<Word, Counts> x = {v, Counts(1)};
            dict_vector.push_back(x);
        }
    }
}
WordCounter::WordCounter(WordCounter& other){
    dict_vector = other.dict_vector;
    other.dict_vector.clear();
}
WordCounter::WordCounter(const WordCounter& other){
    dict_vector = other.dict_vector;
}
WordCounter& WordCounter::operator=(WordCounter& other){
    dict_vector = other.dict_vector;
    other.dict_vector.clear();
}
WordCounter& WordCounter::operator=(const WordCounter& other){
    dict_vector = other.dict_vector;
}
WordCounter::~WordCounter(){
}
WordCounter WordCounter::FromInputStream(std::istream& is) {
    std::string word, temp;
    std::stringstream buf;
    buf << is.rdbuf();
    word = buf.str();
    std::vector<Word> list;

    for(auto x : word){
        if(isWhiteSpace(x)){
            if(temp != ""){
                list.push_back(temp);
                temp = "";
            }
            continue;
        }
        temp += x;
    }
    if(temp != ""){
        list.push_back(temp);
    }
    return WordCounter(list);
}
int WordCounter::operator[](std::string s) {
    for(std::pair<Word, Counts> p : dict_vector){
        if(p.first == Word(s)){
            return p.second.Get_counter();
        }
    }
    return 0;
}
std::ostream& datastructures::operator<<(std::ostream& op, const WordCounter& word) {
    std::vector<std::pair<Word, Counts>> temp = word.dict_vector;
    sort(temp.begin(), temp.end(), compare);
    for(auto x : temp){
        op << x.first.Get_word();
        op << " - ";
        std::stringstream stream1;
        stream1 << x.second.Get_counter();
        op << stream1.str();
        op << ", ";
    }
    return op;

}
bool datastructures::compare(std::pair<Word, Counts> temp1, std::pair<Word, Counts> temp2) {
    return temp1.second.Get_counter() > temp2.second.Get_counter();
}
size_t WordCounter::DistinctWords() {
    return dict_vector.size();
}
size_t WordCounter::TotalWords() {
    size_t result = 0;
    for(auto x : this->dict_vector){
        result += x.second.Get_counter();
    }
    return result;
}
std::set<Word> WordCounter::Words() {
    std::set<Word> result;
    for(auto x : this->dict_vector){
        result.emplace(x.first);
    }
    return result;
}

