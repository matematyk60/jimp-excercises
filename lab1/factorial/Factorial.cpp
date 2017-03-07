//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    if (value > 12 || value < -13) {
        return 0;
    }

    if (value > -1) {
        if (value == 0 || value == 1) {
            return 1;
        }

        int answer = value;

        while (value > 1) {
            answer = answer * --value;
        }

        return answer;
    } else {
        if (value == -1) { return -1; }
        int answer = value;
        while (value < -1) {
            answer = answer * ++value;
        }
        return answer;
    }
}