//
// Created by janek on 23.05.17.
//

#include <iostream>
#include <memory>
#include "FactoryMethod.h"

using namespace std;
using namespace factoryMethod;

int main() {
    int a = 1;
    int b = 2;
    std::cout << Sum(a, b) << endl << endl;

    unique_ptr<int> p = make_unique<int>(5);
    cout << Value(p);

    return 0;
}