//
// Created by hubert on 04.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

namespace pool {

    class TextPool {

    private:
        std::set<std::experimental::string_view> pool;

    public:
        TextPool(TextPool &&other);                  //2. konstruktor przenoszący
        TextPool &operator=(TextPool &&other);       //4. operator przypisania przenoszący
        ~TextPool();                                 //5. destruktor

        TextPool();
        TextPool(std::initializer_list<std::experimental::string_view>);

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    };

}
#endif //JIMP_EXERCISES_TEXTPOOL_H
