//
// Created by janek on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <array>

namespace nets{
    class JsonValue{
    public:

        JsonValue();

        JsonValue(int numberInt);

        JsonValue(double numberDouble);

        JsonValue(std::string str);

        JsonValue(bool tf);

        JsonValue(JsonValue sth);

        JsonValue(std::array arr);

        ~JsonValue();


        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;


    private:
        JsonValue obj;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
