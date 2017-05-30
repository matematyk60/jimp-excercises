//
// Created by matematyk60 on 21.03.17.
//


#include "Square.h"
#include <iostream>

using std::cout;
using std::endl;

namespace geometry{
    Square::Square() {
        cout << "Konstruktor bezparametrowy" << endl;
    }

    Square::Square(Point A, Point B, Point D, Point C) {
        cout << "Konstruktor parametrowy" << endl;
        if(A.Distance(C) != B.Distance(D)){
            A_.SetX(0);
            A_.SetY(0);
            B_.SetX(0);
            B_.SetY(0);
            C_.SetX(0);
            C_.SetY(0);
            D_.SetX(0);
            D_.SetY(0);
        } else{
            A_ = A;
            B_ = B;
            C_ = C;
            D_ = D;
        }


    }

    double Square::Circumference() const {
        return A_.Distance( B_)*4;
    }

    double Square::Area() const {
        return A_.Distance( B_)*A_.Distance( B_);
    }
}