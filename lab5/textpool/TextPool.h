//
// Created by janek on 03.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

namespace pool{
    class TextPool {
    public:

        TextPool();

        TextPool(const std::initializer_list<const char*> &elements);

        TextPool(const TextPool &Pool) = delete;

        TextPool &operator=(TextPool &Pool) = delete;

        TextPool &operator=(TextPool &&Pool);

        TextPool(TextPool &&Pool);

        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;


    private:
        std::vector<std::experimental::string_view> List_;
    };
}



#endif //JIMP_EXERCISES_TEXTPOOL_H
