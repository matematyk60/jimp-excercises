//
// Created by janek on 27.03.17.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"
#include <sstream>

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;
using ::std::stringstream;

namespace nets{

    JsonValue::JsonValue(int numberInt2){
        numberInt = numberInt2;
    }

    JsonValue::JsonValue(double numberDouble2){
        numberDouble = numberDouble2;
    }

    JsonValue::JsonValue(string str2){
        str = str2;
    }

    JsonValue::JsonValue(bool tf2){
        tf = tf2;
    }

    JsonValue::JsonValue(vector <JsonValue> js2){
        js = js2;
    }

    JsonValue::JsonValue(map <string, JsonValue> arr2){
        arr = arr2;
    }


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const string &name) const{

    }

    string JsonValue::ToString() const{
        string tmp;
        stringstream ss;
        //ss << "{" <<  << ":" <<  << "}";
        ss >> tmp;
        return tmp;
    }


}