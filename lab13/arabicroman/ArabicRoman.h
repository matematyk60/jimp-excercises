//
// Created by matematyk60 on 06.06.17.
//

#ifndef JIMP_EXERCISES_ARABICROMAN_H
#define JIMP_EXERCISES_ARABICROMAN_H
#include <string>
#include <exception>
#include <map>
#include <iostream>

using ::std::string;

namespace translator{

    string ArabicToRoman(int arabic){
            if (arabic < 1 || arabic > 3999)
                    throw std::runtime_error("Too big");
            string roman = "";
            while (arabic >= 1000) {
                    roman += "M";
                    arabic -= 1000;        }
            while (arabic >= 900) {
                    roman += "CM";
                    arabic -= 900;
            }
            while (arabic >= 500) {
                    roman += "D";
                    arabic -= 500;
            }
            while (arabic >= 400) {
                    roman += "CD";
                    arabic -= 400;
            }
            while (arabic >= 100) {
                    roman += "C";
                    arabic -= 100;
            }
            while (arabic >= 90) {
                    roman += "XC";
                    arabic -= 90;
            }
            while (arabic >= 50) {
                    roman += "L";
                    arabic -= 50;
            }
            while (arabic >= 40) {
                    roman += "XL";
                    arabic -= 40;
            }
            while (arabic >= 10) {
                    roman += "X";
                    arabic -= 10;
            }
            while (arabic >= 9) {
                    roman += "IX";
                    arabic -= 9;
            }
            while (arabic >= 5) {
                    roman += "V";
                    arabic -= 5;
            }
            while (arabic >= 4) {
                    roman += "IV";
                    arabic -= 4;
            }
            while (arabic >= 1) {
                    roman += "I";
                    arabic -= 1;
            }
            return roman;

    }

    int RomanToArabic(string roman){

    }
}


#endif //JIMP_EXERCISES_ARABICROMAN_H
