//
// Created by matematyk60 on 03.04.17.
//

#include "TextPool.h"

namespace pool{

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        for(auto n : List_){
            if (!n.compare(str)){
                return n;
            }
        }
        //else
        List_.emplace_back(str);
        return List_[List_.size()-1];
    }

    size_t TextPool::StoredStringCount() const {
        return List_.size();
    }

    TextPool::TextPool() {
        List_.clear();
    }

    TextPool::TextPool(const std::initializer_list<const char*> &elements) {
        List_.clear();
        bool is_already_here = false;
        for (auto n : elements) {
            for (auto m : List_)
                if (!m.compare(n)) {
                    is_already_here = true;
                    break;
                }
            if (!is_already_here) {
                List_.emplace_back(n);
            }
            is_already_here = false;
        }
    }

    TextPool &TextPool::operator=(TextPool &&Pool) {
        if(this == &Pool){
            return Pool;
        }

        List_.clear();
        std::swap(List_, Pool.List_);
        return Pool;
    }

    TextPool::TextPool(TextPool &&Pool) {
        List_.clear();
        std::swap(List_, Pool.List_);
    }

    TextPool::~TextPool() {
    }
}

