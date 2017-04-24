//
// Created by matematyk60 on 22.04.17.
//

#include "Product.h"


using std::stringstream;
using std::string;

namespace utility{
    Product::Product(std::vector<int> ints, std::vector<string> strings) {
        products_ = this->product(ints,strings);
    }

    std::vector<std::pair<int, std::string>> Product::product(std::vector<int> ints, std::vector<std::string> strings) {
        std::pair<int, string> tmp;
        std::vector<std::pair<int,std::string>> answer;
        for(auto n : ints){
            tmp.first = n;
            for(auto m : strings){
                tmp.second = m;
                answer.emplace_back(tmp);
            }
        }
        return answer;
    }

    std::vector<std::pair<int,std::string>>::iterator Product::Begin() {
        return products_.begin();
    }

    std::vector<std::pair<int,std::string>>::iterator Product::End() {
        return products_.end();
    }

    std::vector<std::pair<int,std::string>>::iterator Product::begin() {
        return products_.begin();
    }

    std::vector<std::pair<int,std::string>>::iterator Product::end() {
        return products_.end();
    }
}