//
// Created by hubert on 15.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H



#include <StudentRepository.h>


namespace academia {


    class ByFirstName : public Query{
    public:
        ByFirstName(std::string firstname):firstname_(firstname) {}
        ~ByFirstName();
        bool Accept(const Student &student) const override;
    private:
        std::string firstname_;
    };

    class ByLastName : public Query{
    public:
        ByLastName(std::string lastname):lastname_(lastname) {}
        bool Accept(const Student &student) const override;
    private:
        std::string lastname_;
    };

    class ByOneOfPrograms : public Query{
    public:
        ByOneOfPrograms(std::vector<std::string> program):program_(program) {}
        bool Accept(const Student &student) const override;
    private:
        std::vector<std::string> program_;
    };

    class ByYearLowerOrEqualTo : public Query{
    public:
        ByYearLowerOrEqualTo(StudyYear year):year_(year) {}
        bool Accept(const Student &student) const override;
    private:
        StudyYear year_;
    };

    class OrQuery : public Query{
    public:
        OrQuery(std::unique_ptr<Query> a, std::unique_ptr<Query> b): a_(std::move(a)),b_(std::move(b)) {}
        bool Accept(const Student &student) const override;
    private:
        const std::unique_ptr<Query> a_, b_;
    };

    class AndQuery : public Query{
    public:
        AndQuery(std::unique_ptr<Query> a, std::unique_ptr<Query> b): a_(std::move(a)),b_(std::move(b)) {}
        bool Accept(const Student &student) const override;
    private:
        const std::unique_ptr<Query> a_, b_;
    };

}

#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
