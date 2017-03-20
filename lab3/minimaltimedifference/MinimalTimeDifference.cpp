//
// Created by matematyk60 on 14.03.17.
//

#include "MinimalTimeDifference.h"
#include <iostream>

using std::regex;
using std::regex_match;

namespace minimaltimedifference{

    unsigned int ToMinutes(std::string time_HH_MM) {
        regex pattern {R"((\d{1,2}):(\d{2}))"};
        std::smatch matches;
        unsigned int minutes;
        unsigned int hours;

        if(std::regex_match(time_HH_MM,matches,pattern)){
            std::stringstream ss;
            ss << matches[1];
            ss >> hours;
            ss.str("");
            ss.clear();
            ss << matches[2];
            ss >> minutes;


            return (hours * 60 + minutes);
        }

        return 0;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        unsigned int answer = 24*60;

        for(int i = 0 ; i < times.size() ; i++){
            for(int j = 0 ; j < times.size() ; j++){
                if(i == j){
                    continue;
                }
                if(abs(ToMinutes(times[i]) - ToMinutes(times[j])) < answer){
                    answer = abs(ToMinutes(times[i]) - ToMinutes(times[j]));
                    if(answer > 12*60)
                        answer = 24*60 - answer;
                }
            }
        }
        return answer;

    }
}