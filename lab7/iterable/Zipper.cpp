//
// Created by matematyk60 on 22.04.17.
//

#include "Zipper.h"

namespace utility{
    Zipper::Zipper(std::vector<int> ints, std::vector<std::string> strings) {
        zipped_ = this->zip(ints,strings);
    }


    std::vector<std::pair<int,std::string>> Zipper::zip(std::vector<int> ints,std::vector<std::string> strings ) {
        std::pair< int, std::string> tmp;
        std::vector<std::pair<int, std::string>> answer;
        std::vector<std::string>::iterator it = strings.begin();
        std::vector<int>::iterator it2 = ints.begin();
        while(it != strings.end() || it2 != ints.end()){
            if(it == strings.end()){
                tmp.second = strings[strings.size()-1];
            } else {
                tmp.second = *it;
                it++;
            }

            if(it2 == ints.end()){
                tmp.first = ints[ints.size()-1];
            } else{
                tmp.first = *it2;
                it2++;
            }
            answer.emplace_back(tmp);
        }
        return answer;
    }

    std::vector<std::pair<int,std::string>>::iterator Zipper::Begin() {
        return zipped_.begin();
    }

    std::vector<std::pair<int,std::string>>::iterator Zipper::End() {
        return zipped_.end();
    }

    std::vector<std::pair<int,std::string>>::iterator Zipper::begin() {
        return zipped_.begin();
    }

    std::vector<std::pair<int,std::string>>::iterator Zipper::end() {
        return zipped_.end();
    }


}