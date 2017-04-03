#include <iostream>
#include "TextPool.h"

using namespace pool;
using namespace std;

int main() {
    //Inicjalizacja wstępna puli za pomocą listy inicjalizacyjnej
    TextPool pool {"abc", "efg", "hij", "klmn"};

    cout << pool.StoredStringCount() << endl;
    pool.Intern("abc");

    cout << pool.StoredStringCount() << endl;
    pool.Intern("bysiewicz");

    cout << pool.StoredStringCount() << endl;

}