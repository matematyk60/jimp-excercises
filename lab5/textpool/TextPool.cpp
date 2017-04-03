//
// Created by janek on 03.04.17.
//

#include "TextPool.h"


namespace pool{

    TextPool::TextPool() {
    }

    TextPool::TextPool(std::initializer_list<string> str) {
        std::initializer_list<string>::iterator it;
        if (pula.size() == 0)
            for (it = str.begin(); it != str.end(); ++it)
                pula.insert(pula.end(), *it);
        else
            for (it = str.begin(); it != str.end(); ++it)
                Intern(*it);
    }

    TextPool::TextPool(TextPool &&xxx) {
    }

    TextPool &TextPool::operator=(TextPool &&xxx) {
        return xxx;
    }

    TextPool::~TextPool() {
    }

    std::experimental::string_view TextPool::Intern(const string &str) {
        if (pula.find(str) != pula.end())
            return std::experimental::string_view();
        else {
            pula.emplace(pula.end(), str);
            return std::experimental::string_view();
        }
    }

    size_t TextPool::StoredStringCount() const {
        size_t siz = pula.size();
        return siz;
    }
}