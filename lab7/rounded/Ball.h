//
// Created by matematyk60 on 21.04.17.
//

#ifndef JIMP_EXERCISES_BALL_H
#define JIMP_EXERCISES_BALL_H


#include "Circle.h"

namespace geometry{
    class Ball : public Circle{
    public:
        Ball(double x = 0, double y = 0, double z = 0, double r = 0);
        double Surface(void)const;
    private:
        double z_;
    };
}


#endif //JIMP_EXERCISES_BALL_H
