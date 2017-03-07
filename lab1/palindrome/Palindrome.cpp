//
// Created by matematyk60 on 06.03.17.
//

#include "Palindrome.h"

bool is_palindrome(std::string str){
    const char *characters = str.c_str();
    size_t size = str.size();

    for( int i = 0 ; i <= (size/2) ; i++ ){
        if(characters[i] != characters[size - i - 1]) {return false;}
    }
    return true;
    }