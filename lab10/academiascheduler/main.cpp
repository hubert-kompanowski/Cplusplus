//
// Created by hubert on 16.05.18.
//

#include <iostream>
#include "Scheduler.h"
using namespace academia;

int main(){
    Schedule schedule;
    schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
    schedule.InsertScheduleItem(SchedulingItem {5, 33, 7, 5, 2});
    schedule.InsertScheduleItem(SchedulingItem {10, 1, 12, 8, 1});
    schedule.InsertScheduleItem(SchedulingItem {15, 4, 7, 8, 2});
    schedule.InsertScheduleItem(SchedulingItem {35, 35, 37, 9, 1});

    std::vector<int> availability = schedule.AvailableTimeSlots(10);
    std::sort(availability.begin(), availability.end());
    const std::vector<int> expected{1, 2, 4, 6, 7, 10};

    for(auto p: availability){
        std::cout<< p << " ";
    }

}