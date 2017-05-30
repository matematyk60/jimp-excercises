//
// Created by janek on 19.04.17.
//

#include "Point3D.h"
using namespace geometry;
using namespace std;

int main() {
    /*
     * zadanie 5:
     * Jako pierwszy wywoływany jest konstruktor klasy bazowej (2d)
     * Później konstruktor klasy pochodnej (3d)
     * W kontraście destruktory są wywoływane odwrotnie
     * Najpierw zostaje niszczona klasa pochodna, a później klasa bazowa
     */
    //Punkt3d a(1,0), b(2,1,1);




    /*
     * zadanie 6:
     * Zwraca odległość pomiędzy punktami w 2d
     */
    //Punkt3d a(1,0), b(2,1,1);
    //cout << endl << endl;
    //std::cout << "Dist " << a.Distance(b) << endl;;
    //cout << endl << endl;



    /*
     * zadanie 7:
     * Punkt 3d nie ma przeciążonego operatora <<,
     * dlatego zostanie wywołany operator klasy bazowej
     */
    Punkt3d p3d(1, 2, 3);
    cout << endl << endl;
    std::cout << p3d << std::endl;
    cout << endl << endl;

    return 0;
}