//
// Created by hubert on 16.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <initializer_list>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

namespace academia {

    class SchedulingItem{
    public:
        SchedulingItem(int, int, int, int, int);
        int TeacherId()const;
        int CourseId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };


    class Schedule {
    public:
        void InsertScheduleItem(SchedulingItem item);
        Schedule OfTeacher(int) const;
        Schedule OfRoom(int) const;
        Schedule OfYear(int) const;
        std::vector<int> AvailableTimeSlots(int);

        unsigned long Size() const;
        SchedulingItem operator[](int) const;
    private:
        std::vector<SchedulingItem> schedule_list;
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) = 0;

    private:
        std::vector<int> rooms;
        std::map<int, std::vector<int>> teacher_courses_assignment;
        std::map<int, std::set<int>> courses_of_year;
        int n_time_slots;
    };

    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots);
        GreedyScheduler()= default;

    private:
    };

    class NoViableSolutionFound : public std::runtime_error{
    public:
        NoViableSolutionFound(std::string error = "ERROR") : runtime_error(error) {};

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
