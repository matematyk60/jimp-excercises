//
// Created by matematyk60 on 10.04.17.
//

#include "Counts.h"
#include <iostream>
using std::cout;

namespace datastructures{
    int Counts::GetCounts()const{
        return number_;
    }

    Counts::Counts() {
        number_ = 0;
    }

    Counts::Counts(int number) {
        number_ = number;
    }

    Counts::operator int() const {
        return number_;
    }

    bool Counts::operator==(const Counts &other) {
        return (this->number_ == other.number_);
    }

    bool Counts::operator<(const Counts &other) {
        return (this->number_ < other.number_);
    }

    bool Counts::operator>(const Counts &other) {
        return (this->number_ > other.number_);
    }

    Counts &Counts::operator++(int) {
        this->number_++;
        //cout << "gasd" << std::endl;
        return *this;
    }

}