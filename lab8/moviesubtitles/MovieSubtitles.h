//
// Created by matematyk60 on 01.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H
#include <iostream>

using std::ostream;
using std::istream;

namespace moviesubs{
    class MovieSubtitles{
    public:
        virtual ostream* ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output) = 0 ;
        virtual ~MovieSubtitles(){};
        virtual ostream* ParseLine(int delay, int fps, istream *input, ostream *output, int line_number) = 0;
    };

    class MicroDvdSubtitles : public MovieSubtitles{
    public:
        ostream *ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output) override;
        static int GetPosition(istream *input);
        static std::string SkipToBracket(istream *input);
        ostream *ParseLine(int delay, int fps, istream *input, ostream *output, int line_number) override;
    };

    class SubShiftingError : public std::runtime_error{
    public:
        SubShiftingError(std::string error = "ERROR", int line = 0) : runtime_error(error){line_ = line;};
        int LineAt(void)const { return line_;}
    private:
        int line_;
    };

    class InvalidSubtitleLineFormat : public SubShiftingError{
    public:
        InvalidSubtitleLineFormat(std::string message = "Invalid subtitle line format", int line = 0) : SubShiftingError("At line "+std::to_string(line)+": "+message,line){}
    };

    class NegativeFrameAfterShift : public SubShiftingError{
    public:
        NegativeFrameAfterShift(std::string message, int line) : SubShiftingError("At line "+std::to_string(line)+": "+message, line){}
    };

    class SubtitleEndBeforeStart : public SubShiftingError{
    public:
        SubtitleEndBeforeStart(std::string message, int line) : SubShiftingError("At line "+std::to_string(line)+": "+message, line){}
    };



}




#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
