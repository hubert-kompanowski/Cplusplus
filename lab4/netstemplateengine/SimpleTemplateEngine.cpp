//
// Created by abrajner on 26.03.18.
//

#include "SimpleTemplateEngine.h"

namespace  nets{
    View::View(){
        view_value = "";
    }
    View::View(std::string view){
        view_value = view;
    }
    View::~View(){  }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::smatch matches;
        int i = 0;
        std::string text = view_value;
        std::regex pattern{R"({{\w+}})"};
        while(std::regex_search(text, matches, pattern)) {
            while (matches[i].matched) {
                auto it = model.find(matches.str(i));
                if (it != model.end()) {
                    std::string founded_key = it->first;
                    std::string founded_value = it->second;
                    std::regex new_pattern{R"({{+founded_key+}})"};
                    text = regex_replace(text, new_pattern, founded_value);
                } else {
                    //nie ma takiego klucza
                }
                i++;
            }
        }
        return text;
    }

}