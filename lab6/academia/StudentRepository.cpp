//
// Created by janek on 04.04.17.
//

#include "StudentRepository.h"

namespace academia{
    StudyYear::StudyYear() {
        year_ = 1;
    }

    StudyYear::StudyYear(int year) {
        year_ = year;
    }

    void StudyYear::operator++() {
        year_ += 1;
    }

    void StudyYear::operator--() {
        year_ -= 1;
    }

    istream& operator>>(istream &input, StudyYear &sy) {
        int d;
        input >> d;
        sy.year_ = d;
        return input;
    }

    ostream& operator<<(ostream &output, StudyYear &sy) {
        output << sy.year_;
        return output;
    }




/*

    std::istream &StudentRepository::operator>>(std::istream &input, StudentRepository &sy) {
        return input;
    }

    std::ostream &operator<<(std::ostream &output, StudentRepository &sy) {
        return output;
    }






    std::istream &Student::operator>>(std::istream &input, Student &sy) {
        return input;
    }

    std::ostream &operator<<(std::ostream &output, Student &sy) {
        return output;
    }
    */
}