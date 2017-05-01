//
// Created by matematyk60 on 04.04.17.
//

#include "StudentRepository.h"

using namespace academia;

using namespace std;

int main() {
    string name, surname, program, id;
    int year;
    for(int i = 0; i < 10 ; i++) {
        cout << "Name:?" << endl;
        cin >> name;
        cout << "Surname?" << endl;
        cin >> surname;
        cout << "ID?" << endl;
        cin >> id;
        cout << "Program?" << endl;
        cin >> program;
        cout << "Year?" << endl;
        cin >> year;

        try {
            StudentRepository repo{{id, name, surname, program, StudyYear {year}}};
        } catch (const StudentValidationError &n) {
            cerr << n.what() ;
        }
    }

}