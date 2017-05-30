//
// Created by janek on 10.04.17.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <strstream>
#include <istream>

#include "WordCounter.h"

using namespace std;

int main(int argc, char **argv) {
    datastructures::WordCounter w(argv[1]);
    cout << w;
}