//
// Created by janek on 11.04.17.
//

#include <cstddef>
#include <vector>
#include "ArrayFill.h"


namespace arrays {
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    IncrementalFill::IncrementalFill(int start) {
        start_ = start;
        step_ = 1;
    }

    IncrementalFill::IncrementalFill(int start, int step) {
        start_ = start;
        step_ = step;
    }

    int IncrementalFill::Value(int index) const {
        return (start_ + index * step_);
    }

    RandomFill::RandomFill(unique_ptr<default_random_engine> engine,
                           unique_ptr<uniform_int_distribution<int>> uniform) {
        engine_ = move(engine);
        uniform_ = move(uniform);
    }

    int RandomFill::Value(int index) const {
        return (*uniform_)(*engine_);
    }


    SquaredFill::SquaredFill(int a, int b) {
        a_ = a;
        b_ = b;
    }

    int SquaredFill::Value(int index) const {
        return (a_ * index * index + b_);
    }
}