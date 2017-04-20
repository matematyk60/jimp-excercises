//
// Created by matematyk60 on 20.04.17.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H


#include "../../lab6/academia/StudentRepository.h"

namespace academia{
    class StudentComparator{
    public:
        virtual bool IsLess(const Student &left, const Student &right) const = 0;
        bool operator()(const Student &left, const Student&right);
    };
    class ByFirstNameAscending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) const override;
    };
    class ByFirstNameDescending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) const override;
    };
    class ByLastNameAscending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) const override;
    };
    class ByProgramAscendingEmptyFirst : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) const override;
    };
    class ByProgramAscendingEmptyLast : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) const override;
    };
}


#endif //JIMP_EXERCISES_COMPARABLE_H
