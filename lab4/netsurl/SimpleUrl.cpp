//
// Created by hubert on 18.03.18.
//

#include "SimpleUrl.h"

using namespace nets;


SimpleUrl::SimpleUrl(const std::__cxx11::basic_string<char>& x){
    url = x;
}

std::string SimpleUrl::get_match(std::__cxx11::regex wzor, int x) const {
    std::__cxx11::smatch matches;

    if(std::regex_match(url, matches, wzor)){
        return matches[x];
    }
    else return "";
}

std::string SimpleUrl::Login() const{
    std::regex wzor {R"((\S*)\:(\w+)\@(\S*))"};
    return get_match(wzor, 2);
}

std::string SimpleUrl::Host() const{
    std::regex wzor {R"(([^/]*)((\/\/)|\@)([^(/|@|?|&|:)]*)(\S*))"};
    return get_match(wzor, 4);
}

std::string SimpleUrl::Path() const{
    std::regex wzor {R"(([^\/]*)\/\/([^\/]*)\/([^(\?|\#)]*)(\S*))"};
    return get_match(wzor, 3);
}

std::string SimpleUrl::Scheme() const{
    std::regex wzor {R"(([^\:]*):(\S*))"};
    return get_match(wzor, 1);
}

std::string SimpleUrl::Query() const{
    std::__cxx11::regex wzor {R"(([^\?]*)\?([^\?]*))"};
    return get_match(wzor, 2);
}

std::string SimpleUrl::Fragment() const{
    std::__cxx11::regex wzor {R"(([^\#]*)#([^\#]*))"};
    return get_match(wzor, 2);
}

uint16_t SimpleUrl::Port() const{

    std::regex wzor {R"(([^\:]*):([^\:]*):([0-9]*)([^\:]*))"};
    std::string temp  = get_match(wzor, 3);

    if(temp != "") {
        std::stringstream stream1;
        uint16_t result;
        stream1.str(temp);
        stream1 >> result;
        return result;
    }

    uint16_t port=0;

    if(SimpleUrl::Scheme() == "http") port = 80;
    if(SimpleUrl::Scheme() == "https") port = 443;
    if(SimpleUrl::Scheme() == "ftp") port = 22;
    if(SimpleUrl::Scheme() == "mail") port = 0;

    return port;
}