//
// Created by matematyk60 on 06.03.17.
//

#include "ReverseString.h"


std::string reverse(std::string str){

    const char *characters = str.c_str(); //uzyskanie z obiektu string wskaźnika na poszczególne znaki
    size_t size = str.size(); //uzyskanie z obiektu string ilości znaków
    char *reversed_characters = new char[size + 1];//utworzenie nowego obiektu string na podstawie innego char*, char[], itp..
    int i = 0;
    reversing(characters, reversed_characters, &i);
    *(reversed_characters + i) = '\0';
    return std::string(reversed_characters);

}

void reversing(const char *from, char *where, int *i){
    if(*from == '\0'){return;}
    else{
        reversing(from + 1, where, i);
        *(where+*i) = *(from);
        *i = *i + 1;
        return;
    }
}

