//
// Created by janek on 19.04.17.
//

#include <iostream>
#include "Kula.h"
using namespace std;

int main() {
    Kula kul(0, 0, 0, 10);
    cout << "Pole kuli: " << kul.Pole() << endl;
    cout << "Pole przekroju: " << kul.Kolo::Pole() << endl;

    return 0;
}