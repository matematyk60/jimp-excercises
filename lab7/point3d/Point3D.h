//
// Created by matematyk60 on 20.04.17.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H


#include "Point.h"

namespace geometry{
    class Point3D : public Point{
    private:
        double z_;
    public:
        Point3D(double x, double y, double z);
        ~Point3D();
        double GetZ() const;

        void SetZ(double z);

        double Distance(const Point3D &other) const;
    };
}


#endif //JIMP_EXERCISES_POINT3D_H
