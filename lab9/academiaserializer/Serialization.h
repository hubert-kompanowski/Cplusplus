//
// Created by hubert on 09.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <experimental/optional>

namespace academia {

    class Serializable;

    class Serializer{
    public:
         Serializer(std::ostream*);
        ~Serializer();
        virtual void IntegerField(const std::string& field_name,int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
    protected:
        std::unique_ptr<std::ostream> out;
    };


    class Serializable{
    public:
        virtual void Serialize(Serializer*)const=0;
    };


    class Room : public Serializable{
    public:
        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int, std::string, Type);
        std::string ToString(const Type)const;
        void Serialize(Serializer*)const override;
    private:
        int id;
        std::string name;
        Type type;
    };


    class Building : public Serializable{
    public:
        Building(int ID, std::string Name, std::initializer_list<Room> Rooms);
        int Id();
        void Serialize(Serializer*)const override;
    private:
        int id;
        std::string name;
        std::vector<Room> rooms;
    };


    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(std::ostream* out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    private:
        bool is_first;

        void filling_out_field_name(const std::string &field_name);
    };


    class XmlSerializer : public Serializer{
    public:
        XmlSerializer(std::ostream* out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };


    class BuildingRepository {
    public:
        BuildingRepository(std::initializer_list<Building> list);
        void Add(Building temp);
        void StoreAll(Serializer*)const;
        std::experimental::optional<Building> operator[](int a)const;
    private:
        std::vector<Building> List;
    };


}
#endif //JIMP_EXERCISES_SERIALIZATION_H

