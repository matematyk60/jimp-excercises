//
// Created by janek on 13.03.17.
//

#include "XorCypherBreaker.h"
#include <algorithm>
#include <iostream>
using std::find;
using std::vector;
using std::string;




string XorCypherBreaker(const std::vector<char> &cryptogram,
                       int key_length,
                       const std::vector<string> &dictionary){


    char arr[3];
    string str="", str1="";
    int counter1 = 0, counter2 = 0;
    int ite;
    for(int i=97; i<=122; i++){
        arr[0] = char(i);
        //cout << arr[0] << endl;
        for(int j=97; j<=122; j++){
            arr[1] = char(j);
            for(int k=97; k<=122; k++){

                arr[2] = char(k);

                ite = 0;

                //cout << arr << "  " << str1 << endl;
                str1="";
                for(const auto &n : cryptogram) {
                    if(ite == 3)
                        ite = 0;
                    str1 = str1 + (char)(n xor arr[ite]);

                    ite++;
                }


                counter2 = 0;
                for(const string &n : dictionary) {
                    if (str1.find(n) != string::npos) {
                        counter2++;

                    }
                }


                if(counter2 > counter1) {
                    str = arr;
                    counter1 = counter2;

                }
            }
        }
    }
    return str;
}