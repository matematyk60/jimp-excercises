//
// Created by matematyk60 on 22.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H


#include <vector>
#include <cstddef>
#include "SchedulingItem.h"
#include <map>
#include <set>

namespace academia {
    class Schedule {
    public:
        std::pair<int, int> GetRoomAfterGettingAvailableSlots(const std::vector<int> &rooms, std::vector<int> avaliable_slots, int year_id) const;

        std::pair<int,int> GetRoomAndTimeSlot(const std::vector<int> &rooms, int n_time_slots, int teacher_id, int year_id) const;

        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        std::vector<int> PossibleTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size(void) const;

        SchedulingItem operator[](int number) const;

    private:
        std::vector<SchedulingItem> elements_;
    };

    class Scheduler {
    public:
        ~Scheduler(){};
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
    };

    class NoViableSolutionFound : public std::runtime_error {
    public:
        NoViableSolutionFound(std::string error = "ERROR") : runtime_error(error) {};
    };
    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
