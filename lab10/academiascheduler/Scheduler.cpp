//
// Created by janek on 22.05.17.
//

#include "Scheduler.h"
#include "Algo.h"

using ::algo::FindYear;

namespace academia {

    SchedulingItem::SchedulingItem(int course, int teacher, int room, int time, int year) {
        course_id_ = course;
        teacher_id_ = teacher;
        room_id_ = room;
        time_slot_ = time;
        year_ = year;
    }


    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule tmp;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(tmp.schedule_),
                     [teacher_id](const SchedulingItem &compare) {
                         return (compare.TeacherId() == teacher_id);
                     });
        return tmp;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule tmp;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(tmp.schedule_),
                     [room_id](const SchedulingItem &compare) {
                         return (compare.RoomId() == room_id);
                     });
        return tmp;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule tmp;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(tmp.schedule_),
                     [year](const SchedulingItem &compare) {
                         return (compare.Year() == year);
                     });
        return tmp;
    }

    vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> free;
        for (int i = 1; i < n_time_slots + 1; ++i) {
            if (!std::any_of(schedule_.begin(), schedule_.end(), [i](const SchedulingItem in_iter) {
                return (i == in_iter.TimeSlot());
            })) {
                free.emplace_back(i);
            }
        }
        return free;
    }

    std::vector<int> Schedule::PossibleTimeSlots(int n_time_slots) const {
        std::vector<int> answer;
        for (int i = 1; i < n_time_slots + 1; i++) {
            answer.emplace_back(i);
        }
        return answer;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedule_.emplace_back(item);
    }

    size_t Schedule::Size() const {
        return schedule_.size();
    }

    SchedulingItem Schedule::operator[](const int index) const {
        return this->schedule_[index];
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule answer;
        int year;
        int room;
        int time_slot;
        std::pair<int, int> room_and_time_slot;
        for (const auto &n : teacher_courses_assignment) {
            for (const auto &m : n.second) {
                year = FindYear(courses_of_year, m);
                if (year == -1) {
                    throw NoViableSolutionFound{};
                } else {
                    if (n_time_slots * rooms.size() == answer.Size()) {
                        throw NoViableSolutionFound{};
                    } else {
                        room = answer.GetRoomAndTimeSlot(rooms, n_time_slots, n.first, year).first;
                        time_slot = answer.GetRoomAndTimeSlot(rooms, n_time_slots, n.first, year).second;
                        answer.InsertScheduleItem(SchedulingItem(m, n.first, room, time_slot, year));
                    }
                }
            }
        }
        return answer;
    }


    std::pair<int, int>
    Schedule::GetRoomAndTimeSlot(const std::vector<int> &rooms, int n_time_slots, int teacher_id, int year_id) const {
        std::vector<int> slots = this->PossibleTimeSlots(n_time_slots);
        for (auto &n : schedule_) {
            if (n.TeacherId() == teacher_id) {
                slots.erase(std::remove(slots.begin(), slots.end(), n.TimeSlot()), slots.end());
            }
        }
        std::pair<int, int> answer = GetRoomAfterGettingAvailableSlots(rooms, slots, year_id);
        if (answer.first == -1) {
            throw NoViableSolutionFound();
        }
        return answer;

    }

    std::pair<int, int>
    Schedule::GetRoomAfterGettingAvailableSlots(const std::vector<int> &rooms, std::vector<int> avaliable_slots,
                                                int year_id) const {
        bool IsAvailable = true;
        for (const auto &n : rooms) {
            for (const auto &m : avaliable_slots) {
                for (const auto &o : schedule_) {
                    if ((o.TimeSlot() == m && o.RoomId() == n) || (o.TimeSlot() == m && o.Year() == year_id)) {
                        IsAvailable = false;
                        break;
                    }
                }
                if (IsAvailable) {
                    return std::make_pair<int, int>(int(n), int(m));
                } else {
                    IsAvailable = true;
                }
            }
        }
        return std::make_pair<int, int>(-1, -1);
    }
}