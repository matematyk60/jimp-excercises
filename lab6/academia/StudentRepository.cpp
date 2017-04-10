//
// Created by matematyk60 on 04.04.17.
//

#include "StudentRepository.h"


namespace academia{
    StudyYear::StudyYear(int year) {
        year_ = year;
    }

    StudyYear::StudyYear(){
        year_ = 1;
    }

    void StudyYear::operator--(void) {
        year_ -= 1;
    }

    void StudyYear::operator++(void) {
        year_ += 1;
    }

    const bool StudyYear::operator==(const StudyYear &Year) const{
        if(Year.year_ == this->year_){
            return true;
        } else{
            return false;
        }
    }

    const bool StudyYear::operator==(int value)const {
        if(this->year_ == value){
            return true;
        } else{
            return false;
        }
    }

    StudyYear::operator int() const {
        return year_;
    }

    const bool StudyYear::operator<(const StudyYear &Year) const{
        if(this->year_ < Year.year_){
            return true;
        } else {
            return false;
        }
    }

    std::istream& operator>>(std::istream & input, StudyYear &p){
        int tmp;
        input >> tmp;
        p.year_ = tmp;
        return input;      // Umożliwia cin >> a >> b >> c;
    }

    std::ostream &operator<<(std::ostream &output, StudyYear &p) {
        output << p.year_;

        return output;
    }
}