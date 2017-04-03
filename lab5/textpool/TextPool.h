//
// Created by matematyk60 on 03.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool{
    class TextPool {

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    };
}



#endif //JIMP_EXERCISES_TEXTPOOL_H
