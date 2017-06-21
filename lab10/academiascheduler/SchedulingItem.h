//
// Created by matematyk60 on 22.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULINGITEM_H
#define JIMP_EXERCISES_SCHEDULINGITEM_H


namespace academia{
    class SchedulingItem{
    public:
        SchedulingItem(int course_id = 0, int teacher_id = 0, int room_id = 0, int time_slot = 0, int year = 0);
        int CourseId(void)const;
        int TeacherId(void)const;
        int RoomId(void)const;
        int TimeSlot(void)const;
        int Year(void)const;
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };
}


#endif //JIMP_EXERCISES_SCHEDULINGITEM_H
