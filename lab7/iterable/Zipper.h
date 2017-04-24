//
// Created by matematyk60 on 22.04.17.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H
#include <string>
#include <vector>
#include <iterator>
#include "Iterable.h"

using std::iterator;

namespace utility{
    class Zipper : public Iterable{
    public:
        Zipper(std::vector<int> ints, std::vector<std::string> strings);
        static std::vector<std::pair<int,std::string>> zip(std::vector<int> ints,
                                                                   std::vector<std::string> strings);

        std::vector<std::pair<int,std::string>>::iterator Begin() override;

        std::vector<std::pair<int,std::string>>::iterator End() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        begin() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        end() override;


    private:
        std::vector<std::pair<int,std::string>> zipped_;
    };
}


#endif //JIMP_EXERCISES_ZIPPER_H
