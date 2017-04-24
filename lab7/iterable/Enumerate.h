//
// Created by matematyk60 on 22.04.17.
//

#ifndef JIMP_EXERCISES_ENUMERATE_H
#define JIMP_EXERCISES_ENUMERATE_H
#include <vector>
#include <string>
#include "Iterable.h"



namespace utility{
    class Enumerate : public Iterable{
    public:
        Enumerate(std::vector<std::string> strings);
        static std::vector<std::pair<int,std::string>> enumerate(std::vector<std::string> strings);
        
        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        Begin() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        End() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        begin() override;

        std::vector<std::pair<int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator
        end() override;

    private:
        std::vector<std::pair<int,std::string>> enumerated_;
    };
}


#endif //JIMP_EXERCISES_ENUMERATE_H
