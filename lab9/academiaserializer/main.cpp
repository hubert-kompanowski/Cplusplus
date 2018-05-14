//
// Created by hubert on 09.05.18.
//

#include "Serialization.h"

using namespace academia;

int main(){

    std::stringstream out;
    XmlSerializer serializer{&out};


    std::stringstream out2;
    XmlSerializer serializer2{&out2};

    BuildingRepository repository{};
    Building b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
    Building b2{102, "B-2", {}};
    Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};

    repository.Add(b1);
    repository.Add(b2);
    repository.Add(c2);

    repository.StoreAll(&serializer2);
    std::cout << out2.str()<<std::endl;

}