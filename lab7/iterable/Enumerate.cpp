//
// Created by matematyk60 on 22.04.17.
//

#include "Enumerate.h"

namespace utility{
    Enumerate::Enumerate(std::vector<std::string> strings) {
        enumerated_ = this->enumerate(strings);
    }

    std::vector<std::pair<int, std::string>> Enumerate::enumerate(std::vector<std::string> strings) {
        std::vector<std::pair<int, std::string>> answer;
        std::pair<int, std::string> tmp;
        int i = 1;
        for(auto n : strings){
            tmp.first = i;
            tmp.second = n;
            answer.emplace_back(tmp);
            i++;
        }
        return answer;
    }

    
    std::vector<std::pair<int,std::string>>::iterator Enumerate::Begin() {
        return enumerated_.begin();
    }

    std::vector<std::pair<int,std::string>>::iterator Enumerate::End() {
        return enumerated_.end();
    }

    std::vector<std::pair<int,std::string>>::iterator Enumerate::begin() {
        return enumerated_.begin();
    }

    std::vector<std::pair<int,std::string>>::iterator Enumerate::end() {
        return enumerated_.end();
    }
}