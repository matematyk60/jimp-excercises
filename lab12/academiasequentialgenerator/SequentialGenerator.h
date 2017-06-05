//
// Created by janek on 05.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <class TId, class TCounter>
class SequentialIdGenerator {
public:
    SequentialIdGenerator() {
        first_ = true;
        counter_ = 0;
    }

    SequentialIdGenerator(const TCounter &value) {
        first_ = true;
        counter_ = value;
    }

    TId NextValue() {
        if (!first_) {
            ++counter_;
        }
        first_ = false;
        return TId(counter_);
    }

private:
    bool first_;
    TCounter counter_;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
