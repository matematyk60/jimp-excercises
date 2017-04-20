//
// Created by matematyk60 on 20.04.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H
#include <string>
#include "StudyYear.h"
using std::string;


namespace academia{
    class Student{
    public:
        Student(string id = "", string first_name = "", string last_name = "", string program = "", StudyYear year = 3);
        const bool operator==(const Student &other)const;
        const bool operator<(const Student &other)const;
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
}


#endif //JIMP_EXERCISES_STUDENT_H
