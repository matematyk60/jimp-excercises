//
// Created by janek on 24.04.17.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H

namespace geometry {

    class Shape {
    public:
        virtual void Draw(void)const = 0;
    };

    class SquareShape : public Shape{
    public:
        void Draw(void) const override;
    };

    class TriangleShape : public Shape{
    public:
        void Draw(void) const override;
    };

    class CircleShape : public Shape{
    public:
        void Draw(void) const override;
    };
}

#endif //JIMP_EXERCISES_SHAPE_H