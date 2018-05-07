//
// Created by hubert on 07.05.18.
//

#include "MovieSubtitles.h"

int main(){
    int offset = 20*2300/1000;

    std::regex wzor {R"(\{([\d]+)\}\{([\d]+)\}([^\n]+)\n)"};

    std::string temp_tekst = "{0}{100}{y:b}bold text\n{144}{299}{s:12}12 Font used\n{280}{350}{c:$0000FF}Hello!\n{1000}{1050}Multi|Line|Text\n";
    std::string temp_str, wynik;
    int pierwsza, druga;
    std::smatch smatch, matches;
    int linia = 1;
    std::stringstream s1, s2, s3;


    while (std::regex_search(temp_tekst, smatch, wzor)){
        s1.clear();
        s1.str(smatch[1]);
        s2.clear();
        s2.str(smatch[2]);

        s1 >> pierwsza;
        s2 >> druga;

        pierwsza += offset;
        druga += offset;

        wynik += "{" + std::to_string(pierwsza) + "}{" + std::to_string(druga) + "}";
        wynik += smatch[3];
        wynik += "\n";

        temp_tekst = smatch.suffix();
        linia++;
    }
    std::cout << wynik;
}


/*
 * std::__cxx11::smatch matches;

    if(std::regex_match(url, matches, wzor)){
        return matches[x];
    }
    else return "";
 */