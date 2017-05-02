//
// Created by matematyk60 on 01.05.17.
//

#include <sstream>
#include "MovieSubtitles.h"

namespace moviesubs{

    ostream *MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output) {
        if(fps <= 0){
            throw std::invalid_argument("FPS must be larger than zero!");
        }
        int i =2;
        ParseLine(delay, fps, input, output, 1);
        while(input->get() != -1){
            *output << '\n';
            if(input->peek() == -1){
                break;
            }
            ParseLine(delay, fps, input, output, i);
            i++;
        }
        return output;
    }

    ostream *MicroDvdSubtitles::ParseLine(int delay, int fps, istream *input, ostream *output, int line_number) {
        int frame,new_frame,frame2, new_frame2;
        std::string line = "";
        std::string optional = "";
        std::string text = "";
        std::string optional2 = "";
        frame = GetPosition(input);
        new_frame =frame + delay*fps/1000;
        frame2 = GetPosition(input);
        new_frame2 =frame2+ delay*fps/1000;
        if(input->peek() == '{'){
            optional = SkipToBracket(input);
        }
        while(input->peek() != '\n'){
            if(input->peek() == -1){
                optional2 = "\n";
                break;
            }
            text += (char)input->get();
        }
        if(new_frame < 0){
            throw NegativeFrameAfterShift("{"+std::to_string(frame)+"}{"+std::to_string(frame2)+"}"+optional+text+optional2,line_number);
        }
        if(new_frame2 < new_frame){
            throw SubtitleEndBeforeStart("{"+std::to_string(frame)+"}{"+std::to_string(frame2)+"}"+optional+text+optional2,line_number);
        }
        // else
        *output << ("{"+std::to_string(new_frame)+"}{"+std::to_string(new_frame2)+"}"+optional+text+optional2);
        return output;
    }

    std::string MicroDvdSubtitles::SkipToBracket(istream *input) {
        std::string tmp = "";
        while(input->peek() != '}'){
            tmp += input->get();
        }
        tmp += '}';
        input->ignore();
        return tmp;
    }

    int MicroDvdSubtitles::GetPosition(istream *input) {
        std::string tmp = "";
        std::stringstream ss;
        int answer;
        if(input->get() != '{'){
            throw InvalidSubtitleLineFormat();
        }
        if(input->peek() == '}'){
            throw InvalidSubtitleLineFormat();
        }
        while(input->peek() >= 48 && input->peek() <= 57){
            tmp += input->get();
        }
        if(input->get() != '}'){
            throw InvalidSubtitleLineFormat();
        }
        ss << tmp;
        ss >> answer;
        return answer;
    }
}