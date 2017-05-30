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

    bool Word::Empty() {
        return word_.empty();
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

    std::ostream &operator<<(std::ostream &output, const Word &wout) {
        output << wout.GetWord();
        return output;
    }

    std::istream &operator>>(std::istream &input, Word &obj) {
        input >> obj.word_;
        return input;
    }
}