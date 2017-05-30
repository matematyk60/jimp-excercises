//
// Created by janek on 22.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstddef>
#include <map>
#include <set>

using ::std::vector;
using ::std::map;
using ::std::runtime_error;
using ::std::set;

namespace academia {

    class SchedulingItem {
    public:
        SchedulingItem(int course, int teacher, int room, int time, int year);

        int CourseId() const { return course_id_; };

        int TeacherId() const { return teacher_id_; };

        int RoomId() const { return room_id_; };

        int TimeSlot() const { return time_slot_; };

        int Year() const { return year_; };

    //private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;

    };

    class Schedule {
    public:
        std::pair<int, int> GetRoomAfterGettingAvailableSlots(const vector<int> &rooms, vector<int> avaliable_slots, int year_id) const;

        std::pair<int,int> GetRoomAndTimeSlot(const vector<int> &rooms, int n_time_slots, int teacher_id, int year_id) const;

        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        vector<int> AvailableTimeSlots(int n_time_slots) const;

        vector<int> PossibleTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size(void) const;

        SchedulingItem operator[](int number) const;

    private:
        std::vector<SchedulingItem> schedule_;
    };


    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
        ~Scheduler(){};
    };


    class NoViableSolutionFound : public runtime_error {
    public:
        NoViableSolutionFound() : runtime_error("error") {}
        virtual ~NoViableSolutionFound(){};
    };


    class GreedyScheduler : public Scheduler {
    public:
        GreedyScheduler() {};

        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H