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

    int SchedulingItem::CourseId(void) const {
        return course_id_;
    }

    int SchedulingItem::TeacherId(void) const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId(void) const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot(void) const {
        return time_slot_;
    }

    int SchedulingItem::Year(void) const {
        return year_;
    }
}