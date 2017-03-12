//
// Created by jan on 07.03.17.
//

#include "MultiplicationTable.h"
#include "PrintMultiplicationTable.h"
#include <iostream>
using namespace std;

int main(){
    int tab[10][10];
    MultiplicationTable(tab);
    PrintMultiplicationTable(tab);
    return 0;
}