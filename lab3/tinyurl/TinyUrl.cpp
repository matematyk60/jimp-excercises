//
// Created by janek on 19.03.17.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>


namespace tinyurl{


    std::unique_ptr<struct TinyUrlCodec> Init() {
        return std::make_unique<struct TinyUrlCodec>();
    }


    void NextHash(std::array<char, 6> *state) {
        if ((*state)[0] == 122) {
            for (int j = 0; j < 6; j++)
                (*state)[j] = 48;
        }
        for (int i = 5; i > -1; --i) {
            if ((*state)[i] == 122) {
                (*state)[i] = 48;
                continue;
            } else if ((*state)[i] == 57) {
                (*state)[i] = 65;
                break;
            } else if ((*state)[i] == 90) {
                (*state)[i] = 97;
                break;
            } else {
                (*state)[i] = ++(*state)[i];
                break;
            }
        }
    }


    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        string coded_url="";
        auto &c = *codec;
        c->url[c->counter] = url;
        NextHash(&c->state);
        ++(c->counter);
        for(int i=0; i<6; ++i)
            coded_url[i] = c->state[i];
        return coded_url;
    }


    int convert(int n){
        if(n < 48) return 0;
        if(n < 58) return (n-48);
        if(n < 91) return (n-55);
        if(n < 123) return (n-61);
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){

        long number=0;
        long number0=0;
        long number1=0;
        long number2=0;
        long number3=0;
        long number4=0;
        long number5=0;


        string decoded_url="";
        auto &c = *codec;

        number0 = (convert((int)hash[0]))*916132832;
        number1 = (convert((int)hash[1]))*14776336;
        number2 = (convert((int)hash[2]))*238328;
        number3 = (convert((int)hash[3]))*3844;
        number4 = (convert((int)hash[4]))*62;
        number5 = (convert((int)hash[5]));
        number = number0 + number1 + number2 + number3 + number4 + number5;


        decoded_url = c.url[number];

        return decoded_url;
    }
};