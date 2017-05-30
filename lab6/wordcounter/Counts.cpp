//
// Created by janek on 10.04.17.
//

#include "Counts.h"


namespace datastructures {
    Counts::Counts() {
        counts_ = 0;
    }

    Counts::Counts(int value) {
        counts_ = value;
    }

    int Counts::GetCount(void) const {
        return this->counts_;
    }

    void Counts::SetCount(int value) {
        counts_ = value;
    }


    Counts &Counts::operator++(int) {
        this->counts_++;
        return *this;
    }


    Counts::operator int() const {
        return this->counts_;
    }

    bool Counts::operator<(const Counts &other) const {
        return (this->counts_ < other.counts_);
    }

    bool Counts::operator>(const Counts &other) const {
        return (this->counts_ > other.counts_);
    }

    bool operator==(const int int_value, const Counts &other) {
        return (int_value == other.counts_);
    }
}