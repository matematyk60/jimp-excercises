//
// Created by jan on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <map>
#include <vector>

namespace nets {
    class JsonValue {
    public:
        JsonValue(const char *);

        JsonValue(int);

        JsonValue(bool);

        JsonValue(std::string);

        JsonValue(double);

        JsonValue(std::map<std::string, JsonValue>);

        JsonValue(std::vector<JsonValue>);

        //~JsonValue();
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

    private:
        int *integer_;
        double *float_;
        std::string *string_;
        bool *boolean_;
        std::map<std::string, JsonValue> *map_;
        std::vector<JsonValue> *vector_;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H