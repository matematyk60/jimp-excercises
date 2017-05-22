//
// Created by matematyk60 on 21.04.17.
//

#include "Ball.h"
#include "Circle.h"
#include <iostream>

using namespace std;

int main(){
    geometry::Ball k(0,0,0,10);
    cout << k.Area();
}