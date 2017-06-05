//
// Created by janek on 30.05.17.
//

#include <iostream>
#include "Tree.h"

using namespace tree;
using namespace std;

int main() {
    //  labki:
    int p = 23;
    tree::Tree<int> P{5};

    P.Insert(1);
    P.Insert(1);
    P.Insert(5);
    P.Insert(23);

    std::cout << P.Find(0);
}