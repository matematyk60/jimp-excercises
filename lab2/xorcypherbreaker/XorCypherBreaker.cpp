//
// Created by matematyk60 on 14.03.17.
//

#include "XorCypherBreaker.h"
#include <algorithm>


std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary){
    string suspect = "";
    int i2 = 0;
    int power = 0;
    string key;

    for(int i = 0 ; i < key_length ; i++){
        key += "a";
    }


    for(int i = 97 ; i < 123 ; i++){
        key[0] =(char) i;
        for(int j = 97 ; j < 123 ; j++) {
            key[1] = (char) j;
            for (int k = 97; k < 123; k++) {
                key[2] = (char) k;
                for (char ch : cryptogram) {
                    if (i2 == key_length) {
                        i2 = 0;
                    }
                    if ((ch ^ key[i2]) == ' ' || (ch ^ key[i2]) == '?' || (ch ^ key[i2]) == '!' ||
                        (ch ^ key[i2]) == '.') {
                        if (DictionarySearch(dictionary, suspect)) {
                            power++;
                            i2++;
                            suspect = "";
                        } else {
                            suspect = "";
                            i2++;
                        }
                    } else {
                        suspect += ch ^ key[i2];
                        i2++;
                    }
                }
                if (power > 17) {
                    return key;
                } else {
                    power = 0;
                }
                i2 = 0;
            }
        }
    }
    return 0;
}


bool DictionarySearch(const vector<string> &dictionary, string suspect){
    int i = 0;
    while(suspect[i] != '\0'){
        suspect[i] = (char) tolower(suspect[i]);
        i++;
    }

    for(string v : dictionary){
        if( !v.compare(suspect) ){
            return true;
        }
    }
    return false;

}