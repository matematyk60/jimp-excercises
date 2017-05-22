//
// Created by matematyk60 on 25.04.17.
//

#include <iostream>
#include <Pesel.h>

using namespace academia;
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall() {
    throw BallException();
}

int main(){

}