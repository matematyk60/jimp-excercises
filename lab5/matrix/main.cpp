//
// Created by janek on 03.04.17.
//

#include <iostream>
#include "Matrix.h"
using namespace std;
using namespace algebra;

int main(int argc, char* argv[]){
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 1.0i}};


    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;
    cout << endl;
    cout << endl;

    //Matrix m("[7i2 2i0 0i5; 3i0 0i2 8i0; 15i2 0i3 4i2]");
    //Matrix m("[1 2 3;3 4 5;2 3 4]");
    //Matrix m("[1 2 3;4 5 6;7 8 9]");

    //cout << "Macierz trzecia: " << m.Print() << endl;
    cout << endl;
    cout << endl;

    //cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    //cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m1)).Print() << endl;
    cout << "Mnożenie przez liczbe " << (m1.Mul(2.0)).Print() << endl;
    cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
    cout << "Dzielenie przez liczbe" << (m1.Div(3.0)).Print() << endl;
    //cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
    //cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;
}
