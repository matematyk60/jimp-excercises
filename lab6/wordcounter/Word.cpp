//
// Created by janek on 10.04.17.
//

#include "Word.h"

namespace datastructures {
    using ::std::string;
    using ::std::ostream;

    Word::Word() {
        word_ = "";
    }

    Word::Word(const string &word) {
        word_ = word;
    }

    bool Word::operator==(const Word &other) const {
        return (this->word_ == other.word_);
    }

    bool Word::operator<(const Word &other) const {
        return (this->word_ < other.word_);
    }

    bool Word::operator>(const Word &other) const {
        return (this->word_ > other.word_);
    }

    std::string Word::GetWord(void) const {
        return this->word_;
    }
}