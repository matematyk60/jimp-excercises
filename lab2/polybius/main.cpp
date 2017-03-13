//
// Created by janek on 13.03.17.
//

#include "Polybius.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string wejscie, wyjscie, message, converted;
    int a;
    cout << "Podaj nazwe pliku wejsciowego: " << endl;
    cin >> wejscie;
    cout << "Poda nazwe pliku wyjsciowego: " << endl;
    cin >> wyjscie;
    cout << "Wpisz 1 aby zaszyfrowac, lub 0 aby odszyfrowac: " << endl;
    cin >> a;

    fstream plik;
    plik.open(wejscie, std::ios::in | std::ios::out);
    if (plik.good() == true) {
        std::cout << "Uzyskano dostep do pliku!" << std::endl;
        plik >> message;
        if(a == 1) {
            converted = PolybiusCrypt(message);
        }
        else if(a == 0){
            converted = PolybiusDecrypt(message);
        }
        plik.close();
    }
    else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;


    ofstream myfile ("file.txt", ios_base::in | ios_base::app);

    if(!myfile)
        cout << "Nie można otworzyć pliku!" << endl;

    myfile << converted << endl;

    myfile.close();

    return 0;
}
