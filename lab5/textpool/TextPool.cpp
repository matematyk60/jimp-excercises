//
// Created by janek on 03.04.17.
//

#include "TextPool.h"


namespace pool{

    TextPool::TextPool() {

    }

    TextPool::TextPool(std::initializer_list<string> str) {

    }

    TextPool::TextPool(TextPool &&xxx) {

    }

    TextPool &TextPool::operator=(TextPool &&xxx) {
        return <#initializer#>;
    }

    TextPool::~TextPool() {

    }

    std::experimental::string_view TextPool::Intern(const string &str) {
        return std::experimental::string_view();
    }

    size_t TextPool::StoredStringCount() const {
        return 0;
    }
}