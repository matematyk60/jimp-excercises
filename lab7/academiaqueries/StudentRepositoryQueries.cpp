//
// Created by matematyk60 on 20.04.17.
//

#include <curses.h>
#include "StudentRepositoryQueries.h"

namespace academia{
    bool ByFirstName::Accept(const academia::Student &student)const {
        if(name_ == student.FirstName()){
            return true;
        } else{
            return false;
        }
    }

    ByFirstName::ByFirstName(string name) {
        name_ = name;
    }

    ByLastName::ByLastName(string name) {
        name_ = name;
    }

    bool ByLastName::Accept(const Student &student) const {
        if(name_ == student.LastName()){
            return true;
        } else{
            return false;
        }
    }



    ByOneOfPrograms::ByOneOfPrograms(std::initializer_list<string> elements) {
        for(auto n : elements){
            programs_.emplace_back(n);
        }
    }

    bool ByOneOfPrograms::Accept(const Student &student) const {
        for(const auto &n : programs_){
            if(student.Program() == n){
                return true;
            }
        }
        //else
        return false;
    }



    ByYearLowerOrEqualTo::ByYearLowerOrEqualTo(StudyYear year) {
        year_ = year;
    }


    bool ByYearLowerOrEqualTo::Accept(const Student &student) const {
        return (student.Year() <= year_);
    }



    OrQuery::OrQuery(unique_ptr<Query> q1, unique_ptr<Query> q2) {
        q1_ = move(q1);
        q2_ = move(q2);
    }


    bool OrQuery::Accept(const Student &student) const {
        return(q1_->Accept(student) || q2_->Accept(student));
    }


    AndQuery::AndQuery(unique_ptr<Query> q1, unique_ptr<Query> q2) {
        q1_ = move(q1);
        q2_ = move(q2);
    }

    bool AndQuery::Accept(const Student &student) const {
        return(q1_->Accept(student) && q2_->Accept(student));
    }
}
