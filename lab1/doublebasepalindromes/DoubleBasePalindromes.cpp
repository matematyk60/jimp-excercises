//
// Created by matematyk60 on 07.03.17.
//

#include "DoubleBasePalindromes.h"
#include <ReverseString.h>
#include <Palindrome.h>

using namespace std;

string ToBinary(int value){
    string binary;
    while(value != 0){
        binary+=to_string(value%2);
        value = value / 2;
    }
    binary = reverse(binary);
    return binary;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    string stringDecimal, binary;
    uint64_t sum = 0;

    for( int i = 0 ; i < max_vaule_exculsive ; i++) {
        stringDecimal = to_string(i);
        if (IsPalindrome(stringDecimal)) {
            binary = ToBinary(i);
            if (IsPalindrome(binary)) {
                sum += i;
            }
        }
    }

    return sum;

    }


