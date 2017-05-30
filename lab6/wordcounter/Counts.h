//
// Created by janek on 10.04.17.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

#include <iosfwd>

namespace datastructures {
    class Counts {
    public:
        Counts();

        Counts(int value);

        int GetCount(void) const;

        void SetCount(int value);


        Counts &operator++(int);

        operator int() const;


        bool operator<(const Counts &other) const;

        bool operator>(const Counts &other) const;

        friend bool operator==(const int int_value, const Counts &other_object);


        friend class WordCounter;

    private:
        int counts_;

    };

    bool operator==(const int int_value, const Counts &other_object);
}

#endif //JIMP_EXERCISES_COUNTS_H
