//
// Created by janek on 25.04.17.
//

#include "Iterable.h"


namespace utility {
    ZipperIterator::ZipperIterator(std::vector<int>::iterator int_it, std::vector<std::string>::iterator string_it,
                                   std::vector<int>::iterator int_itend,
                                   std::vector<std::string>::iterator string_itend) {
        int_it_ = int_it;
        int_itend_ = int_itend;
        string_it_ = string_it;
        string_itend_ = string_itend;
    }

    IterableIterator &ZipperIterator::Next() {
        int_it_++;
        string_it_++;
        return *this;
    }

    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
        if (this->Dereference().first != other->Dereference().first ||
            other->Dereference().second != this->Dereference().second) {
            return true;
        } else {
            return false;
        }
    }

    std::pair<int, std::string> ZipperIterator::Dereference() const {
        std::pair<int, std::string> answer{*int_it_, *string_it_};
        return answer;
    }

    Enumerate::Enumerate(std::vector<std::string> strings) {
        enumerated_ = this->enumerate(strings);
    }

    std::vector<std::pair<int, std::string>> Enumerate::enumerate(std::vector<std::string> strings) {
        std::vector<std::pair<int, std::string>> answer;
        std::pair<int, std::string> tmp;
        int i = 1;
        for (auto n : strings) {
            tmp.first = i;
            tmp.second = n;
            answer.emplace_back(tmp);
            i++;
        }
        return answer;
    }


    std::vector<std::pair<int, std::string>>::iterator Enumerate::Begin() {
        return enumerated_.begin();
    }

    std::vector<std::pair<int, std::string>>::iterator Enumerate::End() {
        return enumerated_.end();
    }

    std::vector<std::pair<int, std::string>>::iterator Enumerate::begin() {
        return enumerated_.begin();
    }

    std::vector<std::pair<int, std::string>>::iterator Enumerate::end() {
        return enumerated_.end();
    }

    Product::Product(std::vector<int> ints, std::vector<string> strings) {
        products_ = this->product(ints, strings);
    }

    std::vector<std::pair<int, std::string>> Product::product(std::vector<int> ints, std::vector<std::string> strings) {
        std::pair<int, string> tmp;
        std::vector<std::pair<int, std::string>> answer;
        for (auto n : ints) {
            tmp.first = n;
            for (auto m : strings) {
                tmp.second = m;
                answer.emplace_back(tmp);
            }
        }
        return answer;
    }

    std::vector<std::pair<int, std::string>>::iterator Product::Begin() {
        return products_.begin();
    }

    std::vector<std::pair<int, std::string>>::iterator Product::End() {
        return products_.end();
    }

    std::vector<std::pair<int, std::string>>::iterator Product::begin() {
        return products_.begin();
    }

    std::vector<std::pair<int, std::string>>::iterator Product::end() {
        return products_.end();
    }

    Zipper::Zipper(std::vector<int> ints, std::vector<std::string> strings) {
        zipped_ = this->zip(ints, strings);
    }


    std::vector<std::pair<int, std::string>> Zipper::zip(std::vector<int> ints, std::vector<std::string> strings) {
        std::pair<int, std::string> tmp;
        std::vector<std::pair<int, std::string>> answer;
        std::vector<std::string>::iterator it = strings.begin();
        std::vector<int>::iterator it2 = ints.begin();
        while (it != strings.end() || it2 != ints.end()) {
            if (it == strings.end()) {
                tmp.second = strings[strings.size() - 1];
            } else {
                tmp.second = *it;
                it++;
            }

            if (it2 == ints.end()) {
                tmp.first = ints[ints.size() - 1];
            } else {
                tmp.first = *it2;
                it2++;
            }
            answer.emplace_back(tmp);
        }
        return answer;
    }

    std::vector<std::pair<int, std::string>>::iterator Zipper::Begin() {
        return zipped_.begin();
    }

    std::vector<std::pair<int, std::string>>::iterator Zipper::End() {
        return zipped_.end();
    }

    std::vector<std::pair<int, std::string>>::iterator Zipper::begin() {
        return zipped_.begin();
    }

    std::vector<std::pair<int, std::string>>::iterator Zipper::end() {
        return zipped_.end();
    }
}