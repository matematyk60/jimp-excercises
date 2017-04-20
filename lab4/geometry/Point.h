//
// Created by matematyk60 on 21.03.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H
#include <iostream>

namespace geometry{

    class Point {
    public:

        Point();

        Point(double x, double y);

        ~Point();

        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;

        double GetX() const;

        double GetY() const;

        void SetX(double x);

        void SetY(double y);

        friend std::ostream& operator<<(std::ostream& output, const Point &p);

    private:
        double x_, y_;
    };


}



#endif //JIMP_EXERCISES_POINT_H
