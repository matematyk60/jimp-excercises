//
// Created by jan on 06.03.17.
//

#include "ReverseString.h"
using namespace std;

string reverse(string str){
    const char *characters = str.c_str();
    size_t size = str.size();
    string reversed_characters = "";
    for(size_t i=0; i<size; i++){
        reversed_characters = characters[i] + reversed_characters;
    }
    return std::string(reversed_characters);
}