//
// Created by janek on 10.04.17.
//

#include <string>
#include <fstream>
#include <utility>
#include <list>
#include <iostream>
#include <regex>
#include "WordCounter.h"

namespace datastructures {

    WordCounter::WordCounter() {}

    WordCounter::WordCounter(const string &path) {
        string word = "";
        string tmpstr = "";
        Word tmpWord;
        bool isWord;

        file_.open(path, fstream::in);

        if (!file_.good())
            std::cout << "open error" << std::endl;
        else {
            while (file_ >> word) {
                tmpstr = "";
                for (char c: word) {
                    if (c >= 65 and c <= 90) {
                        c += 32;
                    }
                    if (c >= 97 and c <= 122) {
                        tmpstr += c;
                    }
                }

                tmpWord.word_ = tmpstr;
                isWord = false;

                for (pair<Word, Counts> &n: this->wordcontainer_) {
                    if (tmpWord == n.first) {
                        n.second++;
                        isWord = true;
                        break;
                    }
                }
                if (!isWord) {
                    this->wordcontainer_.push_front(pair<Word, Counts>{tmpWord, Counts(1)});
                }
            }
            this->wordcontainer_.sort();
        }
    }


    WordCounter::WordCounter(const std::initializer_list<datastructures::Word> list) {
        string tmpstr = "";
        bool isWord;

        for (Word word: list) {
            isWord = false;
            for (pair<Word, Counts> &n: this->wordcontainer_) {
                if (word == n.first) {
                    n.second++;
                    isWord = true;
                }
            }
            if (!isWord) {
                wordcontainer_.push_back(pair<Word, Counts>{word, Counts(1)});
            }
        }
        this->wordcontainer_.sort();
    }


    WordCounter::~WordCounter() {
        if (file_.is_open())
            file_.close();
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
        std::list<pair<Word, Counts>>::reverse_iterator ite;

        for (ite = wc.wordcontainer_.rbegin(); ite != wc.wordcontainer_.rend(); ite++) {
            output << ite->first.GetWord();
            output << " ";
            output << ite->second.GetCount();
            output << "\n";
        }
        return output;
    }
}