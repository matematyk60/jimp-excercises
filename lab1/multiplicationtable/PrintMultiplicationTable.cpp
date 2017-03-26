//
// Created by jan on 07.03.17.
//

#include "PrintMultiplicationTable.h"
#include <iostream>
using namespace std;

void PrintMultiplicationTable(int tab[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout.width(4);
            cout << tab[i][j];
        }
        cout << endl;
    }
}