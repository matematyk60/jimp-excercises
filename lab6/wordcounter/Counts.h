//
// Created by matematyk60 on 10.04.17.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H


namespace datastructures{
    class Counts{
    public:
        Counts();
        Counts(int number);
        int GetCounts()const;

        operator int()const;

        Counts& operator++(int);

        bool operator==(const Counts &other);
        bool operator<(const Counts &other);
        bool operator>(const Counts &other);


    private:
        int number_;
    };

};


#endif //JIMP_EXERCISES_COUNTS_H
