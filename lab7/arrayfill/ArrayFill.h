//
// Created by matematyk60 on 11.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include <vector>
#include <memory>
#include <random>
using ::std::default_random_engine;
using ::std::uniform_int_distribution;

using std::unique_ptr;



namespace arrays{

    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill{
    public:
        IncrementalFill(int start);
        IncrementalFill(int start, int step);

        int Value(int index) const override;

    private:
        int start_;
        int step_;
    };

    class RandomFill : public ArrayFill{
    public:
        RandomFill(unique_ptr<default_random_engine> engine , unique_ptr<uniform_int_distribution<int>> uniform);

        int Value(int index) const override;
    private:
        unique_ptr<default_random_engine> engine_;
        unique_ptr<uniform_int_distribution<int>> uniform_;
    };

    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v);

    class SquaredFill : public ArrayFill{
    public:
        SquaredFill(int a = 1, int b = 0);

        int Value(int index) const override;

    private:
        int a_;
        int b_;
    };

}


#endif //JIMP_EXERCISES_ARRAYFILL_H
