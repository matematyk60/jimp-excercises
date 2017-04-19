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

        bool Empty();

        bool operator==(const Word &other_object) const;

        bool operator<(const Word &other) const;

        bool operator>(const Word &other) const;

        string GetWord(void) const;

        friend std::ostream &operator<<(std::ostream &os, const Word &wout);

        friend std::istream &operator>>(std::istream &is, Word &obj);

        friend class WordCounter;

    private:
        string word_;
    };

    std::ostream &operator<<(std::ostream &output, const Word &wout);

    std::istream &operator>>(std::istream &input, Word &obj);
}

#endif //JIMP_EXERCISES_WORD_H
