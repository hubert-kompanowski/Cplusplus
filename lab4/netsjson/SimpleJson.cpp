//
// Created by abrajner on 23.03.18.
//

#include "SimpleJson.h"

namespace nets {
    JsonValue::JsonValue(){}

    JsonValue::JsonValue(double double_v) {
        double_value = std::experimental::make_optional(double_v);
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> json_map) {
        json_map_value = std::experimental::make_optional(json_map);
        string_value =
    }

    JsonValue::JsonValue(std::vector<JsonValue> json_vector) {
        json_vector_value = std::experimental::make_optional(json_vector);
    }

    JsonValue::JsonValue(bool bool_v) {
        bool_value = std::experimental::make_optional(bool_v);
    }

    JsonValue::JsonValue(std::string str) {
        string_value = std::experimental::make_optional(str);
    }

    JsonValue::JsonValue(int integer) {
        integer_value = std::experimental::make_optional(integer);
    }

    JsonValue::~JsonValue() {}

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        if (json_map_value){
            for(auto &i: *json_map_value){
                if(i.first == name){
                    auto answ = std::experimental::make_optional(i.second);
                    return answ;
                }
            }
        }
    }

    std::string JsonValue::ToString() const {
        std::string answ;
        if(bool_value){
            if(*bool_value){
                answ = "true";
            }
            else{
                answ = "false";
            }
        }

        if(integer_value){
            answ = std::to_string(*integer_value);
        }

        if(json_map_value){
            answ = "{";
            bool key = true;
            for(auto &i: *json_map_value){
                JsonValue(i.first);
                if(key) {

                    answ = answ + "\"" + i.first + "\"" + ": " + i.second.ToString();
                    key = false;
                }
                else{
                    answ = answ + ", " + "\"" + i.first + "\"" + ": " + i.second.ToString();
                }
            }
            answ = answ + "}";
        }

        if(double_value){
            std::ostringstream strs;
            strs << (*double_value);
            answ = strs.str();
        }

        if(string_value){
            answ = "\"";
            std::string another_string = *string_value;
            for(int i = 0; i < another_string.size(); i++){
                if(another_string[i] == '\"'){
                    answ = answ + "\\"+ "\"";
                }
                else if(another_string[i]=='\\'){
                    answ += "\\";
                    answ += "\\";
                }
                else answ += another_string[i];
            }
            answ += "\"";


        }

        if(json_vector_value){
            answ = "[";
            bool key = true;
            for(auto i: (*json_vector_value)){
                if (key) {
                    answ = answ + i.ToString();
                    key = false;
                }
                else{
                    answ = answ + ", " + i.ToString();
                }
            }
            answ = answ + "]";
        }
        return answ;
    }
}