//
// Created by hubert on 16.05.18.
//

#include "Scheduler.h"

using namespace academia;

SchedulingItem::SchedulingItem(int c, int te, int r, int ti, int y) {
    course_id = c;
    teacher_id = te;
    room_id = r;
    time_slot = ti;
    year = y;
}

void Schedule::InsertScheduleItem(SchedulingItem item) {
    schedule_list.emplace_back(item);
}
int SchedulingItem::TeacherId() const{
    return teacher_id;
}
int SchedulingItem::CourseId() const {
    return course_id;
}
int SchedulingItem::RoomId() const {
    return room_id;
}
int SchedulingItem::TimeSlot() const {
    return time_slot;
}
int SchedulingItem::Year() const {
    return year;
}

Schedule Schedule::OfTeacher(int t) const{
    Schedule result;
    for(auto p : schedule_list){
        if(p.TeacherId() == t)
            result.InsertScheduleItem(p);
    }
    return result;
}

Schedule Schedule::OfRoom(int r) const {
    Schedule result;
    for(auto p : schedule_list){
        if(p.RoomId() == r)
            result.InsertScheduleItem(p);
    }
    return result;
}

Schedule Schedule::OfYear(int y) const {
    Schedule result;
    for(auto p : schedule_list){
        if(p.Year() == y)
            result.InsertScheduleItem(p);
    }
    return result;
}

std::vector<int> Schedule::AvailableTimeSlots(int s) {
    std::vector<int> result, temp;
    for(auto p : schedule_list){
        temp.push_back(p.TimeSlot());
    }
    std::unique(temp.begin(), temp.end());
    std::sort(temp.begin(), temp.end());
    temp.push_back(0);
    unsigned long k = 0;
    int i = 1;

    while(i<=s){
        if(temp.at(k)==i){
            k++; i++;
        } else {
            result.push_back(i);
            i++;
        }
    }
    return result;
}

unsigned long Schedule::Size() const{
    return schedule_list.size();
}

SchedulingItem Schedule::operator[](int i) const{
    return schedule_list[i];
}

Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                             const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                             const std::map<int, std::set<int>> &courses_of_year,
                                             int n_time_slots) {

    int teacher, course, room, time_slot, year=0;
    Schedule new_schedule;

    int room_iterator = 0;
    int time_slots_iterator = 1;
    int counter = 0;
    int prev_course_=0;
    int prev_room=0;

    for(auto p : teacher_courses_assignment) {
        teacher = p.first;
        for(auto q : p.second) {
            course = q;
            for(auto r : courses_of_year) {
                for(auto s : r.second) {
                    if(s == course)
                        year = r.first;
                }
            }

            room = rooms[room_iterator];
            time_slot = time_slots_iterator;

            if(time_slots_iterator >= n_time_slots) {
                time_slots_iterator = 0;
                room_iterator++;
            }
            time_slots_iterator++;
            
            new_schedule.InsertScheduleItem({course, teacher, room, time_slot, year});

            if(room != prev_room && prev_course_ == course)
                throw NoViableSolutionFound();

            prev_course_ = course;
            prev_room = room;

        }

    }

    for(auto p : teacher_courses_assignment) {
        counter += p.second.size();
    }

    if(rooms.size()*n_time_slots < counter)
        throw NoViableSolutionFound();

    return new_schedule;
}