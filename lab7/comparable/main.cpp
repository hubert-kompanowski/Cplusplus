//
// Created by hubert on 15.04.18.
//


#include <iostream>
#include <algorithm>
#include <Comparable.h>
#include <StudentRepository.h>
#include <vector>


using namespace academia;
using namespace std;

int main() {
    ByFirstNameAscending cmp;
    vector<Student>  test_students {
            Student {"1","Marek","Aureliusz","filozofia",StudyYear {3}},
            Student {"2","Albert","Einstein","muzyka",StudyYear{1}},
            Student {"3","Niels","Bohr","fizyka",StudyYear{1}},
            Student {"4","Ada","Lovelace","informatyka",StudyYear {4}},
            Student {"5", "Maria","Gopert-Mayer","fizyka",StudyYear {3}}};

    sort (test_students.begin(), test_students.end(), cmp);
    for (auto &&  item: test_students ) {
        cout<<item.Id()<<endl;
    }

    return 0;
}