//
// Created by hubert on 24.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <sstream>
#include <vector>
#include <map>


namespace nets {

    class JsonValue {

    public:
        JsonValue(int);
        JsonValue(double);
        JsonValue(bool);
        JsonValue(std::string);
        JsonValue(std::vector<JsonValue>);
        JsonValue(std::map<std::string, nets::JsonValue>);

        std::string string_make(std::string) const;
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        int rodzaj_danych;
        int int_value;
        double double_value;
        bool bool_value;
        std::string string_value;
        std::vector<nets::JsonValue> vector_value;
        std::map<std::string, nets::JsonValue> map_value;
    };

}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
