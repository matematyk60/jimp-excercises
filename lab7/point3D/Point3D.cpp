//
// Created by janek on 19.04.17.
//

#include "Point3D.h"
#include <iostream>
#include <cmath>

namespace geometry {
    double Punkt3d::GetZ() const {
        return z_;
    }

    void Punkt3d::SetZ(double z = 0) {
        z_ = z;
    }

    double Punkt3d::Distance(const Punkt3d &other) const {
        double x = other.GetX() - this->GetX();
        double y = other.GetY() - this->GetY();
        double z = other.GetZ() - this->GetZ();
        return std::sqrt(x * x + y * y + z * z);
    }
}