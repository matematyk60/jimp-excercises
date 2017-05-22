//
// Created by matematyk60 on 22.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H


#include <vector>
#include <cstddef>
#include "SchedulingItem.h"

namespace academia{
    class Schedule{
    public:
        Schedule OfTeacher(int teacher_id)const;
        Schedule OfRoom(int room_id)const;
        Schedule OfYear(int year)const;
        std::vector<int> AvailableTimeSlots(int n_time_slots)const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size(void)const;
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
