//
// Created by matematyk60 on 16.05.17.
//
#include <iostream>
#include <set>
#include <map>
#include "Algo.h"

using namespace std;



int main(){
    map<int, set<int>> years{make_pair(1, set<int>{10, 20, 11, 21}),
                             make_pair(2, set<int>{30, 40, 32, 42}),
                             make_pair(3, set<int>{50, 60, 53, 54}),
                             make_pair(4, set<int>{70, 80, 77, 79}),
                             make_pair(5, set<int>{90, 91, 92, 93})};
    cout<< algo::FindYear(years,94);
}