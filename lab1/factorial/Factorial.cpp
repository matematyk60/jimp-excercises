//
// Created by jan on 02.02.17.
//
#include "Factorial.h"

long long int factorial(int value) {
  long long int suma = 1;
  if (value == 0 || value == 1) return 1;
  else if(value >= 13) return 0;
  else if (value > 1) {
    for (int i = 2; i <= value; i++) {
      suma = suma * i;
    }
    return suma;
  } else if (value < 0) {
    for (int i = value; i < 0; i++) {
      suma = suma * i;
    }
    return suma;
  }
}
