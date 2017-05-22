//
// Created by matematyk60 on 20.04.17.
//

#include <vector>
#include "Student.h"

namespace academia{
    Student::Student(string id, string first_name, string last_name, string program, StudyYear year) {
        ValidateNames(first_name);
        ValidateNames(last_name);
        ValidateNameCharacters(first_name);
        ValidateNameCharacters(last_name);
        ValidateAge(year);
        ValidateProgram(program);
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

    void Student::ValidateNames(const string &name) {
        if(name == ""){
            throw InvalidNameSurname();
        }
    }

    void Student::ValidateNameCharacters(const string &name) {
        if(name[0] < 'A' || name[0] > 'Z'){
            throw InvalidNameCharacters();
        }
        int i = 1;
        while(name[i] != '\0'){
            if(name[i] < 'a' || name[i] > 'z'){
                throw InvalidNameCharacters();
            }
            i++;
        }
    }

    void Student::ValidateAge(int age) {
        if(age < 10 || age > 100){
            throw InvalidAge();
        }
    }

    void Student::ValidateProgram(const string &program) {
        std::vector<string> programs = {"informatyka", "ekonomia", "matematyka", "fizyka", "filozofia"};
        bool found = false;
        for( auto &n : programs){
            if( program == n){
                found = true;
                break;
            }
        }
        if(!found){
            throw InvalidProgram();
        }
    }
}
