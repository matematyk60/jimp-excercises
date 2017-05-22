//
// Created by matematyk60 on 04.04.17.
//

#include "Zipper.h"

//Definicja w Point.cpp
#include "Zipper.h"
#include <iomanip>
#include <iostream>

namespace datastructures{
    std::vector<std::pair<std::string, int>> Zipper::zip(std::vector<std::string> strings, std::vector<int> ints) {
        std::pair<std::string, int> tmp;
        std::vector<std::pair<std::string, int>> answer;
        std::vector<std::string>::iterator it = strings.begin();
        std::vector<int>::iterator it2 = ints.begin();
        while(it != strings.end() || it2 != ints.end()){
            if(it == strings.end()){
                tmp.first = "";
            } else {
                tmp.first = *it;
                it++;
            }

            if(it2 == ints.end()){
                tmp.second = 0;
            } else{
                tmp.second = *it2;
                it2++;
            }
            answer.emplace_back(tmp);
        }
        return answer;
    }
}