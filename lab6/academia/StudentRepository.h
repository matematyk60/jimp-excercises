//
// Created by matematyk60 on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H
#include <string>
#include <iostream>
#include <vector>
#include <StudentRepositoryQueries.h>
#include "StudyYear.h"
#include "Student.h"

using ::std::string;

namespace academia{

    class StudentRepository{
    public:
        StudentRepository(std::initializer_list<Student> init);
        Student& operator[](const string cmp);
        unsigned long StudentCount(void)const;
        const bool operator==(const StudentRepository &other)const;
        std::vector<Student> FindByQuery(const Query &query) const;
    private:
        std::vector<Student> repo_;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
