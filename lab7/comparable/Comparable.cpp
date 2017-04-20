//
// Created by matematyk60 on 20.04.17.
//

#include "Comparable.h"

namespace academia{

    bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) const {
        return( left.FirstName() < right.FirstName());
    }

    bool StudentComparator::operator()(const Student &left, const Student&right) {
        return this->IsLess(left,right);

    }


    bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) const {
        return( left.FirstName() > right.FirstName());
    }

    bool ByLastNameAscending::IsLess(const Student &left, const Student &right) const {
        return( left.LastName() < right.LastName());
    }

    bool ByProgramAscendingEmptyFirst::IsLess(const Student &left, const Student &right) const {
        if(left.Program() == ""){
            return true;
        }
        if(right.Program() == ""){
            return false;
        }
        return(left.Program() < right.Program());
    }

    bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) const {
        if(left.Program() == ""){
            return false;
        }
        if(right.Program() == ""){
            return true;
        }
        return(left.Program() < right.Program());
    }


}