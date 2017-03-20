//
// Created by matematyk60 on 06.03.17.
//

#include "ReverseString.h"


std::string reverse(std::string str){

    const char *characters = str.c_str();
    size_t size = str.size();
    char *reversed_characters = new char[size + 1];
    int i = 0;
    RecursiveReverse(characters, reversed_characters, &i);
    *(reversed_characters + size) = '\0';
    return std::string(reversed_characters);

}

void RecursiveReverse(const char *from, char *dest, int *i){
    if(*from == '\0'){
        return;
    } else{
        RecursiveReverse(from + 1, dest, i);
        *(dest+*i) = *(from);
        *i += 1;
        return;
    }
}

