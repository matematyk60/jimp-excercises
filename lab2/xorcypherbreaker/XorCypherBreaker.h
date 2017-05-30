//
// Created by matematyk60 on 14.03.17.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <vector>
#include <iostream>

using namespace std;

bool DictionarySearch(const vector<string> &dictionary, string suspect);

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
