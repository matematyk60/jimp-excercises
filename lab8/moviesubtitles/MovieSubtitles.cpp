//
// Created by janek on 08.05.17.
//

#include <sstream>
#include "MovieSubtitles.h"

namespace moviesubs {

    ostream *MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output) {
        if (fps <= 0) {
            throw std::invalid_argument("FPS must be larger than zero!");
        }
        int i = 2;
        ParseLine(delay, fps, input, output, 1);
        while (input->get() != -1) {
            *output << '\n';
            if (input->peek() == -1) {
                break;
            }
            ParseLine(delay, fps, input, output, i);
            i++;
        }
        return output;
    }

    ostream *MicroDvdSubtitles::ParseLine(int delay, int fps, istream *input, ostream *output, int line_number) {
        int frame, new_frame, frame2, new_frame2;
        std::string line = "";
        std::string optional = "";
        std::string text = "";
        std::string optional2 = "";
        frame = GetPosition(input);
        new_frame = frame + delay * fps / 1000;
        frame2 = GetPosition(input);
        new_frame2 = frame2 + delay * fps / 1000;
        if (input->peek() == '{') {
            optional = SkipToBracket(input);
        }
        while (input->peek() != '\n') {
            if (input->peek() == -1) {
                optional2 = "\n";
                break;
            }
            text += (char) input->get();
        }
        if (new_frame < 0 || new_frame2 < 0) {
            throw NegativeFrameAfterShift(
                    "{" + std::to_string(frame) + "}{" + std::to_string(frame2) + "}" + optional + text + optional2,
                    line_number);
        }
        if (new_frame2 < new_frame) {
            throw SubtitleEndBeforeStart(
                    "{" + std::to_string(frame) + "}{" + std::to_string(frame2) + "}" + optional + text + optional2,
                    line_number);
        }
        // else
        *output << ("{" + std::to_string(new_frame) + "}{" + std::to_string(new_frame2) + "}" + optional + text +
                    optional2);
        return output;
    }

    std::string MicroDvdSubtitles::SkipToBracket(istream *input) {
        std::string tmp = "";
        while (input->peek() != '}') {
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
        if (input->get() != '{') {
            throw InvalidSubtitleLineFormat();
        }
        if (input->peek() == '}') {
            throw InvalidSubtitleLineFormat();
        }
        while (input->peek() >= 48 && input->peek() <= 57) {
            tmp += input->get();
        }
        if (input->get() != '}') {
            throw InvalidSubtitleLineFormat();
        }
        ss << tmp;
        ss >> answer;
        return answer;
    }

    ostream *SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output) {
        if (fps <= 0) {
            throw std::invalid_argument("FPS must be larger than zero!");
        }
        int i = 2;
        ParseLine(delay, fps, input, output, 1);
        while (input->get() != -1) {
            *output << '\n';
            if (input->peek() == -1) {
                break;
            }
            ParseLine(delay, fps, input, output, i);
            i++;
        }
        return output;

    }

    ostream *SubRipSubtitles::ParseLine(int delay, int fps, istream *input, ostream *output, int line_number) {
        int frame1, new_frame1, frame2, new_frame2;
        std::string text, line;
        line = GetNumberOfLine(input);
        if (line != std::to_string(line_number)) {
            throw OutOfOrderFrames(line_number);
        }
        SkipNewLine(input);
        frame1 = GetMiliseconds(input);
        new_frame1 = frame1 + delay;
        IgnoreWhiteSpaces(input);
        SkipArrow(input);
        IgnoreWhiteSpaces(input);
        frame2 = GetMiliseconds(input);
        new_frame2 = frame2 + delay;
        SkipNewLine(input);
        text = GetText(input);
        SkipNewLine(input);
        while (input->peek() != '\n' && input->peek() != -1) {
            text += "\n";
            text += GetText(input);
            SkipNewLine(input);
        }

        if (new_frame1 < 0 || new_frame2 < 0) {
            throw NegativeFrameAfterShift(GetString2OfNumber(frame1 / 3600000) + ":" +
                                          GetString2OfNumber((frame1 - (frame1 / 3600000) * 3600000) / 60000)
                                          + ":" + GetString2OfNumber(
                    (frame1 - ((frame1 - (frame1 / 3600000) * 3600000) / 60000) * 60000) / 1000) + "," +
                                          GetString3OfNumber(frame1 % 1000) +
                                          " --> " + GetString2OfNumber(frame2 / 3600000) + ":" +
                                          GetString2OfNumber((frame2 - (frame2 / 3600000) * 3600000) / 60000)
                                          + ":" + GetString2OfNumber(
                    (frame2 - ((frame2 - (frame2 / 3600000) * 3600000) / 60000) * 60000) / 1000) + "," +
                                          GetString3OfNumber(frame2 % 1000), line_number);
        }

        if (new_frame1 >= new_frame2) {
            throw SubtitleEndBeforeStart(GetString2OfNumber(frame1 / 3600000) + ":" +
                                         GetString2OfNumber((frame1 - (frame1 / 3600000) * 3600000) / 60000)
                                         + ":" + GetString2OfNumber(
                    (frame1 - ((frame1 - (frame1 / 3600000) * 3600000) / 60000) * 60000) / 1000) + "," +
                                         GetString3OfNumber(frame1 % 1000) +
                                         " --> " + GetString2OfNumber(frame2 / 3600000) + ":" +
                                         GetString2OfNumber((frame2 - (frame2 / 3600000) * 3600000) / 60000)
                                         + ":" + GetString2OfNumber(
                    (frame2 - ((frame2 - (frame2 / 3600000) * 3600000) / 60000) * 60000) / 1000) + "," +
                                         GetString3OfNumber(frame2 % 1000), line_number);
        }


        *output << line + "\n" + GetString2OfNumber(new_frame1 / 3600000) + ":" +
                   GetString2OfNumber((new_frame1 - (new_frame1 / 3600000) * 3600000) / 60000)
                   + ":" + GetString2OfNumber(
                (new_frame1 - ((new_frame1 - (new_frame1 / 3600000) * 3600000) / 60000) * 60000) / 1000) + "," +
                   GetString3OfNumber(new_frame1 % 1000) +
                   " --> " + GetString2OfNumber(new_frame2 / 3600000) + ":" +
                   GetString2OfNumber((new_frame2 - (new_frame2 / 3600000) * 3600000) / 60000)
                   + ":" + GetString2OfNumber(
                (new_frame2 - ((new_frame2 - (new_frame2 / 3600000) * 3600000) / 60000) * 60000) / 1000) + "," +
                   GetString3OfNumber(new_frame2 % 1000) + "\n" + text + "\n";

    }

    std::string SubRipSubtitles::GetString2OfNumber(int number) {
        std::string answer = "";
        if (number < 10) {
            answer += "0";
        }
        answer += std::to_string(number);
        return answer;
    }

    std::string SubRipSubtitles::GetString3OfNumber(int number) {
        std::string answer = "";
        if (number < 10) {
            answer += "00";
        }
        if (number < 100) {
            answer += "0";
        }
        answer += std::to_string(number);
        return answer;
    }


    istream *SubRipSubtitles::IgnoreWhiteSpaces(istream *input) {
        while (input->peek() == ' ') {
            input->ignore();
        }
        return input;
    }

    std::string SubRipSubtitles::GetNumberOfLine(istream *input) {
        std::string answer = "";
        while (input->peek() >= 48 && input->peek() <= 57) {
            answer += input->get();
        }
        if (input->peek() != '\n') {
            throw InvalidSubtitleLineFormat();
        } else {
            return answer;
        }
    }

    istream *SubRipSubtitles::SkipNewLine(istream *input) {
        if (input->get() == '\n') {
            return input;
        } else {
            throw InvalidSubtitleLineFormat();
        }
    }

    istream *SubRipSubtitles::SkipArrow(istream *input) {
        std::string tmp = "";
        for (int i = 0; i < 3; i++) {
            tmp += input->get();
        }
        if (tmp == "-->") {
            return input;
        } else {
            throw InvalidSubtitleLineFormat();
        }
    }


    int SubRipSubtitles::GetDoubleNumber(istream *input) {
        int answer = 0;
        int c;
        c = input->get();
        if (c < 48 || c > 57) {
            throw InvalidSubtitleLineFormat();
        } else {
            answer += (c - 48) * 10;
        }
        c = input->get();
        if (c < 48 || c > 57) {
            throw InvalidSubtitleLineFormat();
        } else {
            answer += (c - 48);
        }
        return answer;
    }

    int SubRipSubtitles::GetTripleNumber(istream *input) {
        int answer = 0;
        int c;
        c = input->get();
        if (c < 48 || c > 57) {
            throw InvalidSubtitleLineFormat();
        } else {
            answer += (c - 48) * 100;
        }
        c = input->get();
        if (c < 48 || c > 57) {
            throw InvalidSubtitleLineFormat();
        } else {
            answer += (c - 48) * 10;
        }
        c = input->get();
        if (c < 48 || c > 57) {
            throw InvalidSubtitleLineFormat();
        } else {
            answer += (c - 48);
        }
        return answer;
    }

    istream *SubRipSubtitles::SkipColon(istream *input) {
        if (input->get() != ':') {
            throw InvalidSubtitleLineFormat();
        } else {
            return input;
        }
    }

    istream *SubRipSubtitles::SkipComma(istream *input) {
        if (input->get() != ',') {
            throw InvalidSubtitleLineFormat();
        } else {
            return input;
        }
    }

    int SubRipSubtitles::GetMiliseconds(istream *input) {
        int miliseconds = 0;
        std::stringstream ss;
        std::string tmp;
        miliseconds += GetDoubleNumber(input) * 3600000;
        SkipColon(input);
        miliseconds += GetDoubleNumber(input) * 60000;
        SkipColon(input);
        miliseconds += GetDoubleNumber(input) * 1000;
        SkipComma(input);
        miliseconds += GetTripleNumber(input);
        return miliseconds;
    }

    std::string SubRipSubtitles::GetText(istream *input) {
        std::string answer = "";
        while (input->peek() != '\n') {
            answer += input->get();
        }
        return answer;
    }
}
