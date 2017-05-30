//
// Created by janek on 10.04.17.
//

#include <string>
#include <iostream>
#include<initializer_list>
#include "StudyYear.h"
#include "Student.h"

using std::string;
using std::initializer_list;

namespace academia {


    Student::Student() {}

    Student::Student(string id, string first, string last, string program, int y) :
            id_(id),
            first_name_(first),
            last_name_(last),
            program_(program),
            year_(y) {}


    string Student::Id() const { return id_; }

    string Student::FirstName() const { return first_name_; }

    string Student::LastName() const { return last_name_; }

    string Student::Program() const { return program_; }

    StudyYear Student::Year() const { return year_; }

    int Student::StudentCount() { return 0; }

    void Student::ChangeFirstName(string newfirstname) { first_name_ = newfirstname; }

    void Student::ChangeLastName(string newlastname) { last_name_ = newlastname; }

    void Student::ChangeId(string newid) { id_ = newid; }

    void Student::ChangeProgram(string newprogram) { program_ = newprogram; }

    void Student::ChangeYear(int newyear) { year_ = newyear; }

    //przładowanie operatorów:
    bool operator==(const Student std, const Student std2) {
        return (std.Id() == std2.Id());
    }

    bool operator==(const Student std, string idtext) {
        return (std.Id() == idtext);
    }

    bool operator<(const Student std, const Student std2) {
        return (std.Id() < std2.Id());
    }


    std::istream &operator>>(std::istream &input, Student &student) {
        input >> student.id_ >> student.first_name_ >> student.last_name_ >> student.program_ >> student.year_;
        return input;
    }

    std::ostream &operator<<(std::ostream &output, Student &student) {
        output << "Id: " << student.Id();
        output << "First name: " << student.FirstName();
        output << "Lastname: " << student.LastName();
        output << "Program: " << student.Program();
        output << "Year: " << student.Year();
    }
}