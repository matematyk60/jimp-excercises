//
// Created by matematyk60 on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H
#include <string>

using ::std::string;

namespace datastructures{

    class Word{
    public:
        Word();
        Word(const char *text);
        Word(std::string text);
        bool operator==(const Word &other_object) const;

        bool operator<(const Word &other) const;



        bool operator>(const Word &other) const;
        string GetWord()const;
    private:
        string word_;
    };

}


#endif //JIMP_EXERCISES_WORD_H
