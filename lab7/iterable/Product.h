//
// Created by matematyk60 on 22.04.17.
//

#ifndef JIMP_EXERCISES_PRODUCT_H
#define JIMP_EXERCISES_PRODUCT_H
#include <sstream>
#include <string>
#include <vector>
#include "Iterable.h"

namespace utility{
    class Product : public Iterable {
    public:
        Product(std::vector<int> ints, std::vector<std::string> strings);
        static std::vector<std::pair<int,std::string>> product(std::vector<int> ints,
                                                           std::vector<std::string> strings);

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        Begin() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        End() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        begin() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        end() override;

    private:
        std::vector<std::pair<int,std::string>> products_;
    };
}


#endif //JIMP_EXERCISES_PRODUCT_H
