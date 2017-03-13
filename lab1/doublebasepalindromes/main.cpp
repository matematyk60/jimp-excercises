//
// Created by jan on 07.03.17.
//

#include "DoubleBasePalindromes.h"
#include <cstdio>
#include <iostream>
using namespace std;


int main(){
    int max_vaule_exculsive;
    uint64_t sum;
    cin >> max_vaule_exculsive;
    sum = DoubleBasePalindromes(max_vaule_exculsive);
    cout << sum << endl;
    return 0;
}