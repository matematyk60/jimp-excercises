//
// Created by matematyk60 on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H
#include <string>
#include <iostream>
#include <vector>
#include "StudyYear.h"

using ::std::string;

namespace academia{
    class Student{
    public:
        Student(string id = "", string first_name = "", string last_name = "", string program = "", StudyYear year = 3);
        const bool operator==(const Student &other)const;
        void ChangeFirstName(const string new_name);
        void ChangeLastName(const string new_name);
        const string Id(void)const;
        const string FirstName(void)const;
        const string LastName(void)const;
        const string Program(void)const;
        const StudyYear Year(void)const;
    private:
        string id_;
        string first_name_;
        string last_name_;
        string program_;
        StudyYear year_;
    };

    class StudentRepository{
    public:
        StudentRepository(std::initializer_list<Student> init);
        Student& operator[](const string cmp);
        unsigned long StudentCount(void)const;
        const bool operator==(const StudentRepository &other)const;
    private:
        std::vector<Student> repo_;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
