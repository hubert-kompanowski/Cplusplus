//
// Created by abrajner on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <regex>

namespace nets {
    class JsonValue {
    public:
        JsonValue();
        JsonValue(int integer);
        JsonValue(std::string str);
        JsonValue(double double_v);
        JsonValue(bool bool_v);
        JsonValue(std::vector <JsonValue> json_vector);
        JsonValue(std::map <std::string, JsonValue> json_map);
        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    private:
        std::experimental::optional <int> integer_value;
        std::experimental::optional <double> double_value;
        std::experimental::optional <std::string> string_value;
        std::experimental::optional <bool> bool_value;
        std::experimental::optional <std::vector<JsonValue>> json_vector_value;
        std::experimental::optional <std::map <std::string, JsonValue>> json_map_value;

    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
