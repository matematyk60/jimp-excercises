//
// Created by janek on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <strstream>
#include <istream>
#include <fstream>
#include <vector>
#include <list>
#include <set>

using namespace std;
namespace datastructures {
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

    class Counts {
    public:
        Counts();

        Counts(int value);

        int GetCounts(void) const;

        void SetCount(int value);


        Counts &operator++(int);

        operator int() const;


        bool operator<(const Counts &other) const;

        bool operator>(const Counts &other) const;

        friend bool operator==(const int int_value, const Counts &other_object);


        friend class WordCounter;

    private:
        int counts_;

    };

    bool operator==(const int int_value, const Counts &other_object);


    class WordCounter {
    public:
        WordCounter();

        WordCounter(const char *file);

        WordCounter(const initializer_list<Word> list1);

        int TotalWords();

        unsigned long DistinctWords();

        set<Word> Words(void) const;

        Counts operator[](const char *word);


        friend ostream &operator<<(std::ostream &is, WordCounter &word_counter);

    private:
        //fstream file_;
        list <pair<Word, Counts>> wordcontainer_;
    };

    ostream &operator<<(std::ostream &is, WordCounter &word_counter);
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H