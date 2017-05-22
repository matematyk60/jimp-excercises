//
// Created by matematyk60 on 13.03.17.
//

#include "Polybius.h"


std::string PolybiusCrypt(std::string message){

    int i = 0;

    while(message[i] != '\0'){
        message[i] = (char) tolower(message[i]);
        if( message[i] >= 'j'){ //ignoring j in alphabet
            message[i] -= 1;
        }
        i++;
    }

    i = 0;
    std::string answer;
    while(message[i] != '\0'){
        if(message[i] == ' ') {
            i++;
            continue;
        }

        answer += std::to_string((((int)message[i]-97)-((int)message[i]-97)%5)/5+1);
        answer += std::to_string(((int)message[i]-97)%5+1);
        i++;
        }

    return answer;
    }




std::string PolybiusDecrypt(std::string crypted){
    int p = 97;
    char keys[5][5];
    std::string answer;


    for(int i = 0 ; i < 5 ; i++){
        for( int j = 0 ; j < 5 ; j++) {
            if (i == 1 && j == 4) {
                p++;
            }
            keys[i][j] = p;
            p++;
        }
    }
    int i = 0;

    while(crypted[i] != '\0'){
        if(crypted[i] == ' '){
            i++;
            continue;
        } else {
            answer += keys[(int)crypted[i] - 49][(int)crypted[i+1] - 49];
            i += 2;

            }
        }
    return answer;
    }

