//
// Created by matematyk60 on 22.05.17.
//

#include "SchedulingItem.h"

namespace academia{
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
        course_id_ = course_id;
        teacher_id_ = teacher_id;
        room_id_ = room_id;
        time_slot_ = time_slot;
        year_ = year;
    }

    int SchedulingItem::GetCourseId(void) {
        return course_id_;
    }

    int SchedulingItem::GetTeacherId(void) const {
        return teacher_id_;
    }

    int SchedulingItem::GetRoomId(void) const {
        return room_id_;
    }

    int SchedulingItem::GetTimeSlot(void) const {
        return time_slot_;
    }

    int SchedulingItem::GetYear(void) const {
        return year_;
    }
}