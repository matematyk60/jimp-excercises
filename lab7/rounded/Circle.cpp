//
// Created by matematyk60 on 21.04.17.
//

#include <iostream>
#include "Circle.h"


namespace geometry{
    Circle::Circle(double x, double y, double r) {
        x_ = x;
        y_ = y;
        r_ = r;
        std::cout << "konstruktor circle" << std::endl;
    }

    double Circle::Area(void) const {
        return(3.1415*r_*r_);
    }
}