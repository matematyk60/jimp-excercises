//
// Created by matematyk60 on 14.03.17.
//

#include "GreatestProduct.h"

using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k){
    vector<int> greatest_natural;

    for(int v : numbers) {
        if (v < 0) {
            return 0;
        } else{
            TryToInsert(greatest_natural,v,k);
        }
    }

    int product = 1;

    for(int v : greatest_natural){
        product *= v;
    }

    return product;
}

void TryToInsert(vector<int> &greatest, int value, int k){
    bool inserted = false;
    if(greatest.size() == 0){
        greatest.push_back(value);
    } else{
        for(int i = 0 ; i < greatest.size() ; i++){
            if(value >= greatest[i]){
                greatest.insert(greatest.begin()+i,value);
                inserted = true;
                if(greatest.size() > k){
                    greatest.pop_back();
                }
                break;
            }
            }
        if(!inserted && greatest.size() < k){
            greatest.push_back(value);
        }

    }

}
