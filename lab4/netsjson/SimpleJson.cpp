//
// Created by matematyk60 on 27.03.17.
//

#include <sstream>
#include "SimpleJson.h"


namespace nets{
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        for(auto n : *map_){
            if(!n.first.compare(name)){
                return std::experimental::make_optional(n.second);
            }
        }
        return {};
    }

    std::string JsonValue::ToString() const {
        std::stringstream ss;

        std::string answer = "";
        if(integer_ != nullptr){
            ss << *integer_;
            ss >> answer;
            return answer;
        }

        if(float_ != nullptr){
            ss << *float_;
            ss >> answer;
            return answer;
        }

        if(string_ != nullptr){
            std::string copy = *string_;
            answer += '\"';
            for(int i = 0 ; i < copy.length() ; i++){
                if(copy[i] == '\\' || copy[i] == '\"'){
                    answer += '\\';
                }
                answer += copy[i];
            }

            answer += '\"';
            return answer;
        }

        if(boolean_ != nullptr){
            if(*boolean_){
                return "true";
            } else {
                return "false";
            }
        }

        if(vector_ != nullptr){
            answer += '[';
            for(auto n  : *vector_ ){
                answer+=n.ToString();
                answer+=", ";
            }
            answer.erase(answer.length() - 2, 2);
            answer += ']';
            return answer;
        }

        if(map_ != nullptr){
            answer += '{';
            for( auto n : *map_){
                answer += '\"';
                answer += n.first;
                answer += "\": ";
                answer += n.second.ToString();
                answer += ", ";
            }
            answer.erase(answer.length()-2,2);
            answer += '}';
            return answer;
        }





    }


    JsonValue::JsonValue(const char *text) {
        integer_ = nullptr;
        float_ = nullptr;
        boolean_ = nullptr;
        string_ = new std::string;
        *string_ = text;
        map_ = nullptr;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(std::string text) {
        integer_ = nullptr;
        float_ = nullptr;
        boolean_ = nullptr;
        string_ = new std::string;
        *string_ = text;
        map_ = nullptr;
        vector_ = nullptr;
    }


    JsonValue::JsonValue(int value) {
        integer_ = new int;
        *integer_ = value;
        float_ = nullptr;
        boolean_ = nullptr;
        string_ = nullptr;
        vector_ = nullptr;
        map_ = nullptr;
    }

    JsonValue::JsonValue(bool tf) {
        integer_ = nullptr;
        float_ = nullptr;
        boolean_ = new bool;
        *boolean_ = tf;
        string_ = nullptr;
        map_ = nullptr;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(double dbl) {
        integer_ = nullptr;
        float_ = new double;
        *float_ = dbl;
        boolean_ = nullptr;
        string_ = nullptr;
        map_ = nullptr;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> map) {
        integer_ = nullptr;
        float_ = nullptr;
        boolean_ = nullptr;
        string_ = nullptr;
        map_ = new std::map<std::string, JsonValue>;
        *map_ = map;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(std::vector<JsonValue> vec) {
        integer_ = nullptr;
        float_ = nullptr;
        boolean_ = nullptr;
        string_ = nullptr;
        map_ = nullptr;
        vector_ = new std::vector<JsonValue>;
        *vector_ = vec;
    }
/*
    JsonValue::~JsonValue(){
        if(integer_ != nullptr){
            delete integer_;
        }
        if(float_ != nullptr) {
            delete float_;
        }
        if(boolean_!= nullptr) {
            delete boolean_;
        }
        if(string_ != nullptr) {
            delete string_;
        }
        if(map_ != nullptr) {
            delete map_;
        }
        if(vector_ != nullptr) {
            delete vector_;
        }
    }
*/

}