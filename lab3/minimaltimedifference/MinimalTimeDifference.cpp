//
// Created by hubert on 12.03.18.
//

#include "MinimalTimeDifference.h"



namespace minimaltimedifference {


    unsigned int ToMinutes(std::string time_HH_MM) {

        unsigned long size = time_HH_MM.length();
        std::string hours;
        std::string minutes;

        if (size == 5) {
            hours += time_HH_MM.at(0);
            hours += time_HH_MM.at(1);
            minutes += time_HH_MM.at(3);
            minutes += time_HH_MM.at(4);
        } else {
            hours += time_HH_MM.at(0);
            minutes += time_HH_MM.at(2);
            minutes += time_HH_MM.at(3);
        }

        std::stringstream stream1;
        std::stringstream stream2;
        unsigned int int_hours;
        unsigned int int_minutes;

        stream1.str(hours);
        stream1 >> int_hours;
        stream2.str(minutes);
        stream2 >> int_minutes;

        return 60 * int_hours + int_minutes;
    }


    unsigned int MinimalTimeDifference(std::vector<std::string> times) {

        std::vector<int> times_int;
        int i = 0;
        for (std::string k : times) {
            times_int.push_back(ToMinutes(k));
            i++;
        }

        std::sort(times_int.begin(), times_int.end());

        int tmp = -1441;
        unsigned int min_difference = 1441;
        for (int x : times_int) {
            if (abs(tmp - x) < min_difference) {
                min_difference =  abs(tmp - x);
            }
            tmp = x;
        }

        if (abs(1440+times_int.at(0) - tmp) < min_difference) {
            min_difference = abs(1440+times_int.at(0) - tmp);
        }

        return min_difference;
    }
}