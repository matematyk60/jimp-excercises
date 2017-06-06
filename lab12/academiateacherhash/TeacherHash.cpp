//
// Created by janek on 05.06.17.
//

#include "TeacherHash.h"
namespace academia {

    Teacher::Teacher(TeacherId id, string name, string place) {
        name_ = name;
        department_ = place;
        id_ = id;
    }


    bool Teacher::operator!=(const Teacher &teacher) const {
        return !(*this == teacher);
    }

    bool Teacher::operator==(const Teacher &teacher) const {
        return (id_ == teacher.Id() and name_ == teacher.Name() and department_ == teacher.Department());
    }


    size_t TeacherHash::operator()(const Teacher &teacher) const {
        size_t hashed = std::hash<int>()(teacher.Id()) +
                        std::hash<string>()(teacher.Name()) +
                        std::hash<string>()(teacher.Department());
        return hashed;
    }
}