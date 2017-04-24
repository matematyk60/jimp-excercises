//
// Created by matematyk60 on 22.04.17.
//

#include "Iterable.h"

utility::ZipperIterator::ZipperIterator(std::vector<int>::iterator int_it, std::vector<std::string>::iterator string_it,
                                        std::vector<int>::iterator int_itend,
                                        std::vector<std::string>::iterator string_itend) {
    int_it_ = int_it;
    int_itend_ = int_itend;
    string_it_ = string_it;
    string_itend_ = string_itend;
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    int_it_++;
    string_it_++;
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    if(this->Dereference().first != other->Dereference().first || other->Dereference().second != this->Dereference().second){
        return true;
    } else{
        return false;
    }
}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    std::pair<int,std::string> answer {*int_it_, *string_it_};
    return answer;
}
