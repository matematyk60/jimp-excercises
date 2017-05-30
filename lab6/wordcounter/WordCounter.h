//
// Created by janek on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "Counts.h"
#include "Word.h"

#include <string>
#include <fstream>
#include <utility>
#include <list>
#include <set>
#include <initializer_list>

namespace datastructures {
    using ::std::string;
    using ::std::ostream;
    using ::std::set;
    using ::std::pair;
    using ::std::fstream;


    class WordCounter {
    public:
        WordCounter();

        WordCounter(const string &path);

        WordCounter(const std::initializer_list<Word> list);

        ~WordCounter();


        int TotalWords();

        unsigned long DistinctWords();

        set<Word> Words(void) const;

        Counts operator[](const char *word);


        friend ostream &operator<<(ostream &is, WordCounter &word_counter);

    private:
        fstream file_;
        std::list<pair<Word, Counts>> wordcontainer_;
    };

    ostream &operator<<(ostream &output, WordCounter &wc);
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
