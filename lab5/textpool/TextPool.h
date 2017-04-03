//
// Created by janek on 03.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool{
    using ::std::string;

    class TextPool{
    public:

        //domyślny konstruktor
        TextPool();

        //konstruktor z listą inicjalizacyjną
        TextPool(std::initializer_list<string> str);

        //1. konstruktor kopiujący
        TextPool(const TextPool &xxx) = delete;

        //2. konstruktor przenoszący
        TextPool(TextPool &&xxx);

        //3. operator przypisania kopiujący
        TextPool &operator=(const TextPool &xxx) = delete;

        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&xxx);

        //5. Destruktor
        ~TextPool();


        std::experimental::string_view Intern(const string &str);

        size_t StoredStringCount() const;

    private:
        std::set<string> pula{};

    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H

