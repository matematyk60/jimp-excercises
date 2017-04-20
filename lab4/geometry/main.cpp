//
// Created by matematyk60 on 21.03.17.
//
#include <iostream>
#include "../../lab7/point3d/Point3D.h"
using namespace geometry;

int main(){
    Point3D p3D(12,31,12);//najpierw Konstruktor 2D, później kostruktor 3D
    Point p2D(0,0);
    std::cout << p2D.Distance(p3D); // następuje rzutowanie w doł Punktu 3D na punkt 2D
    Point3D p3d(1,2,3);
    std::cout << p3D << std::endl; // znów następuje rzutowanie w dół Punktu 3D na punkt 2D

}