//
// Created by matematyk60 on 07.03.17.
//

#include "Array2D.h"
#include <iostream>

using namespace std;

int main(void){
    int n_cols, n_rows;
    int **array;

    cout << "Podaj liczbę kolumn:" << endl;
    cin >> n_cols;
    cout << "Podaj liczbę wierszy:" << endl;
    cin >> n_rows;

    array = NewArray2D(n_rows, n_cols);

    FillArray2D(n_rows, n_cols, array);

    PrintArray2D(array, n_rows, n_cols);

    DeleteArray2D(array, n_rows, n_cols);
}