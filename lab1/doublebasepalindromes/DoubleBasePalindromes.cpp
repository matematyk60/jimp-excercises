//
// Created by matematyk60 on 07.03.17.
//

#include "DoubleBasePalindromes.h"

using namespace std;

string DecimalToBinary(int DecimalValue){
    string Binary;
    while(DecimalValue != 0){
        Binary+=to_string(DecimalValue%2);
        DecimalValue =  DecimalValue / 2;
    }
    return Binary;
}

bool is_palindrome(std::string str){
    const char *characters = str.c_str();
    size_t size = str.size();

    for( int i = 0 ; i <= (size/2) ; i++ ){
        if(characters[i] != characters[size - i - 1]) {return false;}
    }
    return true;
}




uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    string StringDecimal, Binary;
    uint64_t sum = 0;

    for( int i = 0 ; i < max_vaule_exculsive ; i++) {
        StringDecimal = to_string(i);
        if (is_palindrome(StringDecimal)) {
            Binary = DecimalToBinary(i);
            if (is_palindrome(Binary)) { sum += i; }
        }
    }
    return sum;

    }


