//
// Created by janek on 13.03.17.
//

#include "Polybius.h"
#include <map>
using namespace std;


string PolybiusCrypt(string message) {
    string converted = "";
    map<char, int> v = {
                        {'a', 11}, {'b', 12}, {'c', 13}, {'d', 14}, {'e', 15},
                        {'f', 21}, {'g', 22}, {'h', 23}, {'i', 24}, {'j', 24}, {'k', 25},
                        {'l', 31}, {'m', 32}, {'n', 33}, {'o', 34}, {'p', 35},
                        {'q', 41}, {'r', 42}, {'s', 43}, {'t', 44}, {'u', 45},
                        {'v', 51}, {'w', 52}, {'x', 53}, {'y', 54}, {'z', 55}
    };
    for(int i=0; i<message.length(); i++){
        if(message[i] == ' ') continue;
        else{
            message[i] = tolower(message[i]);
            for(const auto &n : v){
                if(message[i] == n.first)
                    converted = converted + to_string(n.second);
            }
        }
    }
    return converted;
}

string PolybiusDecrypt(string crypted){
    string converted = "", tmp2;
    int tmp;
    map<char, int> v = {
            {'a', 11}, {'b', 12}, {'c', 13}, {'d', 14}, {'e', 15},
            {'f', 21}, {'g', 22}, {'h', 23}, {'i', 24}, {'k', 25},
            {'l', 31}, {'m', 32}, {'n', 33}, {'o', 34}, {'p', 35},
            {'q', 41}, {'r', 42}, {'s', 43}, {'t', 44}, {'u', 45},
            {'v', 51}, {'w', 52}, {'x', 53}, {'y', 54}, {'z', 55}
    };
    for(int i=0; i<crypted.length(); i+=2) {
        tmp = (int(crypted[i]) -48)*10 + int(crypted[i+1]) - 48;
        for (const auto &n : v) {
            if (tmp == n.second) {
                tmp2 = n.first;
                converted = converted + tmp2;
            }
        }
    }
    return converted;
}