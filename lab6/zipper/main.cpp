//
// Created by matematyk60 on 04.04.17.
//
#include <iostream>
#include "Zipper.h"

int main(){
    std::vector<std::string> vec = {"fasda","Dsadas","DSAdsa"};
    std::vector<int> vec2 = {12,13};
    for(auto n : datastructures::Zipper::zip(vec,vec2)){
        std::cout << n.first+std::to_string(n.second) << std::endl;
    }
}