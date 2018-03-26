//
// Created by hubert on 18.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H

#include <iostream>
#include <string>
#include <cstdint>
#include <regex>

namespace nets {

    class SimpleUrl {

    public:
        SimpleUrl(const std::__cxx11::basic_string<char>&);

        std::string get_match(std::__cxx11::regex wzor, int x) const;

        std::string Login() const;
        std::string Host() const;
        std::string Path() const;
        std::string Scheme() const;
        std::string Query() const;
        std::string Fragment() const;
        uint16_t Port() const;

    private:
        std::string url;
    };


}
#endif //JIMP_EXERCISES_SIMPLEURL_H
