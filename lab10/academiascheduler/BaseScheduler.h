//
// Created by matematyk60 on 22.05.17.
//

#ifndef JIMP_EXERCISES_BASESCHEDULER_H
#define JIMP_EXERCISES_BASESCHEDULER_H

#include <vector>
#include <map>
#include <set>

using ::std::vector;
using std::map;
using std::set;

namespace academia {
    class Scheduler {
        class Scheduler{
        public:
            Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)
        };
    };
}

#endif //JIMP_EXERCISES_BASESCHEDULER_H
