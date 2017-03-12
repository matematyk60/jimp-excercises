//
// Created by jan on 06.03.17.
//

#include "Palindrome.h"
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str) {
    unsigned long long int n;
    n = str.length();
    unsigned long long int j = n - 1;
    for (unsigned long long int i = 0; i < (n / 2); --j, i++) {
        if (str[i] != str[j])
            return false;
    }
    return true;
}
