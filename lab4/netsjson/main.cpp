//
// Created by jan on 27.03.17.
//
#include "SimpleJson.h"
#include <iostream>

using std::cout;
using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;


using namespace nets;

int main(){
    JsonValue str(R"(\\\\\\\"http:\\\\\\\"klmno)");
    cout << str.ToString();


}


