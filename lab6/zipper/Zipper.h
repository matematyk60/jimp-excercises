//
// Created by janek on 04.04.17.
//


#ifndef JIMP_EXERCISES_POINTTEST_H
#define JIMP_EXERCISES_POINTTEST_H

#include <iostream>
#include <exception>

class Point {
public:
    Point() : x_(0), y_(0) {};

    void SetX(double x);
    void SetY(double y);

    //opcjonalna definicja pozwalająca na uzyskanie
    //dostępu do prywatnych pól z wewnątrz definicji
    //funkcji zadeklarowanej poniżej
//    friend std::istream& operator>>(std::istream &, Point&);
    friend std::ostream &operator<<(std::ostream &is, Point &point);
    friend std::istream &operator>>(std::istream &is, Point &point);


private:
    double x_, y_;
};

//właściwa deklaracja, przeciążająca
//operator >> dla strumienia wejściowego
//i klasy punkt
std::istream &operator>>(std::istream &is, Point &point);

std::ostream &operator<<(std::ostream &is, Point &point);

#endif //JIMP_EXERCISES_POINTTEST_H