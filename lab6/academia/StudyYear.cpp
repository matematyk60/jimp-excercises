//
// Created by janek on 10.04.17.
//

#include "StudyYear.h"

namespace academia {

    int StudyYear::GetYear() const {
        return studyyear_;
    }

    StudyYear &StudyYear::operator++() {
        ++studyyear_;
    }

    StudyYear StudyYear::operator++(int) {
        studyyear_++;
        return studyyear_;
    }

    StudyYear &StudyYear::operator--() {
        if (studyyear_ > 0)
            --studyyear_;
    }

    StudyYear StudyYear::operator--(int) {
        if (studyyear_ > 0)
            studyyear_--;
        return studyyear_;
    }

    bool operator>(const StudyYear oneman, const StudyYear otherman) {
        return (oneman.GetYear() > otherman.GetYear());
    }

    bool operator>=(const StudyYear oneman, const StudyYear otherman) {
        return (oneman.GetYear() >= otherman.GetYear());
    }

    bool operator<(const StudyYear oneman, const StudyYear otherman) {
        return (oneman.GetYear() < otherman.GetYear());
    }

    bool operator<=(const StudyYear oneman, const StudyYear otherman) {
        return (oneman.GetYear() <= otherman.GetYear());
    }

    std::istream &operator>>(std::istream &input, StudyYear howlongread) {
        input >> howlongread.studyyear_;
        return input;
    }

    std::ostream &operator<<(std::ostream &output, StudyYear howlong) {
        output << howlong.GetYear();
        return output;
    }

    StudyYear::operator int() const {
        return studyyear_;
    }
}