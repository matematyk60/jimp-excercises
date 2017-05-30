//
// Created by janek on 03.04.17.
//

#include "TextPool.h"

namespace pool{
    std::experimental::string_view TextPool::Intern(const std::string &str) {
        for(auto n : List_){
            if (!n.compare(str)){
                return std::experimental::string_view(n);
            }
        }
        //else
        List_.emplace_back(str);
        return std::experimental::string_view(List_[List_.size()-1]);
    }

    size_t TextPool::StoredStringCount() const {
        return List_.size();
    }

    TextPool::TextPool() {
        List_.clear();
    }

    TextPool::TextPool(const std::initializer_list<const char*> &elements) {
        List_.clear();
        bool issomewhere = false;
        for (auto n : elements) {
            for (auto m : List_)
                if (!m.compare(n)) {
                    issomewhere = true;
                    break;
                }
            if (!issomewhere) {
                List_.emplace_back(n);
            }
            issomewhere = false;
        }
    }

    TextPool &TextPool::operator=(TextPool &&Pool) {
        if(this == &Pool){
            return Pool;
        }

        List_.clear();
        std::swap(List_, Pool.List_);
    }

    TextPool::TextPool(TextPool &&Pool) {
        List_.clear();
        std::swap(List_, Pool.List_);
    }

    TextPool::~TextPool() {
        List_.clear();
    }
}