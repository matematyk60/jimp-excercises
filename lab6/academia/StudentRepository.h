//
// Created by janek on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>

namespace academia{
    using ::std::string;
    using ::std::ostream;
    using ::std::istream;

    class StudyYear{
    public:
        StudyYear();
        StudyYear(int year);

        void operator ++();
        void operator --();

        friend std::istream& operator>>(std::istream &input, StudyYear& sy);

        friend std::ostream& operator<<(std::ostream &output, StudyYear& sy);

    private:
        int year_;
    };


/*
    class Student{
    public:
        std::istream& operator>>(std::istream &input, Student& sy);

        std::ostream& operator<<(std::ostream &output, Student& sy);

    private:
        string id_;
        string first_name_;
        string last_name_;
        string program_;
        StudyYear year_;
    };



    class StudentRepository{
    public:
        std::istream& operator>>(std::istream &input, StudentRepository& sy);

        std::ostream& operator<<(std::ostream &output, StudentRepository& sy);

    private:
        Student student;
    };
    */
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
