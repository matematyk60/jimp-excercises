//
// Created by janek on 24.04.17.
//

#include <memory>
#include "Shape.h"
using ::std::unique_ptr;
using std::make_unique;

using namespace geometry;
#include <list>
int main(){
    std::list<Shape*> lista{new TriangleShape, new TriangleShape{}, new SquareShape{}, new TriangleShape{},new  TriangleShape{}, new SquareShape{},
                            new CircleShape{},new  SquareShape{}};

    for(auto n : lista){
        n->Draw();
    }
}