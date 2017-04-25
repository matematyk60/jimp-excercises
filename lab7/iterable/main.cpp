//
// Created by janek on 25.04.17.
//

#include <vector>
#include <string>
#include "Iterable.h"
#include <iostream>

using namespace utility;

using namespace std;

int main(){
    vector<int> vi {4, 77, -91};
    vector<string> vs {"4", "9991", "adfskld"};
    auto it = ZipperIterator(vi.begin(),vs.begin(), vi.end(), vs.end());
    std::pair<int, string> p1 {1,"tr"};
    std::pair<int,string> p2 {1, "tr"};
    if(p1 == p2){
        cout << it.Next().Dereference().first;
    }
}