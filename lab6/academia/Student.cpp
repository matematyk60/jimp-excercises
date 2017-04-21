//
// Created by matematyk60 on 20.04.17.
//

#include "Student.h"

namespace academia{
    Student::Student(string id, string first_name, string last_name, string program, StudyYear year) {
        id_ = id;
        first_name_ = first_name;
        last_name_ = last_name;
        program_ = program;
        year_ = year;
    }

    const bool Student::operator==(const Student &other) const {
        if(this->id_ == other.id_){
            return true;
        } else {
            return false;
        }
    }

    const bool Student::operator<(const Student &other) const {
        return(other.Id() < this->Id());
    }

    void Student::ChangeFirstName(const string new_name) {
        first_name_= new_name;
    }

    void Student::ChangeLastName(const string new_name) {
        last_name_ = new_name;
    }

    const string Student::Id(void) const {
        return id_;
    }

    const string Student::FirstName(void) const {
        return first_name_;
    }

    const string Student::LastName(void) const {
        return last_name_;
    }

    const string Student::Program(void) const {
        return program_;
    }

    const StudyYear Student::Year(void) const {
        return year_;
    }
}
