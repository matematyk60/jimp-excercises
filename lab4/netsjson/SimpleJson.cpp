//
// Created by janek on 27.03.17.
//

#include "SimpleJson.h"
#include <experimental/optional>
#include <string>

namespace nets{
    JsonValue::JsonValue() {
    }

    JsonValue::JsonValue(int numberInt){

    }

    JsonValue::JsonValue(double numberDouble){

    }

    JsonValue::JsonValue(std::string str){

    }

    JsonValue::JsonValue(bool tf){

    }

    JsonValue::JsonValue(JsonValue sth){

    }

    JsonValue::JsonValue(std::array arr){

    }

    JsonValue::~JsonValue() {
    }


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{

    }

    std::string JsonValue::ToString() const{

    }


}