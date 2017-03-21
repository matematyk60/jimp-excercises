//
// Created by janek on 19.03.17.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>
using namespace tinyurl;
using std::cout;
using std::endl;

int main() {
    auto codec = Init();
    auto voronoi_shortened = Encode("https://en.wikipedia.org/wiki/Voronoi_diagram", &codec);
    auto movie_shortened = Encode("https://www.youtube.com/watch?v=cWDdd5KKhts", &codec);
    cout << Decode(codec, voronoi_shortened) << endl;
    cout << Decode(codec, movie_shortened) << endl;

    return 0;
}

