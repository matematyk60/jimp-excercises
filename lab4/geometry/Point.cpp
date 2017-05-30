//
// Created by matematyk60 on 21.03.17.
//

#include <cmath>
#include <ostream>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;


namespace geometry{
    Point::Point():x_(0),y_(0){
        cout << "Konstruktor bezparametrowy" << endl;
    }

    Point::Point(double x, double y) {
        cout << "Konstruktor parametrowy" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        cout << endl;
    }

    void Point::ToString(std::ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

    double Point::GetX() const {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x) {
        x_ = x;
    }

    void Point::SetY(double y) {
        y_ = y;
    }

    std::ostream& operator<<(std::ostream& out, const Point &other){
        out<<"("<<other.GetX()<<", "<<other.GetY()<<")";
    }
}


