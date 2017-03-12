//
// Created by jan on 06.03.17.
//
#include "DoubleBasePalindrome.h"
#include <cstdio>
using namespace std;

uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {
    uint64_t sum = 0;
    char number[1000];
    int yes;
    int digit;
    int j;
    int a, tab[10000], b;


    if (max_vaule_exculsive < 0) return 0;

    for (int k = 0; k <= max_vaule_exculsive; k++) {
        yes = 1;
        digit = sprintf(number, "%d", k);
        j = digit - 1;
        for (int i = 0; i <= j; --j, i++) {
            if (number[i] != number[j]) {
                yes = 0;
                break;
            }
        }
        if (yes) {
            b = k;
            a = 0;
            while (b > 0) {
                tab[a] = b % 2;
                b = b / 2;
                a++;
            }
            j = a-1;
            for (int i = 0; i <= j; --j, i++) {
                if (tab[i] != tab[j]) {
                    yes = 0;
                    break;
                }
            }
        }
        if (yes)
            sum += k;
    }
    return sum;
}