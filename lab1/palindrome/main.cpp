//
// Created by jan on 06.03.17.
//

#include "Palindrome.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    bool yes;
    cout << "Did call is_palindrome or exit?" << endl;
    cin >> yes;
    if (yes) {
        cout << "Enter the word" << endl;
        cin >> str;
        yes = is_palindrome(str);
        if(yes)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    else
        return 0;
    return 0;
}