//
// Created by janek on 05.06.17.
//

#include <iostream>
#include "TreeIterators.h"

using namespace tree;
using namespace std;

int main() {
    Tree<int> tree{5};
    tree.Insert(9);


    /*
    cout << "PreOrder: ";
    for (const int &value_in_tree : PreOrder(tree)) {
        cout << value_in_tree << " ";
    }
    cout << "InOrder: ";
    for (const int &value_in_tree : InOrder(tree)) {
        cout << value_in_tree << " ";
    }
    cout << "PostOrder: ";
    for (const int &value_in_tree : PostOrder(tree)) {
        cout << value_in_tree << " ";
    }
     */
}