//
// Created by hubert on 09.05.18.
//

#include "Serialization.h"

using namespace academia;

// Serializer Room & Building
Serializer::Serializer(std::ostream* s) {
    out = move(std::unique_ptr<std::ostream>(s));
}
Serializer::~Serializer() {
    out.release();
}
Room::Room(int i, std::string s, Type t) {
    id = i;
    name = move(s);
    type = t;
}
void Room::Serialize(Serializer* s) const {
    s->Header("room");
    s->IntegerField("id", id);
    s->StringField("name", name);
    s->StringField("type", ToString(type));
    s->Footer("room");
}
std::string Room::ToString(const Type t) const {
    switch (t) {
        case Type::COMPUTER_LAB:
            return "COMPUTER_LAB";
        case Type::LECTURE_HALL:
            return "LECTURE_HALL";
        case Type::CLASSROOM:
            return "CLASSROOM";
    }
    return "";
}
Building::Building(int ID,std::string Name, std::initializer_list<Room> Rooms):id(ID),name(move(Name)){
    for(auto p : Rooms){
        rooms.emplace_back(p);
    }
}
void Building::Serialize(Serializer* temp)const{
    temp->Header("building");
    temp->IntegerField("id",id);
    temp->StringField("name",name);
    std::vector<std::reference_wrapper<const Serializable>> vector;
    for (const auto &room : rooms)
        vector.emplace_back(room);
    temp->ArrayField("rooms",vector);
    temp->Footer("building");
}
int Building::Id(){
    return id;
}


// Json
JsonSerializer::JsonSerializer(std::ostream* out):Serializer(out),is_first(true){}

void JsonSerializer::filling_out_field_name(const std::string &field_name) {
    if(!is_first)
        *out << ", ";
    *out << "\"" << field_name << "\": ";
    is_first = false;
}
void JsonSerializer::IntegerField(const std::string &field_name, int value){
    std::stringstream sstream;
    sstream<< value;
    filling_out_field_name(field_name);
    *out <<sstream.str();
}
void JsonSerializer::DoubleField(const std::string &field_name, double value){
    std::stringstream sstream;
    sstream << value;
    filling_out_field_name(field_name);
    *out<<sstream.str();
}
void JsonSerializer::StringField(const std::string &field_name, const std::string &value){
    filling_out_field_name(field_name);
    *out << "\""<<value<<"\"";
}
void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    filling_out_field_name(field_name);
    if(value)
        *out << "TRUE";
    else
        *out << "FALSE";
}
void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
    filling_out_field_name(field_name);
    is_first = true;
    value.Serialize(this);
}
void JsonSerializer::ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const Serializable>> &value) {
    if(!is_first)
        *out << ", ";
    *out<< "\""<< field_name << "\": [";
    bool temp=false;
    for(const Serializable& p: value){
        if(temp)
            *out << ", ";
        is_first = true;
        p.Serialize(this);
        temp=true;
    }
    *out <<"]";
}
void JsonSerializer::Header(const std::string &object_name) {
    *out<<"{";
}
void JsonSerializer::Footer(const std::string &object_name) {
    *out << "}";
}



// Xml
XmlSerializer::XmlSerializer(std::ostream* out):Serializer(out){}

void XmlSerializer::IntegerField(const std::string &field_name, int value){
    std::stringstream sstream;
    sstream<< value;
    *out<< "<"<<field_name<<">"<<sstream.str() << "<\\"<<field_name<<">";
}
void XmlSerializer::DoubleField(const std::string &field_name, double value){
    std::stringstream sstream;
    sstream<< value;
    *out<< "<"<<field_name<<">"<<sstream.str() << "<\\"<<field_name<<">";
}
void XmlSerializer::StringField(const std::string &field_name, const std::string &value){
    *out<< "<"<<field_name<<">"<<value << "<\\"<<field_name<<">";
}
void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    *out<< "<"<<field_name<<">";
    if(value)
        *out << "TRUE";
    else
        *out << "FALSE";
    *out << "<\\"<<field_name<<">";
}
void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}
void XmlSerializer::ArrayField(const std::string &field_name,
                               const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *out<< "<"<<field_name<<">";
    for(const Serializable& x: value){
        x.Serialize(this);
    }
    *out<< "<\\"<<field_name<<">";
}
void XmlSerializer::Header(const std::string &object_name) {
    *out<<"<"<<object_name<<">";
}
void XmlSerializer::Footer(const std::string &object_name) {
    *out<<"<\\"<<object_name<<">";
}


// Building Repository
BuildingRepository::BuildingRepository(std::initializer_list<Building> list) {
    for(auto x : list){
        List.emplace_back(x);
    }
}
void BuildingRepository::Add(Building temp) {
    List.emplace_back(temp);
}
void BuildingRepository::StoreAll(Serializer *serializer) const {
    serializer->Header("building_repository");
    std::vector<std::reference_wrapper<const Serializable>> vector;
    for(const auto &p : List) {
        vector.emplace_back(p);
    }
    serializer->ArrayField("buildings", vector);
    serializer->Footer("building_repository");
}
std::experimental::optional<Building> BuildingRepository::operator[](int a) const {
    for(auto x : this->List){
        if(x.Id() == a){
            return std::experimental::optional<Building>{x};
        }
    }
    return {};
}