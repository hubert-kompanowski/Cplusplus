//
// Created by hubert on 23.05.18.
//

#ifndef JIMP_EXERCISES_LOGGER_H
#define JIMP_EXERCISES_LOGGER_H



#include <iostream>
#include <memory>
using namespace std;


namespace logger {
    template<class T>
    class Logger {

    public:

        T * output_;
        enum Level{
            DEBUG,
            INFO,
            WARRNING,
            ERROR
        };
        Level x = DEBUG;


        Logger(T * output) {
            output_ = output;
        }

        void debug(const char * text) {
            if(x==DEBUG)
                *output_ << "[debug]" << text << std::endl;
        }
        void info(const char * text){
            if(x==(INFO))
                *output_ << "[warning]" << text << std::endl;
        }

        void warning(const char * text){
            if(x==(WARRNING))
            *output_ << "[error]" << text << std::endl;
        }

        void error(const char * text){
            if(x==(ERROR||DEBUG||INFO||WARRNING))
            *output_ << "[info]" << text << std::endl;
        }

    };


}


#endif //JIMP_EXERCISES_LOGGER_H
