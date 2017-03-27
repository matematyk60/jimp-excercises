//
// Created by janek on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
using ::std::map;
using ::std::string;
using ::std::vector;

namespace nets{
    class JsonValue{
    public:

        JsonValue(){};

        ~JsonValue(){};

        JsonValue(int numberInt2);

        JsonValue(double numberDouble2);

        JsonValue(string str2);

        JsonValue(bool tf2);


        JsonValue(vector <JsonValue> js2);

        JsonValue(map <string, JsonValue> arr2);


        std::experimental::optional<JsonValue> ValueByName(const string &name) const;

        string ToString() const;


    private:
        string str;
        bool tf;
        int numberInt;
        double numberDouble;
        map <string, JsonValue> arr;
        vector <JsonValue> js;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H