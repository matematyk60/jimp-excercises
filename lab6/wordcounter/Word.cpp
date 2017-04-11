//
// Created by matematyk60 on 10.04.17.
//

#include "Word.h"

namespace datastructures{
    Word::Word(){
        word_ = "";
    }

    Word::Word(const char *text) {
        word_ = text;
    }

    bool Word::operator==(const Word &other)const{
        return (this->word_ == other.word_);
    }

    bool Word::operator<(const Word &other) const {
        return (this->word_ < other.word_);
    }

    bool Word::operator>(const Word &other) const {
        return (this->word_ > other.word_);
    }

    string Word::GetWord() const{
        return word_;
    }

}