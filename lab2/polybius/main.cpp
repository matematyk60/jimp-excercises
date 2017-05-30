#include <iostream>
#include "Polybius.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv){

    char line[256];

    ifstream input_file( argv[1] );
    if(!input_file){
        cout << "Cannot open input file" << endl;
        return -1;
    }

    ofstream output_file( argv[2] , ios_base::in | ios_base::app );
    if(!output_file){
        cout << "Cannot open output file" << endl;
        return -1;
    }
    if( (int)*argv[3]-48 == 1){
        while(!input_file.eof()){
            input_file.getline(line,256);
            output_file << PolybiusCrypt(line);
        }
    } else{
        while(!input_file.eof()){
            input_file.getline(line,256);
            output_file << PolybiusDecrypt(line);
        }
    }
    
    input_file.close();
    output_file.close();





}