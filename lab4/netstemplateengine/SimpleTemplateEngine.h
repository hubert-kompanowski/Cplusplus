//
// Created by abrajner on 26.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <regex>
#include <map>
#include <iostream>
namespace  nets {
    class View {
    public:
        View();
        View(std::string view);
        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:
        std::string view_value;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
