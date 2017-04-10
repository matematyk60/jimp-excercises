//
// Created by janek on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>

namespace datastructures {
    using ::std::string;
    using ::std::ostream;


    class Word {
    public:
        Word();

        Word(const string &word);

        bool operator==(const Word &other_object) const;

        bool operator<(const Word &other) const;

        bool operator>(const Word &other) const;

        string GetWord(void) const;


        friend class WordCounter;

    private:
        string word_;
    };
}

#endif //JIMP_EXERCISES_WORD_H
