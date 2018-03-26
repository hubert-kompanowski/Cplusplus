//
// Created by abrajner on 26.03.18.
//

#include "SimpleTemplateEngine.h"

namespace  nets {
    View::View() {
        view_value = "";
    }

    View::View(std::string view) {
        view_value = view;
    }

    View::~View() {}

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::regex wzor {R"(\{\{([^{|}]+)\}\})"};

        std::smatch smatch, matches;
        std::string temp_tekst = view_value;
        std::string temp_str, wynik;

        while (std::regex_search(temp_tekst, smatch, wzor)){

            wynik += smatch.prefix();

            temp_str = smatch.str();
            if(std::regex_search(temp_str, matches, wzor)) {
                auto it = model.find(matches[1]);
                if(it != model.end()){
                    wynik += it->second;
                }
            }
            temp_tekst = smatch.suffix();
        }
        wynik += temp_tekst;

        return wynik;
    }
}

