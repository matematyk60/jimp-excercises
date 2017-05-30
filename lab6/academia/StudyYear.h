//
// Created by janek on 10.04.17.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

#include <iostream>

using std::string;
namespace academia {

    class StudyYear {
    public:

        StudyYear() : studyyear_(1) {};

        StudyYear(int yr) : studyyear_(yr) {};

        int GetYear() const;


        StudyYear &operator++();

        StudyYear operator++(int);

        StudyYear &operator--();

        StudyYear operator--(int);

        operator int() const;

        friend std::istream &operator>>(std::istream &is, StudyYear howlongread);


    private:
        int studyyear_;
    };

    bool operator>(const StudyYear oneman, const StudyYear otherman);

    bool operator>=(const StudyYear oneman, const StudyYear otherman);

    bool operator<(const StudyYear oneman, const StudyYear otherman);

    bool operator<=(const StudyYear oneman, const StudyYear otherman);


    std::istream &operator>>(std::istream &input, StudyYear howlongread);

    std::ostream &operator<<(std::ostream &output, StudyYear howlong);
}

#endif //JIMP_EXERCISES_STUDYYEAR_H
