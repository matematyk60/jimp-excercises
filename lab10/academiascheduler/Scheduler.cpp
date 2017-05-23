//
// Created by matematyk60 on 22.05.17.
//

#include <algorithm>
#include "Scheduler.h"
#include "Algo.h"

using ::algo::FindYear;

namespace academia{
    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule answer;
        for(const auto &n : elements_){
            if(n.TeacherId() == teacher_id){
                answer.InsertScheduleItem(n);
            }
        }
        return answer;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule answer;
        for(const auto &n : elements_){
            if(n.RoomId() == room_id){
                answer.InsertScheduleItem(n);
            }
        }
        return answer;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule answer;
        for(const auto &n : elements_){
            if(n.Year() == year){
                answer.InsertScheduleItem(n);
            }
        }
        return answer;
    }

    std::vector<int> Schedule::PossibleTimeSlots(int n_time_slots) const {
        std::vector<int> answer;
        for (int i = 1; i < n_time_slots + 1; i++) {
            answer.emplace_back(i);
        }
        return answer;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> answer;
        std::vector<int> occupied;
        std::transform(elements_.begin(),elements_.end(), std::back_inserter(occupied), [](SchedulingItem p){return p.TimeSlot(); });
        for(int i = 1; i < n_time_slots+1; i++){
            if(std::find(occupied.begin(),occupied.end(),i) == occupied.end()){
                answer.emplace_back(i);
            }
        }
        return answer;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        elements_.emplace_back(item);
    }

    size_t Schedule::Size(void) const {
        return elements_.size();
    }

    SchedulingItem Schedule::operator[](int number) const {
        return elements_[number];
    }


    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule answer;
        int year;
        int room;
        int time_slot;
        pair<int, int> room_and_time_slot;
        for(const auto &n : teacher_courses_assignment){
           for(const auto &m : n.second){
               year = FindYear(courses_of_year, m);
               if(year == -1){
                   throw NoViableSolutionFound{"No compatible year for course"+std::to_string(m)+"\n"};
               } else {
                   if(n_time_slots*rooms.size() == answer.Size() ){
                       throw NoViableSolutionFound{"No available time slot"};
                   }else{
                       room = answer.GetRoomAndTimeSlot(rooms,n_time_slots,n.first,year).first;
                       time_slot = answer.GetRoomAndTimeSlot(rooms,n_time_slots,n.first,year).second;
                       answer.InsertScheduleItem(SchedulingItem(m,n.first,room,time_slot,year));
                   }
                   }
               }
           }
        return answer;
        }


    std::pair<int, int> Schedule::GetRoomAndTimeSlot(const std::vector<int> &rooms, int n_time_slots, int teacher_id, int year_id) const {
        std::vector<int> slots = this->PossibleTimeSlots(n_time_slots);
        for(auto &n : elements_){
            if(n.TeacherId() == teacher_id) {
                slots.erase(std::remove(slots.begin(), slots.end(), n.TimeSlot()),slots.end());
            }
        }
        std::pair<int,int> answer = GetRoomAfterGettingAvailableSlots(rooms,slots,year_id);
        if(answer.first == -1){
            throw NoViableSolutionFound{"error"};
        }
        return answer;

    }

    std::pair<int, int> Schedule::GetRoomAfterGettingAvailableSlots(const std::vector<int> &rooms, std::vector<int> avaliable_slots, int year_id) const {
        bool IsAvailable = true;
        for(const auto &n : rooms){
            for(const auto &m : avaliable_slots){
                for(const auto &o : elements_){
                    if((o.TimeSlot() == m && o.RoomId() == n) || (o.TimeSlot() == m && o.Year() == year_id)){
                        IsAvailable = false;
                        break;
                    }
                }
                if(IsAvailable){
                    return std::make_pair<int,int>(int(n),int(m));
                } else{
                    IsAvailable = true;
                }
            }
        }
        return std::make_pair<int,int>(-1,-1);
    }
}