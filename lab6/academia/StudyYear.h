//
// Created by matematyk60 on 16.04.17.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H




#include <string>
#include <iostream>
using ::std::string;

namespace academia {
    class StudyYear {
    public:
        StudyYear();

        StudyYear(int year);

        void operator--(void);

        void operator++(void);

        friend std::istream &operator>>(std::istream &input, StudyYear &Year);

        friend std::ostream &operator<<(std::ostream &output, StudyYear &Year);

        const bool operator==(const StudyYear &Year) const;

        const bool operator<(const StudyYear &Year) const;

        const bool operator==(int value) const;

        operator int() const;


    private:
        int year_;
    };
}

#endif //JIMP_EXERCISES_STUDYYEAR_H
