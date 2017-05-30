//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    if (value > 12 || value < -12) {
        return 0;
    }

    int sign = 1;

    if (value < 0) {
        sign = -1;
    }

    if (value == 0 || value == 1 || value == -1) {
        return 1 * sign;
    }

    int answer = value;

    while (value > 1 || value < -1) {
        value -= sign;
        answer *= value;
    }

    return answer;
}