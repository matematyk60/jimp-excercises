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
        static void ValidateNames(const string &name);
        static void ValidateNameCharacters(const string &name);
        static void ValidateAge(int age);
        static void ValidateProgram(const string &program);
    private:
        string id_;
        string first_name_;
        string last_name_;
        string program_;
        StudyYear year_;
    };

    class StudentValidationError : public std::invalid_argument{
    public:
        StudentValidationError(string message = "ERROR") : std::invalid_argument(message){}
        virtual ~StudentValidationError() {};
    };

    class InvalidNameSurname : public StudentValidationError{
    public:
        InvalidNameSurname() : StudentValidationError("Invalid name/surname"){}
    };

    class InvalidNameCharacters : public StudentValidationError{
    public:
        InvalidNameCharacters() : StudentValidationError("Invalid name characters"){}
    };

    class InvalidAge : public StudentValidationError{
    public:
        InvalidAge() : StudentValidationError("Invalid AGE!"){}
    };

    class InvalidProgram : public StudentValidationError{
    public:
        InvalidProgram() : StudentValidationError("Invalid Program!"){}
    };
}


#endif //JIMP_EXERCISES_STUDENT_H
