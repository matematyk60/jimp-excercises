//
// Created by matematyk60 on 01.05.17.
//
#include <MovieSubtitles.h>
#include <sstream>

using namespace moviesubs;
using std::cout;
int main(){
    std::stringstream ss;
    ss << "{10}{250}TEXT\n{260}{220}NEWLINE\n";
    std::stringstream so;
    MicroDvdSubtitles sd;
    sd.ShiftAllSubtitlesBy(300, 25, &ss,&so);
    cout << so.str();

}