//
// Created by matematyk60 on 20.04.17.
//

#include <iostream>
#include <cmath>
#include "Point3D.h"

namespace geometry{
    Point3D::Point3D(double x, double y, double z) : Point(x,y){
        z_ = z;
        std::cout << "Konstruktor 3d" << std::endl;
    }

    Point3D::~Point3D(){
        std::cout << "Destruktor 3d" << std::endl;
    }

    double Point3D::GetZ() const {
        return z_;
    }

    void Point3D::SetZ(double z = 0) {
        z_ = z;
    }

    double Point3D::Distance(const Point3D &other) const {
        double x = other.GetX() - this->GetX();
        double y = other.GetY() - this->GetY();
        double z = other.GetZ() - this->GetZ();
        return std::sqrt(x * x + y * y + z * z);
    }

}