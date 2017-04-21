//
// Created by matematyk60 on 21.04.17.
//

#include <iostream>
#include "Ball.h"

namespace geometry{
    Ball::Ball(double x, double y, double z, double r) : Circle(x,y,r){
        z_ = z;
        std::cout << "konstruktor ball" << std::endl;
    }

    double Ball::Surface(void) const {
        return(4*this->Area());
    }
}