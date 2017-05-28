//
// Created by matematyk60 on 23.05.17.
//

#include <FactoryMethod.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace factoryMethod;
using namespace std;

class Tmp{
public:
    Tmp(int id = 0){
        id_ = id;
    }
    int Id(){
        return id_;
    }
private:
    int id_;
};

int main(){
    int *b = new int;
    *b = 32;
    cout << Value(b)<< endl;

    shared_ptr<int> integer= make_shared<int>(34);
    cout << Value(integer);

    vector<int> integer2 {1,2,3,4};
    cout << Value(integer2.begin()+3) << endl;

    Repository<int> tmp {1,2,3,4,5};
    cout << tmp.Size() << endl;

    Tmp tmp1 {1};
    Tmp tmp2 {2};
    Repository<Tmp> repo {tmp1,tmp2};
    cout<< repo.NextId() << endl;

    cout<< Mean(integer2) << endl;




}