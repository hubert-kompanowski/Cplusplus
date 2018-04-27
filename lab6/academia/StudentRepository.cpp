//
// Created by hubert on 11.04.18.
//



#include "StudentRepository.h"

namespace academia {
    StudentRepository::StudentRepository(std::initializer_list<Student> in) {
        studentcontainer_.assign(in);
    }


    void StudentRepository::AddStudent(Student &in) {
        studentcontainer_.push_back(in);
    }
    void StudentRepository::RemoveStudent(std::string outbyid) {
        bool flag = true;
        int i=0;
        while  ( i < studentcontainer_.size() && flag) {
            if (studentcontainer_[i].Id()==outbyid)
                flag=false;
            i++;
        }
        if (!flag)
            studentcontainer_.erase(studentcontainer_.begin()+i);
    }
    void StudentRepository::RemoveStudent(Student out) {
        std::string outbyid=out.Id();
        this->RemoveStudent(outbyid);
    }
    int StudentRepository::StudentCount() const{
        return studentcontainer_.size();
    }

    std::vector<Student> StudentRepository::FindByQuery(const std::unique_ptr<Query> &query){
        std::vector<Student> out;
        for (auto item : studentcontainer_) {
            if (query->Accept(item)) out.push_back(item);
        }
        return out;
    }

    std::vector<Student> StudentRepository::get() const {
        return studentcontainer_;
    }

    Student &StudentRepository::operator[]( const std::string &searchforid) {
        bool flag = true;
        int i=0;
        while  ( i < studentcontainer_.size() && flag) {
            if (studentcontainer_[i].Id()==searchforid) {
                flag = false;
                return studentcontainer_[i];
            }
            i++;
        }
        return studentcontainer_[i];
    }

    bool operator==(const StudentRepository &a, const StudentRepository &b) {
        if(a.StudentCount() != b.StudentCount())
            return false;
        bool flag;

        for (auto u: a.get())
        {
            flag = false;
            for(auto v: b.get())
            {
                if (u.Id() == v.Id())
                    flag = true;
            }
            if(!flag) return false;
        }
        return true;
    }

    std::ostream &operator<<(std::ostream &os, StudentRepository stdrep){
        for(int i=0; i<stdrep.StudentCount(); ++i) {
            os << stdrep;
            os << std::endl;
        }
    }

}