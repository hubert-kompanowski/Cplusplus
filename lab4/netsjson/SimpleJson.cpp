//
// Created by hubert on 24.03.18.
//

#include "SimpleJson.h"

using namespace nets;

nets::JsonValue::JsonValue(int i){
    rodzaj_danych = 0;
    int_value = i;
}

nets::JsonValue::JsonValue(double d){
    rodzaj_danych = 1;
    double_value = d;
}

nets::JsonValue::JsonValue(bool b){
    rodzaj_danych = 2;
    bool_value = b;
}

nets::JsonValue::JsonValue(std::string s){
    rodzaj_danych = 3;
    string_value = s;
}

nets::JsonValue::JsonValue(std::vector<JsonValue> v){
    rodzaj_danych = 4;
    vector_value = v;
}

nets::JsonValue::JsonValue(std::map<std::string, nets::JsonValue> m){
    rodzaj_danych = 5;
    map_value = m;
}

std::string nets::JsonValue::string_make(std::string s) const {
    std::string temp = "\"";
    std::string str_tekst = s;

    for(char znak : str_tekst) {
        if(znak == '\"')
            temp += "\\\"";
        else if(znak == '\n')
            temp+="\\\n";
        else if(znak == '\t')
            temp+= "\\\t";
        else if (znak == '\\')
            temp+="\\\\";
        else
            temp+= znak;
    }
    temp+= "\"";
    return temp;
}

std::string nets::JsonValue::ToString() const {
    if(rodzaj_danych == 0){
        std::string wynik = std::to_string(int_value);
        return wynik;
    }

    if(rodzaj_danych == 1){
        std::stringstream stream;
        stream << double_value;
        std::string wynik = stream.str();
        return wynik;
    }

    if(rodzaj_danych == 2){
        if(bool_value) return "true";
        else return "false";
    }

    if(rodzaj_danych == 3){
        return string_make(string_value);
    }

    if(rodzaj_danych == 4){
        std::string wynik = "[";
        bool korekta = true;
        for(JsonValue i : vector_value){
            if(korekta) {
                wynik += i.ToString();
                korekta = false;
            } else {
                wynik += ", ";
                wynik += i.ToString();
            }
        }
        wynik += "]";
        return wynik;
    }

    if(rodzaj_danych == 5){
        std::string wynik="{";
        bool korekta = true;
        for(std::pair<std::string, JsonValue> para : map_value){
            if(korekta) {
                wynik += string_make(para.first);
                wynik += +": ";
                korekta = false;
            } else {
                wynik += ", \"";
                wynik += para.first;
                wynik += "\": ";
            }
            wynik += para.second.ToString();
        }
        wynik += "}";
        return wynik;
    }
}

std::experimental::optional<JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {
    if(rodzaj_danych == 5) {
        for(std::pair<std::string, JsonValue> para : map_value){
            if(para.first == name)
                return para.second;
        }
    }
    return std::experimental::optional<JsonValue>{};
}
