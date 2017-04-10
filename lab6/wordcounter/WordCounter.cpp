//
// Created by janek on 10.04.17.
//

#include "WordCounter.h"


namespace datastructures {
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


    Counts::Counts() {
        counts_ = 0;
    }

    Counts::Counts(int value) {
        counts_ = value;
    }

    int Counts::GetCounts(void) const {
        return this->counts_;
    }

    void Counts::SetCount(int value) {
        counts_ = value;
    }


    Counts &Counts::operator++(int) {
        this->counts_++;
        return *this;
    }


    Counts::operator int() const {
        return this->counts_;
    }

    bool Counts::operator<(const Counts &other) const {
        return (this->counts_ < other.counts_);
    }

    bool Counts::operator>(const Counts &other) const {
        return (this->counts_ > other.counts_);
    }

    bool operator==(const int int_value, const Counts &other) {
        return (int_value == other.counts_);
    }


    WordCounter::WordCounter() {}

    WordCounter::WordCounter(const char *file) {
        ifstream file_open;
        file_open.open(file);
        if (file_open.good()) {
            string word = "";
            string tmpstr = "";
            while (file_open >> word) {
                tmpstr = "";
                for (char c:word) {
                    if (c >= 65 and c <= 90) {
                        c += 32;
                    }
                    if (c >= 97 and c <= 122) {
                        tmpstr.push_back(c);
                    }
                }
                Word tmp_word(tmpstr);
                bool is_word = false;
                for (pair<Word, Counts> &n: this->wordcontainer_) {
                    if (tmp_word == n.first) {
                        n.second++;
                        is_word = true;
                        break;
                    }
                }
                if (is_word == false) {
                    this->wordcontainer_.push_front(pair<Word, Counts>{tmp_word, Counts(1)});
                }
            }
            this->wordcontainer_.sort();
        }
        return;
    }

    WordCounter::WordCounter(const std::initializer_list<Word> list) {
        string tmpstr = "";
        bool is_word = false;

        for (Word word: list) {
            is_word = false;
            for (pair<Word, Counts> &n: this->wordcontainer_) {
                if (word == n.first) {
                    n.second++;
                    is_word = true;
                }
            }
            if (!is_word) {
                wordcontainer_.push_back(pair<Word, Counts>{word, Counts(1)});
            }
        }
        this->wordcontainer_.sort();
    }


    int WordCounter::TotalWords() {
        int words = 0;
        for (pair<Word, Counts> &oneword : wordcontainer_)
            words += oneword.second;
        return words;
    }


    unsigned long WordCounter::DistinctWords() {
        return this->wordcontainer_.size();
    }


    std::set<Word> WordCounter::Words(void) const {
        std::set<Word> s;

        for (pair<Word, Counts> sth : this->wordcontainer_)
            s.insert(sth.first);

        return s;
    }

    Counts WordCounter::operator[](const char *word) {
        string tmp(word);
        int result = 0;
        Counts toreturn;

        if (!this->wordcontainer_.empty()) {
            for (pair<Word, Counts> &n: this->wordcontainer_) {
                if (n.first == tmp) {
                    result = n.second;
                }
            }
            toreturn.counts_ = result;
            return toreturn;
        } else {
            return toreturn;
        }
    }


    ostream &operator<<(ostream &output, WordCounter &wc) {
        list<pair<Word, Counts>>::reverse_iterator ite;

        for (ite = wc.wordcontainer_.rbegin(); ite != wc.wordcontainer_.rend(); ite++) {
            output << ite->first.GetWord();
            output << " ";
            output << ite->second.GetCounts();
            output << "\n";
        }
        return output;
    }
}