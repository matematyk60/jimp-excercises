//
// Created by matematyk60 on 04.04.17.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H


#include <iterator>
#include <vector>

namespace datastructures{
    class Zipper{
    public:
        static std::vector<std::pair<std::string,int>> zip(std::vector<std::string> strings, std::vector<int> ints);
    };
}


#endif //JIMP_EXERCISES_ZIPPER_H
