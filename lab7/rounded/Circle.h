//
// Created by matematyk60 on 21.04.17.
//

#ifndef JIMP_EXERCISES_CIRCLE_H
#define JIMP_EXERCISES_CIRCLE_H


namespace geometry{
    class Circle{
    public:
        Circle(double x = 0, double y = 0, double r = 0);
        double Area(void)const;
    private:
        double x_;
        double y_;
        double r_;
    };
}


#endif //JIMP_EXERCISES_CIRCLE_H
