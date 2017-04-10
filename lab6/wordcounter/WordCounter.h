//
// Created by matematyk60 on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <list>
#include <set>

using std::string;

namespace datastructures{
    class Counts{
    public:
        Counts();
        Counts(int number);
        int GetCounts();

    private:
        int number_;
    };

    class Word{
    public:
        Word();
        Word(const char *text);
        bool Compare(const char *text);
        string GetWord();
    private:
        string word_;
    };

    class WordCounter{
        public:
        WordCounter();
        WordCounter(std::pair<Word,Counts> new_pair);
        WordCounter(std::initializer_list<Word> elements);

        std::set<Word> Words();
        int TotalWords();
        int DistinctWords();
        bool IsAlreadyHere(const char *text);

        int operator[](const char *text)const;
    private:
        std::list<std::pair<Word,Counts>> index_;
    };




}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
