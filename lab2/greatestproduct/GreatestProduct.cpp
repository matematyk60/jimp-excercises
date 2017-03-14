//
// Created by matematyk60 on 14.03.17.
//

#include "GreatestProduct.h"

using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k){
    vector<int> greatest;
    for(int i = 0 ; i<k ; i++){
        greatest.emplace_back(-1);
    }


    for(int v : numbers){
        for(int i = 0 ; i < k ; i++){
            if(v >= greatest[i]){
                greatest.insert(greatest.begin()+i,v);
                greatest.pop_back();
                break;
            }
        }
    }
    for(int i = 0 ; i < k ; i++){
        if(greatest[i] == -1){
            greatest[i] = 1;
        }
    }
    int product = 1;
    for(int v : greatest){
        product *= v;
    }

    return product;
}

