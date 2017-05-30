//
// Created by matematyk60 on 13.03.17.
//

#include <iostream>
#include "Array2D.h"

void FillArray2D(int n_rows, int n_cols, int **array){
    for( int i = 0 ; i < n_rows ; i++){
        for (int j = 0 ; j < n_cols ; j++){
            *(*(array+i)+j) = (i*n_cols)+j+1;
        }

    }
}

int **NewArray2D(int n_rows, int n_cols){
    int **array = new int *[n_rows];

    for(int i = 0 ; i < n_rows ; i++){

        *(array + i) = new int[n_cols];

    }

    return array;
}


void DeleteArray2D(int **array, int n_rows, int n_cols){

    for(int i = 0 ; i < n_rows ; i++){

        delete [] *(array + i);

    }

    delete [] array;

}

void PrintArray2D(int **array, int n_rows, int n_cols){
    for( int i = 0 ; i < n_rows ; i++){
        for (int j = 0 ; j < n_cols ; j++){
            std::cout << *(*(array+i)+j) << " | ";
        }
        std::cout << std::endl;

    }
}