//
// Created by janek on 24.04.17.
//

#include <iostream>
#include "Shape.h"
using ::std::cout;
using std::endl;

namespace geometry {

    void SquareShape::Draw(void) const {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i % 4 == 0 || j % 4 == 0) {
                    cout << "X";
                } else {
                    cout << " ";
                }
            }
            std::cout << endl;
        }
        std::cout << endl;
    }

    void TriangleShape::Draw(void) const {
        int p = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 3 || abs(j - 2) == p) {
                    cout << "X";
                } else {
                    cout << " ";
                }
            }
            p++;
            std::cout << endl;
        }
        std::cout << endl;
    }

    void CircleShape::Draw(void) const {
        int p = 0;
        int t = 1;
        for (int i = 0; i < 9; i++) {
            if (i == 4) { t = -1; }
            for (int j = 0; j < 9; j++) {
                if (abs(j - 4) == p) {
                    cout << "X";
                } else {
                    cout << " ";
                }
            }
            p += t;
            std::cout << endl;
        }
        std::cout << endl;
    }
}